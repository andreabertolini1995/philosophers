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

typedef enum e_philo_state
{
	EATING,
	SLEEPING,
	THINKING,
	DEAD,
}	t_state;
typedef struct s_philo
{
	int					number;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	
	int					num_meals;
	long int			time_last_meal;

	long int			start_time;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					must_eat;

	bool				is_full;
	t_state				state;

}	t_philo;

typedef struct s_dining
{
	int				num_philos;
	long int		start_time;
	
	pthread_mutex_t	*forks;
	t_philo			*philos;
	pthread_t		*philo_threads;
	
	int				num_full_philos;

	pthread_t		monit_all_alive;
	pthread_t		monit_all_full;
}	t_dining;

// Threads and mutexes
int				create_threads(t_dining *dining);
void			terminate_threads(t_dining *dining);
void			destroy_mutexes(t_dining *dining);
pthread_mutex_t	*create_forks(int num_philos);

// Routine
void			*one_philo_routine(void *arg);
void			*all_philos_routine(void *arg);
void			*check_if_philos_are_dead(void *arg);
void			*check_if_philos_are_full(void *arg);

// Utils
long int		get_current_time(void);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlen(const char *str);
int				ft_atoi(const char *str);

// Philo actions
void			print(t_philo *philo, char *action);
int				philo_eat(t_philo *philo);
int				philo_sleep(t_philo *philo);
int				philo_think(t_philo *philo);
bool			philo_died(t_philo *philo);
int				take_right_fork(t_philo *philo);
int				take_left_fork(t_philo *philo);
int				pick_up_forks(t_philo *philo);

#endif