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

pthread_t	*create_threads(int num_philos, t_philo *philosophers)
{
	pthread_t	*threads;
	int			i;

	i = 0;
	threads = (pthread_t *) malloc (sizeof(pthread_t) * num_philos);
	if (threads == NULL)
		return (0);
	if (num_philos == 1)
		pthread_create(&threads[i], NULL, &routine_one_philo, (void *)&philosophers[i]);
	else
	{
		while (i < num_philos)
		{
			pthread_create(&threads[i], NULL, &routine, (void *)&philosophers[i]);
			i++;
		}
	}
	return (threads);
}

void	terminate_threads(int num_philos, pthread_t *threads)
{
	int	i;

	i = 0;
	while (i < num_philos)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
}

void	destroy_mutexes(int num_philos, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < num_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}
