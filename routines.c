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
	while (philo->state != DEAD)
	{
		philo_think(philo);
		philo_died(philo);
	}
	return (NULL);
}

void	*philos_routine(void *arg)
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

void	notify_all_philos(t_dining *dining)
{
	int		i;

	i = 0;
	while (i < dining->num_philos)
	{
		dining->philos[i].state = DEAD;
		i++;
	}
}

void	*all_alive_routine(void *arg)
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
		if (i == dining->num_philos - 1)
			i = 0;
		else
			i++;
	}
	return (NULL);
}

// void	*all_full_routine(void *arg)
// {
// 	t_dining	*dining;

// 	dining = (t_dining *) arg;
// if (philo->num_meals == philo->must_eat && philo->is_full == false)
		// {
		// 	philo->is_full = true;
		// 	philo->num_full_philos[0]++;
		// }
		// if (philo->num_full_philos[0] == philo->num_philos)
		// 	exit(1);

// }
