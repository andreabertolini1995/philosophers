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

static t_philo	*create_philosophers(int num_philos, pthread_mutex_t *forks,
									int *times, long int start_time)
{
	t_philo	*philosophers;
	int		i;

	philosophers = (t_philo *) malloc (sizeof(t_philo) * num_philos);
	if (philosophers == NULL)
		return (NULL);
	i = 0;
	while (i < num_philos)
	{
		philosophers[i].number = i + 1;
		philosophers[i].start_time = start_time;
		philosophers[i].time_to_die = times[0];
		philosophers[i].time_to_eat = times[1];
		philosophers[i].time_to_sleep = times[2];
		philosophers[i].left_fork = &forks[i];
		if (philosophers[i].number == 1)
			philosophers[i].right_fork = &forks[num_philos - 1];
		else
			philosophers[i].right_fork = &forks[i + 1];
		i++;
	}
	return (philosophers);
}

int	main(int argc, char **argv)
{
	int				num_philos;
	pthread_mutex_t	*forks;
	pthread_t		*threads;
	t_philo			*philosophers;
	int				times[3];

	if (argc > 5)
	{
		printf("Too many arguments provided.\n");
		return (1);
	}
	num_philos = atoi(argv[1]);
	times[0] = atoi(argv[2]);
	times[1] = atoi(argv[3]);
	times[2] = atoi(argv[4]);
	forks = create_forks(num_philos);
	philosophers = create_philosophers(num_philos, forks,
			times, get_current_time());
	threads = create_threads(num_philos, philosophers);
	terminate_threads(num_philos, threads);
	destroy_mutexes(num_philos, forks);
	return (0);
}
