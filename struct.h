/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:01:36 by jgirard-          #+#    #+#             */
/*   Updated: 2022/11/23 13:52:05 by jgirard-         ###   ########.fr       */
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
	pthread_mutex_t	*fork;
	pthread_t		*philo;
	int				nphilo;
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
