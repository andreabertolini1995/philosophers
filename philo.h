/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abertoli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:33:54 by abertoli          #+#    #+#             */
/*   Updated: 2022/10/21 18:29:38 by abertoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>

typedef struct s_philo
{
	int					number;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	long int			start_time;
	long int			time_last_meal;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					must_eat;
	int					num_meals;
	bool				is_full;
	int					*num_full_philos;
	int					num_philos;
}	t_philo;

// Threads and mutexes
pthread_t		*create_threads(int num_philos, t_philo *philosophers);
void			terminate_threads(int num_philos, pthread_t *threads);
void			destroy_mutexes(int num_philos, pthread_mutex_t *forks);
pthread_mutex_t	*create_forks(int num_philos);

// Routine
void			*routine(void *arg);
void			*routine_one_philo(void *arg);

// Utils
long int		get_current_time(void);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlen(const char *str);
int				ft_atoi(const char *str);

#endif