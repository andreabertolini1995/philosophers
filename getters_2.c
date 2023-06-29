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

int	get_time_to_die(t_dining *dining_data)
{
	int	time_to_die;

	pthread_mutex_lock(&dining_data->mutex_time_to_die);
	time_to_die = dining_data->time_to_die;
	pthread_mutex_unlock(&dining_data->mutex_time_to_die);
	return (time_to_die);
}

int	get_time_to_eat(t_dining *dining_data)
{
	int	time_to_eat;

	pthread_mutex_lock(&dining_data->mutex_time_to_eat);
	time_to_eat = dining_data->time_to_eat;
	pthread_mutex_unlock(&dining_data->mutex_time_to_eat);
	return (time_to_eat);
}

int	get_time_to_sleep(t_dining *dining_data)
{
	int	time_to_sleep;

	pthread_mutex_lock(&dining_data->mutex_time_to_sleep);
	time_to_sleep = dining_data->time_to_sleep;
	pthread_mutex_unlock(&dining_data->mutex_time_to_sleep);
	return (time_to_sleep);
}

int	get_num_meals(t_philo *philo)
{
	int	num_meals;

	pthread_mutex_lock(&philo->mutex_num_meals);
	num_meals = philo->num_meals;
	pthread_mutex_unlock(&philo->mutex_num_meals);
	return (num_meals);
}
