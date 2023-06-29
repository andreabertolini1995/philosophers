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

void	set_philo_state(t_philo *philo, t_state state)
{
	pthread_mutex_lock(&philo->mutex_state);
	philo->state = state;
	pthread_mutex_unlock(&philo->mutex_state);
}

void	set_time_last_meal(t_philo *philo, long int time_last_meal)
{
	pthread_mutex_lock(&philo->mutex_time_last_meal);
	philo->time_last_meal = time_last_meal;
	pthread_mutex_unlock(&philo->mutex_time_last_meal);
}
