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

void	terminate_threads(t_dining *dining)
{
	int	i;

	i = 0;
	while (i < dining->num_philos)
	{
		pthread_join(dining->philo_threads[i], NULL);
		i++;
	}
	pthread_join(dining->monitor_philos, NULL);
}

void	destroy_mutexes(t_dining *dining)
{
	int	i;

	i = 0;
	while (i < dining->num_philos)
	{
		pthread_mutex_destroy(&dining->forks[i]);
		pthread_mutex_destroy(&dining->philos[i].mutex_state);
		pthread_mutex_destroy(&dining->philos[i].mutex_time_last_meal);
		pthread_mutex_destroy(&dining->philos[i].mutex_num_meals);
		i++;
	}
	pthread_mutex_destroy(&dining->mutex_print);
	pthread_mutex_destroy(&dining->mutex_time_to_die);
	pthread_mutex_destroy(&dining->mutex_time_to_eat);
	pthread_mutex_destroy(&dining->mutex_time_to_sleep);
	pthread_mutex_destroy(&dining->mutex_must_eat);
	pthread_mutex_destroy(&dining->mutex_num_philos);
	pthread_mutex_destroy(&dining->mutex_num_full_philos);
}

void	free_data(t_dining *dining)
{
	free(dining->forks);
	free(dining->philo_threads);
	free(dining->philos);
	free(dining);
}
