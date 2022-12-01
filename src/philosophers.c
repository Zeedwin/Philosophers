/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:36:46 by jgirard-          #+#    #+#             */
/*   Updated: 2022/12/01 18:59:28 by jgirard-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../includes/struct.h"
#include	<sys/time.h>

void	error(char *c)
{
	ft_putendl_fd(c, 1);
	exit(1);
}

void	badargs()
{
	error("\033[91;1mError: Bad Params\n""\033[95;1mUsage:\033[0m./philosophers "
	"\033[92;1mNUMBER_OF_PHILOS TIME_TO_EAT "
	"TIME_TO_DIE TIME_TO_SLEEP \033[93;1mNUMBER_OF_TIMES_PHILOS_EAT");
}

int	initphvars(int ac, char **av, t_struct *s)
{
	if (ft_atoi(av[1]) >= 200)
	{
		error("\033[91;1m Exeeded maximum number of philosophers");
	}
	s->phil.philo = malloc(ft_atoi(av[1]) * sizeof(pthread_t));
	s->phil.fork_mutex = malloc(ft_atoi(av[1]) * sizeof(pthread_mutex_t));
	s->phil.fork = malloc(ft_atoi(av[1]) * sizeof(int));
	s->phil.nphilo = ft_atoi(av[1]);
	s->time.tto_die = ft_atoi(av[2]);
	s->time.tto_eat = ft_atoi(av[3]);
	s->time.tto_sleep = ft_atoi(av[4]);
	s->phil.phindex = 0;
	if (ac > 5)
	s->time.num_eat = ft_atoi(av[5]);
	else
		s->time.num_eat = 0;
	
	s->time.start_time = philo_get_time();
		for (int i = 0; i < s->phil.nphilo; i++)
	{
		if (pthread_mutex_init(&s->phil.fork_mutex[i], NULL) != 0)
			return	(-1);
		s->phil.fork[i] = 0;
	}
	/*printf("Number of philosophers: %d\n", s->phil.nphilo);
	printf("Time to die: %d\n", s->time.tto_die);
	printf("Time to eat: %d\n", s->time.tto_eat);
	printf("Time to sleep: %d\n", s->time.tto_sleep);
	printf("Number of times each philosopher must eat: %d\n", s->time.num_eat);*/
	return (0);
}

void	*philosopher(void *arg)
{
	//printf("philosophy time!\n");
	//int			i;
	t_struct	*s;

	s = (t_struct *)arg;
	int index = s->phil.phindex;
	//i = 0;
	//printf("entering philosopher thread\n");
	//printf("%d", s->phil.nphilo);
	while (1)
	{
		//printf("loop\n");
		eats(s, index);
		//LOCK PRINTF
		// printf SLEEP
		// deLOCK PRINTF
		// ftUSLEEP timetosleep
		// LOCK PRINTF
		// printf THINK
		// delock PRINTF
		//usleep timethink
		
		//printf("%d has taken a fork\n", index + 1);
		//printf("%u ", philo_get_time() - s->time.start_time);
		//s->phil.phindex++;
		//ft_usleep(5000);
	}
	return	(NULL);
}

// 4
// 
// 0 1 2 3
// index = 2
// 2
// 2 - 1 = 1
/*
void print_msg(char *msg, mutx) {
	pthread_mutex_lock(&s->print);
	printf("%s", index);
	pthread_mutex_unlock(&s->print);
}*/

void death_check()
{
	pthread_
}

void eats(t_struct *s, int index) 
{	
	pthread_mutex_lock(&s->phil.fork_mutex[index]);
	if (s->phil.fork[index] == 0)
		s->phil.fork[index] = 1;
	// lasteat - actuel >= time_toe_die
	//     dea = 1 
	//lock
	pthread_mutex_lock(&s->print);
	printf("%d has taken a fork\n", index);
	pthread_mutex_unlock(&s->print);
	//delock
	if (index == 0) {
		pthread_mutex_lock(&s->phil.fork_mutex[s->phil.nphilo-1]);
		if (s->phil.fork[s->phil.nphilo-1] == 0)
			s->phil.fork[s->phil.nphilo-1] = 1;
	} else {
		pthread_mutex_lock(&s->phil.fork_mutex[index-1]);
		if (s->phil.fork[index-1] == 0)
			s->phil.fork[index-1] = 1;
	}
	// lock
	pthread_mutex_lock(&s->print);
	printf("%d has taken a fork\n", index);
	printf("%d is eating\n", index);
	pthread_mutex_unlock(&s->print);
	// delock
	//phil->timelasteat = time actuel
	ft_usleep(s->time.tto_eat);
	s->phil.fork[index] = 0;
	pthread_mutex_unlock(&s->phil.fork_mutex[index]);
	if (index == 0)
	{
		s->phil.fork[s->phil.nphilo-1] = 0;
		pthread_mutex_unlock(&s->phil.fork_mutex[s->phil.nphilo-1]);
	}
	else
		s->phil.fork[index-1] = 0;
		pthread_mutex_unlock(&s->phil.fork_mutex[index-1]);
}

int	main(int ac, char **av)
{
	t_struct	s;
	//int			*res;
	if (ac < 5 || ac > 6)
	{
		badargs();
	}
	initphvars(ac, av, &s);
	printf("entering main\n");
	
	if (pthread_create())
	{
		/* code */
	}
	
	for (int i = 0; i < s.phil.nphilo; i++)
	{
		s.phil.phindex = i;
		if (pthread_create(&s.phil.philo[i], NULL, philosopher, &s) != 0)
			return	(1);
		usleep(100);
	}
	printf("thread created\n");
	//philosopher(s);
	for (int i = 0; i < s.phil.nphilo; i++)
	{
		if (pthread_join((s.phil.philo[i]), NULL) != 0)
			return (2);
	}
	
	//printf("thread joined\n");
	return (0);
}
