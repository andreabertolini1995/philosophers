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

pthread_mutex_t	*create_forks(int num_philos)
{
	pthread_mutex_t	*forks;
	int				i;

	forks = (pthread_mutex_t *) malloc (sizeof(pthread_mutex_t) * num_philos);
	if (forks == NULL)
		return (0);
	i = 0;
	while (i < num_philos)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	return (forks);
}

int	create_threads(t_dining *dining)
{
	int			i;

	i = 0;
	dining->philo_threads = (pthread_t *) malloc
		(sizeof(pthread_t) * dining->num_philos);
	if (dining->philo_threads == NULL)
		return (0);
	if (dining->num_philos == 1)
		pthread_create(&dining->philo_threads[i], NULL,
			&one_philo_routine, (void *)&dining->philos[i]);
	else
	{
		while (i < dining->num_philos)
		{
			pthread_create(&dining->philo_threads[i], NULL,
				&all_philos_routine, (void *)&dining->philos[i]);
			i++;
		}
	}
	pthread_create(&dining->monit_all_alive, NULL,
		&check_if_philos_are_dead, dining);
	pthread_create(&dining->monit_all_full, NULL,
		&check_if_philos_are_full, dining);
	return (0);
}

void	terminate_threads(t_dining *dining)
{
	int	i;

	i = 0;
	while (i < dining->num_philos)
	{
		pthread_join(dining->philo_threads[i], NULL);
		i++;
	}
	pthread_join(dining->monit_all_alive, NULL);
	pthread_join(dining->monit_all_full, NULL);
}

void	destroy_mutexes(t_dining *dining)
{
	int	i;

	i = 0;
	while (i < dining->num_philos)
	{
		pthread_mutex_destroy(&dining->forks[i]);
		i++;
	}
}
