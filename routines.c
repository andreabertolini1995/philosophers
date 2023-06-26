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
		if (philo->state == DEAD)
			break ;
		if (philo_eat(philo) == 1)
			break ;
		if (philo->state == DEAD)
			break ;
		if (philo_sleep(philo) == 1)
			break ;
	}
	return (NULL);
}

static int	update_philo_index(t_dining *dining, int i)
{
	if (i == dining->num_philos - 1)
		i = 0;
	else
		i++;
	return (i);
}

static void	notify_all_philos(t_dining *dining)
{
	int		i;

	i = 0;
	while (i < dining->num_philos)
	{
		dining->philos[i].state = DEAD;
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
			dining->num_full_philos++;
			if (dining->num_full_philos == dining->num_philos
				&& dining->num_full_philos != 0)
			{
				notify_all_philos(dining);
				break ;
			}
		}
		i = update_philo_index(dining, i);
	}
	return (NULL);
}
