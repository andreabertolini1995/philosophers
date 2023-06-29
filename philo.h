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
	EATING = 0,
	SLEEPING = 1,
	THINKING = 2,
	DEAD = 3,
}	t_state;

typedef struct s_philo
{
	int					number;
	t_state				state;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	int					num_meals;
	long int			time_last_meal;
	bool				is_full;
	pthread_mutex_t		mutex_state;
	pthread_mutex_t		mutex_time_last_meal;
	pthread_mutex_t		mutex_num_meals;
	struct s_dining		*dining_data;
}	t_philo;

typedef struct s_dining
{
	int				num_philos;
	long int		start_time;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				num_full_philos;
	t_philo			*philos;
	pthread_t		*philo_threads;
	pthread_t		monitor_philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	mutex_time_to_die;
	pthread_mutex_t	mutex_time_to_eat;
	pthread_mutex_t	mutex_time_to_sleep;
	pthread_mutex_t	mutex_must_eat;
	pthread_mutex_t	mutex_num_philos;
	pthread_mutex_t	mutex_num_full_philos;
}	t_dining;

// Init
void			initialize_philos(t_dining *dining, t_philo *philos);
t_philo			*create_philosophers(t_dining *dining);
t_dining		*initialize_dining_data(int argc, char **argv);
int				check_input(int argc, char **argv);
int				create_threads(t_dining *dining);
pthread_mutex_t	*create_forks(int num_philos);

// Final
void			terminate_threads(t_dining *dining);
void			destroy_mutexes(t_dining *dining);
void			free_data(t_dining *dining);

// Routine
void			*one_philo_routine(void *arg);
void			*all_philos_routine(void *arg);
void			*check_if_philos_are_dead_or_full(void *arg);

// Utils
long int		get_current_time(void);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlen(const char *str);
int				ft_atoi(const char *str);
int				ft_str_is_numeric(char *str);

// Philo actions
int				philo_eat(t_philo *philo);
int				philo_sleep(t_philo *philo);
int				philo_think(t_philo *philo);
bool			philo_died(t_philo *philo);
int				take_right_fork(t_philo *philo);
int				take_left_fork(t_philo *philo);
int				pick_up_forks(t_philo *philo);
bool			is_philo_full(t_philo *philo);

// Getters
void			print(t_philo *philo, char *action);
t_state			get_philo_state(t_philo *philo);
long int		get_time_last_meal(t_philo *philo);
int				get_time_to_die(t_dining *dining_data);
int				get_time_to_eat(t_dining *dining_data);
int				get_time_to_sleep(t_dining *dining_data);
int				get_num_meals(t_philo *philo);
int				get_num_philos(t_dining *dining_data);
int				get_num_full_philos(t_dining *dining_data);
int				get_must_eat(t_dining *dining_data);

// Setters
void			set_philo_state(t_philo *philo, t_state state);
void			set_time_last_meal(t_philo *philo, long int time_last_meal);
void			set_num_meals(t_philo *philo, int num_meals);
void			set_num_full_philos(t_dining *dining_data, int num_full_philos);

#endif