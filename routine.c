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

#include "philo.h"

static void	pick_up_forks(t_philo *philo)
{
	if (philo->number % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		printf("%ld %d has taken a fork\n", get_current_time()
			- philo->start_time, philo->number);
		pthread_mutex_lock(philo->right_fork);
		printf("%ld %d has taken a fork\n", get_current_time()
			- philo->start_time, philo->number);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		printf("%ld %d has taken a fork\n", get_current_time()
			- philo->start_time, philo->number);
		pthread_mutex_lock(philo->left_fork);
		printf("%ld %d has taken a fork\n", get_current_time()
			- philo->start_time, philo->number);
	}
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	while (42)
	{
		printf("%ld %d is thinking\n", get_current_time()
			- philo->start_time, philo->number);
		pick_up_forks(philo);
		printf("%ld %d is eating\n", get_current_time()
			- philo->start_time, philo->number);
		usleep((philo->time_to_eat) * 1000);
		philo->time_last_meal = get_current_time();
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		printf("%ld %d is sleeping\n", get_current_time()
			- philo->start_time, philo->number);
		usleep((philo->time_to_sleep) * 1000);
		if (get_current_time() > (philo->time_last_meal + philo->time_to_die))
		{
			printf("%ld %d died\n", get_current_time()
				- philo->start_time, philo->number);
			exit(1);
		}
	}
}
