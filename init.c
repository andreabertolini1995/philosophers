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

void	initialize_philos(t_dining *dining, t_philo *philos,
							int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < dining->num_philos)
	{
		philos[i].number = i + 1;
		philos[i].time_last_meal = get_current_time();
		philos[i].start_time = get_current_time();
		philos[i].time_to_die = ft_atoi(argv[2]);
		philos[i].time_to_eat = ft_atoi(argv[3]);
		philos[i].time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			philos[i].must_eat = ft_atoi(argv[5]);
		philos[i].num_meals = 0;
		philos[i].is_full = false;
		philos[i].state = THINKING;
		philos[i].left_fork = &dining->forks[i];
		if (philos[i].number == 1)
			philos[i].right_fork = &dining->forks[dining->num_philos - 1];
		else
			philos[i].right_fork = &dining->forks[i + 1];
		pthread_mutex_init(&dining->mutex_print, NULL);
		philos[i].dining_data = dining;
		i++;
	}
}

t_philo	*create_philosophers(t_dining *dining, int argc, char **argv)
{
	t_philo	*philos;

	philos = (t_philo *) malloc (sizeof(t_philo) * dining->num_philos);
	if (philos == NULL)
		return (NULL);
	initialize_philos(dining, philos, argc, argv);
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
	dining->philos = create_philosophers(dining, argc, argv);
	create_threads(dining);
	dining->num_full_philos = 0;
	return (dining);
}

int	check_input(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
	{
		printf("Too many or too few arguments provided.\n");
		return (1);
	}
	if (ft_atoi(argv[1]) < 1)
	{
		printf("There should be at least one philosopher.\n");
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		if (!ft_str_is_numeric(argv[i]))
		{
			printf("All the arguments must be a positive integer.\n");
			return (1);
		}
		i++;
	}
	return (0);
}