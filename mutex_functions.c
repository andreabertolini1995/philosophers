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

# include "philo.h"

void	print(t_philo *philo, char *action)
{
	pthread_mutex_lock(&philo->dining_data->mutex_print);
	printf("%ld %d %s\n", get_current_time()
		- philo->start_time, philo->number, action);
	pthread_mutex_unlock(&philo->dining_data->mutex_print);
}

t_state	get_philo_state(t_philo *philo)
{
	t_state state;

	pthread_mutex_lock(&philo->mutex_state);
	state = philo->state;
	pthread_mutex_unlock(&philo->mutex_state);
	return (state);
}

void	set_philo_state(t_philo *philo, t_state state)
{
	pthread_mutex_lock(&philo->mutex_state);
	philo->state = state;
	pthread_mutex_unlock(&philo->mutex_state);
}