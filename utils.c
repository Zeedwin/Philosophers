/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 05:53:20 by jgirard-          #+#    #+#             */
/*   Updated: 2023/04/01 18:16:39 by jgirard-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long int	time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (((tv.tv_sec * 1000) + (tv.tv_usec / 1000)));
}

int	death_stop(t_philo *philo)
{
	pthread_mutex_lock(&philo->var->print);
	if (philo->var->dead == 1)
	{
		pthread_mutex_unlock(&philo->var->print);
		return (1);
	}
	else
		pthread_mutex_unlock(&philo->var->print);
	return (0);
}

int	ft_usleep(useconds_t usec, t_philo *philo)
{
	useconds_t	start;
	useconds_t	after;

	start = time_ms();
	after = start;
	while (after - start < usec)
	{
		if (death_stop(philo))
			break ;
		usleep(50);
		after = time_ms();
	}
	return (0);
}

void	print(char *str, unsigned long time, int id, t_philo *philo)
{
	pthread_mutex_lock(&philo->var->print);
	if (philo->var->dead != 1)
	{
		printf("%lu %d %s", time, id, str);
		pthread_mutex_unlock(&philo->var->print);
	}
}

void	error(char *c)
{
	ft_putendl_fd(c, 1);
	exit(1);
}
