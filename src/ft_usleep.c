/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:48:10 by jgirard-          #+#    #+#             */
/*   Updated: 2022/12/01 17:51:15 by jgirard-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/struct.h"
#include	<sys/time.h>

useconds_t	philo_get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

int	ft_usleep(useconds_t usec)
{
	useconds_t		start;
	useconds_t		after;

	start = philo_get_time();
	after = start;
	while (after - start < usec)
	{
		usleep(1);
		after = philo_get_time();
	}
	return (0);
}
