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

void	initialize_philos(t_dining *dining, t_philo *philos)
{
	int	i;

	i = 0;
	pthread_mutex_init(&dining->mutex_print, NULL);
	while (i < dining->num_philos)
	{
		philos[i].number = i + 1;
		philos[i].time_last_meal = get_current_time();
		philos[i].num_meals = 0;
		philos[i].is_full = false;
		philos[i].state = THINKING;
		philos[i].left_fork = &dining->forks[i];
		if (philos[i].number == 1)
			philos[i].right_fork = &dining->forks[dining->num_philos - 1];
		else
			philos[i].right_fork = &dining->forks[i - 1];
		pthread_mutex_init(&philos[i].mutex_state, NULL);
		pthread_mutex_init(&philos[i].mutex_time_last_meal, NULL);
		pthread_mutex_init(&philos[i].mutex_num_meals, NULL);
		philos[i].dining_data = dining;
		i++;
	}
}

t_philo	*create_philosophers(t_dining *dining)
{
	t_philo	*philos;

	philos = (t_philo *) malloc (sizeof(t_philo) * dining->num_philos);
	if (philos == NULL)
		return (NULL);
	initialize_philos(dining, philos);
	return (philos);
}

t_dining	*initialize_dining_data(int argc, char **argv)
{
	t_dining		*dining;

	dining = (t_dining *) malloc (sizeof(t_dining));
	if (dining == NULL)
		return (NULL);
	dining->num_philos = ft_atoi(argv[1]);
	dining->start_time = get_current_time();
	dining->forks = create_forks(dining->num_philos);
	dining->philos = create_philosophers(dining);
	create_threads(dining);
	dining->num_full_philos = 0;
	dining->start_time = get_current_time();
	dining->time_to_die = ft_atoi(argv[2]);
	dining->time_to_eat = ft_atoi(argv[3]);
	dining->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		dining->must_eat = ft_atoi(argv[5]);
	pthread_mutex_init(&dining->mutex_time_to_die, NULL);
	pthread_mutex_init(&dining->mutex_time_to_eat, NULL);
	pthread_mutex_init(&dining->mutex_time_to_sleep, NULL);
	pthread_mutex_init(&dining->mutex_must_eat, NULL);
	pthread_mutex_init(&dining->mutex_num_philos, NULL);
	pthread_mutex_init(&dining->mutex_num_full_philos, NULL);
	return (dining);
}

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
	pthread_create(&dining->monitor_philos, NULL,
		&check_if_philos_are_dead_or_full, dining);
	return (0);
}
