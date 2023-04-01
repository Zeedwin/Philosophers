/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 05:53:10 by jgirard-          #+#    #+#             */
/*   Updated: 2023/04/01 18:18:18 by jgirard-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_var
{
	int				number_of_philosophers;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	unsigned long	time_zero;
	int				must_eat;
	pthread_mutex_t	print;
	pthread_mutex_t	m_dead;
	int				everyone_ate;
	pthread_mutex_t	m_everyone_ate;
	int				dead;
	pthread_mutex_t	*fork;
}				t_var;

typedef struct s_philo
{
	int				id;
	int				nb_meal;
	unsigned long	last_meal;
	pthread_mutex_t	m_last_meal;
	t_var			*var;
}				t_philo;

int				ft_atoi(const char *str);
int				ft_isdigit(int c);
int				check_arg(int argc, char **argv);
int				digit_check(char *str);

int				ft_usleep(useconds_t usec, t_philo *philo);
unsigned long	time_ms(void);
void			print(char *str, unsigned long time, int id, t_philo *philo);
int				death_stop(t_philo *philo);

void			*philo_checker(void *ph);
int				check_everyone_ate(t_philo *philo);
int				check_diff_die(t_philo *philo);
void			eats(t_philo *ph, int next_id, int id);
void			min_eats(t_philo *ph);
void			last_meal(t_philo	*ph);
void			ft_putendl_fd(char *s, int fd);
void			error(char *c);
#endif