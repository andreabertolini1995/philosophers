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

typedef struct s_philo_state
{
	bool	eating;
	bool	sleeping;
	bool	thinking;
	bool	death;
}	t_philo_state;

typedef struct s_philo
{
	int				number;
    pthread_t       thread;
	struct s_philo  *next;  // this can be the philosophers sitting next
	int				forks;
	t_philo_state	state;
}	t_philo;

// Philo actions
void    philo_eat(t_philo philo);
void    philo_sleep(t_philo philo);
void    philo_think(t_philo philo);
void    philo_fork(t_philo philo);
void    philo_die(t_philo philo);

// Utils
double  get_timestamp();

#endif