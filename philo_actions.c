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

int	philo_eat(t_philo *philo)
{
	if (pick_up_forks(philo) == 1)
		return (1);
	print(philo, "is eating");
	set_philo_state(philo, EATING);
	usleep((philo->dining_data->time_to_eat) * 1000);
	set_time_last_meal(philo, get_current_time());
	philo->num_meals++;
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	return (0);
}

int	philo_sleep(t_philo *philo)
{
	if (get_philo_state(philo) == DEAD || (philo->dining_data->num_full_philos
			== philo->dining_data->num_philos))
		return (1);
	print(philo, "is sleeping");
	set_philo_state(philo, SLEEPING);
	usleep((philo->dining_data->time_to_sleep) * 1000);
	return (0);
}

int	philo_think(t_philo *philo)
{
	if (get_philo_state(philo) == DEAD || (philo->dining_data->num_full_philos
			== philo->dining_data->num_philos))
		return (1);
	print(philo, "is thinking");
	set_philo_state(philo, THINKING);
	return (0);
}

bool	philo_died(t_philo *philo)
{
	if (get_current_time() > (get_time_last_meal(philo) + philo->dining_data->time_to_die)
			&& get_philo_state(philo) != EATING)
	{
		if (philo->is_full == false)
			print(philo, "died");
		set_philo_state(philo, DEAD);
		return (true);
	}
	return (false);
}
