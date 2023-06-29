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

void	*one_philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	while (42)
	{
		if (philo_think(philo) == 1)
			break ;
		usleep(500);
	}
	return (NULL);
}

void	*all_philos_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	while (42)
	{
		if (philo_think(philo) == 1)
			break ;
		if (get_philo_state(philo) == DEAD)
			break ;
		if (philo_eat(philo) == 1)
			break ;
		if (get_philo_state(philo) == DEAD)
			break ;
		if (philo_sleep(philo) == 1)
			break ;
	}
	return (NULL);
}

static int	update_philo_index(t_dining *dining, int i)
{
	if (i == get_num_philos(dining) - 1)
		i = 0;
	else
		i++;
	return (i);
}

static void	notify_all_philos(t_dining *dining)
{
	int		i;

	i = 0;
	while (i < get_num_philos(dining))
	{
		set_philo_state(&dining->philos[i], DEAD);
		i++;
	}
}

void	*check_if_philos_are_dead_or_full(void *arg)
{
	t_dining	*dining;
	int			i;

	dining = (t_dining *) arg;
	i = 0;
	while (i < dining->num_philos)
	{
		if (philo_died(&dining->philos[i]))
		{
			notify_all_philos(dining);
			break ;
		}
		else if (is_philo_full(&dining->philos[i]))
		{
			set_num_full_philos(dining, get_num_full_philos(dining) + 1);
			if (get_num_full_philos(dining) == get_num_philos(dining)
				&& get_num_full_philos(dining) != 0)
				break ;
		}
		i = update_philo_index(dining, i);
	}
	return (NULL);
}
