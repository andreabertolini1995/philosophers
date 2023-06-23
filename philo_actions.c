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
	printf("%ld %d %s\n", get_current_time()
			- philo->start_time, philo->number, action);
}

int philo_eat(t_philo *philo)
{
	if (pick_up_forks(philo) == 1)
			return (1);
	print(philo, "is eating");
    philo->state = EATING;
	philo->num_meals++;
	usleep((philo->time_to_eat) * 1000);
	philo->time_last_meal = get_current_time();
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	return (0);
}

int philo_sleep(t_philo *philo)
{
	print(philo, "is sleeping");
	if (philo->state == DEAD)
        return (1);
	philo->state = SLEEPING;
	usleep((philo->time_to_sleep) * 1000);
	return (0);
}

int philo_think(t_philo *philo)
{
	print(philo, "is thinking");
    if (philo->state == DEAD)
        return (1);
    philo->state = THINKING;
	return (0);
}

bool philo_died(t_philo *philo)
{
	if (get_current_time() > (philo->time_last_meal + philo->time_to_die) && philo->state != EATING)
	{
		print(philo, "died");
        philo->state = DEAD;
		return (true);
	}
	return (false);
}
