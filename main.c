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

static t_philo	*create_philosophers(int *num_philos, pthread_mutex_t *forks,
									int *times, long int start_time)
{
	t_philo	*philosophers;
	int		i;

	philosophers = (t_philo *) malloc (sizeof(t_philo) * num_philos[0]);
	if (philosophers == NULL)
		return (NULL);
	i = 0;
	while (i < num_philos[0])
	{
		philosophers[i].number = i + 1;
		philosophers[i].start_time = start_time;
		philosophers[i].time_to_die = times[0];
		philosophers[i].time_to_eat = times[1];
		philosophers[i].time_to_sleep = times[2];
		if (sizeof(times) == 8)
			philosophers[i].must_eat = times[3];
		philosophers[i].num_meals = 0;
		philosophers[i].is_full = false;
		philosophers[i].num_full_philos = &num_philos[1];
		philosophers[i].num_philos = num_philos[0];
		philosophers[i].left_fork = &forks[i];
		if (philosophers[i].number == 1)
			philosophers[i].right_fork = &forks[num_philos[0] - 1];
		else
			philosophers[i].right_fork = &forks[i + 1];
		i++;
	}
	return (philosophers);
}

static int	*fill_times_array(int argc, char **argv)
{
	int	i;
	int	*times;

	i = 0;
	times = (int *) malloc (sizeof(int) * (argc - 2));
	if (times == NULL)
		return (NULL);
	i = 0;
	while (i < (argc - 2))
	{
		times[i] = ft_atoi(argv[i + 2]);
		i++;
	}
	return (times);
}

int	main(int argc, char **argv)
{
	pthread_mutex_t	*forks;
	pthread_t		*threads;
	t_philo			*philosophers;
	int				*times;
	int				num_philos[2];

	if (argc < 5 || argc > 6)
	{
		printf("Too many ot too few arguments provided.\n");
		return (1);
	}
	num_philos[0] = ft_atoi(argv[1]);
	num_philos[1] = 0;
	times = fill_times_array(argc, argv);
	forks = create_forks(num_philos[0]);
	philosophers = create_philosophers(num_philos, forks,
			times, get_current_time());
	threads = create_threads(num_philos[0], philosophers);
	terminate_threads(num_philos[0], threads);
	destroy_mutexes(num_philos[0], forks);
	return (0);
}
