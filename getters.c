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

void	print(t_philo *philo, char *action)
{
	pthread_mutex_lock(&philo->dining_data->mutex_print);
	if (get_philo_state(philo) != DEAD)
		printf("%ld %d %s\n", get_current_time()
			- philo->dining_data->start_time, philo->number, action);
	pthread_mutex_unlock(&philo->dining_data->mutex_print);
}

t_state	get_philo_state(t_philo *philo)
{
	t_state	state;

	pthread_mutex_lock(&philo->mutex_state);
	state = philo->state;
	pthread_mutex_unlock(&philo->mutex_state);
	return (state);
}

long int	get_time_last_meal(t_philo *philo)
{
	long int	time_last_meal;

	pthread_mutex_lock(&philo->mutex_time_last_meal);
	time_last_meal = philo->time_last_meal;
	pthread_mutex_unlock(&philo->mutex_time_last_meal);
	return (time_last_meal);
}

int	get_num_philos(t_dining *dining_data)
{
	int	num_philos;

	pthread_mutex_lock(&dining_data->mutex_num_philos);
	num_philos = dining_data->num_philos;
	pthread_mutex_unlock(&dining_data->mutex_num_philos);
	return (num_philos);
}

int	get_num_full_philos(t_dining *dining_data)
{
	int	num_full_philos;

	pthread_mutex_lock(&dining_data->mutex_num_full_philos);
	num_full_philos = dining_data->num_full_philos;
	pthread_mutex_unlock(&dining_data->mutex_num_full_philos);
	return (num_full_philos);
}
