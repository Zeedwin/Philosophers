/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:36:46 by jgirard-          #+#    #+#             */
/*   Updated: 2022/11/23 14:43:50 by jgirard-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "struct.h"

void	error(char *c)
{
	ft_putendl_fd(c, 1);
	exit(1);
}

int	main(int ac, char **av)
{
	t_struct	s;
	int			phn;
	int			i;

	if (ac < 5 || ac > 6)
	{
		error("\033[32;1mUsage:\033[0m./philosophers "
			"\033[92;1mN_OF_PHILO T_TO_EAT "
			"T_TO_DIE T_TO_SLEEP \033[93;1mN_OF_T_PHILO_EAT");
	}
	s.phil.nphilo = ft_atoi(av[1]);
	s.time.tto_die = ft_atoi(av[2]);
	s.time.tto_eat = ft_atoi(av[3]);
	s.time.tto_sleep = ft_atoi(av[4]);
	if (ac > 5)
	s.time.num_eat = ft_atoi(av[5]);
	else
		s.time.num_eat = 0;
	printf("Number of philosophers: %d\n", s.phil.nphilo);
	printf("Time to die: %d\n", s.time.tto_die);
	printf("Time to eat: %d\n", s.time.tto_eat);
	printf("Time to sleep: %d\n", s.time.tto_sleep);
	printf("Number of times each philosopher must eat: %d\n", s.time.num_eat);
	return (0);
}
