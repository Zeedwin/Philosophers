/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:36:46 by jgirard-          #+#    #+#             */
/*   Updated: 2022/11/27 17:21:45 by jgirard-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../includes/struct.h"

void	error(char *c)
{
	ft_putendl_fd(c, 1);
	exit(1);
}

void	initphvars(int ac, char **av, t_struct *s)
{
	if (ft_atoi(av[1]) >= 200)
	{
		error("\033[91;1m Exeeded maximum number of philosophers");
	}
	if (ac < 5 || ac > 6)
	{
		error("\033[91;1mError: Bad Params\n""\033[95;1mUsage:\033[0m./philosophers "
			"\033[92;1mNUMBER_OF_PHILOS TIME_TO_EAT "
			"TIME_TO_DIE TIME_TO_SLEEP \033[93;1mNUMBER_OF_TIMES_PHILOS_EAT");
	}
	else
		s->phil.philo = malloc(sizeof(ft_atoi(av[1])));
		s->phil.fork = malloc(sizeof(ft_atoi(av[1])));
	s->phil.nphilo = ft_atoi(av[1]);
	s->time.tto_die = ft_atoi(av[2]);
	s->time.tto_eat = ft_atoi(av[3]);
	s->time.tto_sleep = ft_atoi(av[4]);
	s->phil.phindex = 0;
	if (ac > 5)
	s->time.num_eat = ft_atoi(av[5]);
	else
		s->time.num_eat = 0;
	printf("Number of philosophers: %d\n", s->phil.nphilo);
	printf("Time to die: %d\n", s->time.tto_die);
	printf("Time to eat: %d\n", s->time.tto_eat);
	printf("Time to sleep: %d\n", s->time.tto_sleep);
	printf("Number of times each philosopher must eat: %d\n", s->time.num_eat);
}	

void	*philosopher(void *arg)
{
	//printf("philosophy time!\n");
	//int			i;
	t_struct	*s;

	s = (t_struct *)arg;
	
	//i = 0;
	//printf("entering philosopher thread\n");
	//printf("%d", s->phil.nphilo);
	while (s->phil.phindex < s->phil.nphilo)
	{
		//printf("loop\n");
		printf("%d has taken a fork\n", s->phil.phindex);
		s->phil.phindex++;
	}
	return	(NULL);
}

int	main(int ac, char **av)
{
	t_struct	s;
	//int			*res;
	//printf("entering main\n");
	initphvars(ac, av, &s);
	for (int i = 0; i < 10; i++)
	{
		if (pthread_create(s.phil.philo, NULL, philosopher, &s) != 0)
			return	(1);
	}
	
	//printf("thread created\n");
	//philosopher(s);
	if (pthread_join(*(s.phil.philo), NULL) != 0)
		return (2);
	//printf("thread joined\n");
	return (0);
}
