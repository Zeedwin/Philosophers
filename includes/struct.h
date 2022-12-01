/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:01:36 by jgirard-          #+#    #+#             */
/*   Updated: 2022/12/01 18:48:06 by jgirard-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct philosophers
{
	pthread_mutex_t	*fork_mutex;
	int				*fork;
	pthread_t		*philo;
	int				nphilo;
	int				phindex;
}					t_phil;

typedef struct times
{
	int	tto_die;
	int	tto_eat;
	int	tto_sleep;
	int	num_eat;
	unsigned int start_time;
}			t_times;

typedef struct s_structs
{
	t_times			time;
	t_phil			phil;
	pthread_mutex_t	print;
}				t_struct;

int	ft_usleep(useconds_t usec);
useconds_t	philo_get_time(void);
void eats(t_struct *s, int index);

#endif
