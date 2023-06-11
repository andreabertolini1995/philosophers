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

typedef enum s_philo_state
{
	eating,
	sleeping,
	thinking,
	dead
}	t_philo_state;

typedef enum s_fork
{
	taken,
	available
}	t_fork;

typedef struct s_philo
{
	pthread_t       thread;
	int				number;
	pthread_mutex_t mutex;
	t_fork			right_fork;
	t_fork			left_fork;
	int				num_forks;
	t_philo_state	state;
	double			time_to_die;
	double			time_to_eat;
	double			time_to_sleep;
	double			time_last_meal;
	struct s_philo  *next;
	struct s_philo	*prev;
}	t_philo;

// Philo actions
void    philo_eat(t_philo *philo);
void    philo_sleep(t_philo *philo);
void    philo_think(t_philo *philo);
void    philo_take_fork(t_philo *philo, char *side);
void    philo_die(t_philo *philo);

// Circular list utils
t_philo	*last_philo(t_philo *lst);
t_philo	*new_philo(int philo_number, double time_to_die,
		double time_to_eat, double time_to_sleep);
void	add_philo(t_philo **lst, t_philo *new);
int		get_list_size(t_philo *lst);

// Routine
void    *routine(void *arg);

// Utils
long int	get_timestamp();
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlen(const char *str);

#endif