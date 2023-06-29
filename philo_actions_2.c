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

int	take_right_fork(t_philo *philo)
{
	if (get_philo_state(philo) == DEAD
		|| (get_num_full_philos(philo->dining_data)
			== get_num_philos(philo->dining_data)))
		return (1);
	if (pthread_mutex_lock(philo->right_fork) != 0)
		return (1);
	print(philo, "has taken a fork");
	return (0);
}

int	take_left_fork(t_philo *philo)
{
	if (get_philo_state(philo) == DEAD
		|| (get_num_full_philos(philo->dining_data)
			== get_num_philos(philo->dining_data)))
		return (1);
	if (pthread_mutex_lock(philo->left_fork) != 0)
		return (1);
	print(philo, "has taken a fork");
	return (0);
}

int	pick_up_forks(t_philo *philo)
{
	if (philo->number % 2 == 0)
	{
		if (take_left_fork(philo) == 1)
			return (1);
		if (take_right_fork(philo) == 1)
		{
			pthread_mutex_unlock(philo->left_fork);
			return (1);
		}
	}
	else
	{
		if (take_right_fork(philo) == 1)
			return (1);
		if (take_left_fork(philo) == 1)
		{
			pthread_mutex_unlock(philo->right_fork);
			return (1);
		}
	}
	return (0);
}

bool	is_philo_full(t_philo *philo)
{
	if (get_num_meals(philo) == philo->dining_data->must_eat
		&& philo->is_full == false)
	{
		philo->is_full = true;
		return (true);
	}
	return (false);
}
