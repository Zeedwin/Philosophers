/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:36:46 by jgirard-          #+#    #+#             */
/*   Updated: 2022/11/23 19:06:56 by jgirard-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "struct.h"

void	error(char *c)
{
	ft_putendl_fd(c, 1);
	exit(1);
}

void	initphvars(int ac, char **av, t_struct *s)
{
	if (ac < 5 || ac > 6)
	{
		error("\033[91;1mError: Bad Params\n""\033[95;1mUsage:\033[0m./philosophers "
			"\033[92;1mNUM_OF_PHILO TIME_TO_EAT "
			"TIME_TO_DIE TIME_TO_SLEEP \033[93;1mNUM_OF_TIMES_PHILOS_EAT");
	}
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
	//printf("Time to die: %d\n", s->time.tto_die);
	//printf("Time to eat: %d\n", s->time.tto_eat);
	//printf("Time to sleep: %d\n", s->time.tto_sleep);
	//printf("Number of times each philosopher must eat: %d\n", s->time.num_eat);
}	

void	*philosopher(t_struct s)
{
	//int			i;

	//i = 0;
	//printf("%d", s.phil.nphilo);
	while (s.phil.phindex < s.phil.nphilo)
	{
		printf("%d has taken a fork\n", s.phil.phindex);
		s.phil.phindex++;
	}
	exit (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_struct	s;
	pthread_t	ph;
	int			*res;

	initphvars(ac, av, &s);
	if (pthread_create(&ph, NULL, philosopher(s), NULL) != 0)
		return	(1);
	if (pthread_join(ph, (void**) &res) != 0)
		return (2);
	return (0);
}
