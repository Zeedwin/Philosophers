/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:01:36 by jgirard-          #+#    #+#             */
/*   Updated: 2022/11/23 19:05:58 by jgirard-         ###   ########.fr       */
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
# include "./libft/libft.h"

typedef struct philosophers
{
	pthread_mutex_t	*fork[200];
	pthread_t		*philo[200];
	int				nphilo;
	int				phindex;
}					t_phil;

typedef struct times
{
	int	tto_die;
	int	tto_eat;
	int	tto_sleep;
	int	num_eat;
}			t_times;

typedef struct s_structs
{
	t_times			time;
	t_phil			phil;
	pthread_mutex_t	print;
}				t_struct;

#endif
