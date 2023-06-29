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

static void	ft_usleep(int time_to_wait)
{
	long int	current_time;

	current_time = get_current_time();
	while (get_current_time() < current_time + time_to_wait)
		usleep(500);
}

int	philo_eat(t_philo *philo)
{
	if (pick_up_forks(philo) == 1)
		return (1);
	print(philo, "is eating");
	set_philo_state(philo, EATING);
	set_time_last_meal(philo, get_current_time());
	ft_usleep(get_time_to_eat(philo->dining_data));
	set_num_meals(philo, get_num_meals(philo) + 1);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	return (0);
}

int	philo_sleep(t_philo *philo)
{
	if (get_philo_state(philo) == DEAD
		|| (get_num_full_philos(philo->dining_data)
			== get_num_philos(philo->dining_data)))
		return (1);
	print(philo, "is sleeping");
	set_philo_state(philo, SLEEPING);
	ft_usleep(get_time_to_sleep(philo->dining_data));
	return (0);
}

int	philo_think(t_philo *philo)
{
	if (get_philo_state(philo) == DEAD
		|| (get_num_full_philos(philo->dining_data)
			== get_num_philos(philo->dining_data)))
		return (1);
	print(philo, "is thinking");
	set_philo_state(philo, THINKING);
	return (0);
}

bool	philo_died(t_philo *philo)
{
	if (get_current_time() > (get_time_last_meal(philo)
			+ get_time_to_die(philo->dining_data))
		&& get_philo_state(philo) != EATING)
	{
		if (philo->is_full == false)
			print(philo, "died");
		set_philo_state(philo, DEAD);
		return (true);
	}
	return (false);
}
