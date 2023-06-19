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

static void	print(t_philo *philo, char *action)
{
	printf("%ld %d %s\n", get_current_time()
			- philo->start_time, philo->number, action);
}

static void	pick_up_forks(t_philo *philo)
{
	if (philo->number % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		print(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		print(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print(philo, "has taken a fork");
	}
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	while (42)
	{
		print(philo, "is thinking");
		pick_up_forks(philo);
		print(philo, "is eating");
		usleep((philo->time_to_eat) * 1000);
		philo->num_meals++;
		philo->time_last_meal = get_current_time();
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		print(philo, "is sleeping");
		usleep((philo->time_to_sleep) * 1000);
		if (get_current_time() > (philo->time_last_meal + philo->time_to_die))
		{
			print(philo, "died");
			exit(1);
		}
		if (philo->num_meals == philo->must_eat && philo->is_full == false)
		{
			philo->is_full = true;
			philo->num_full_philos[0]++;
		}
		if (philo->num_full_philos[0] == philo->num_philos)
			exit(1);
	}
}
