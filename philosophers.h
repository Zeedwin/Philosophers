/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:33:54 by jgirard-          #+#    #+#             */
/*   Updated: 2022/11/16 12:55:12 by jgirard-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <pthread.h>

typedef struct philosophers
{
	pthread_mutex_t	fork;
	pthread_t		philo[]
}					p_phil;


#endif
