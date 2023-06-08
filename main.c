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

void    *routine(void *arg)
{
    t_philo *philo;

    philo = (t_philo*) arg;
    pthread_mutex_lock(&philo->mutex);
    while (42) 
    {
        philo_take_fork(philo, "left");
        philo_take_fork(philo, "right");
        philo_eat(philo);
        philo_sleep(philo);
        philo_think(philo);
        if (get_timestamp() > (philo->time_last_meal + philo->time_to_die))
            philo_die(philo);
    }
    pthread_mutex_unlock(&philo->mutex);
}

static void    fill_philos_list(t_philo *philos_list, int num_philos)
{
    int     i;
    t_philo *last_node;

    i = 1;
    while (i < num_philos)
	{
		add_philo(&philos_list, new_philo(i + 1, philos_list->time_to_die,
                    philos_list->time_to_eat, philos_list->time_to_sleep));
		i++;
	}
    last_node = last_philo(philos_list);
    last_node->next = philos_list;
    philos_list->prev = last_node;
}

int    terminate_threads(t_philo *philos_list, int num_philos)
{
    int i;

    i = 0;
    while (i < num_philos)
    {
        if (pthread_join(philos_list->thread, NULL) != 0)
            return (1);
        printf("Thread %d has finished execution\n", i + 1);
        i++;
    }
    return (0);
}

t_fork *initialize_forks(int num_philos)
{
    t_fork*    forks;
    int     i;

    forks = (t_fork* ) malloc (sizeof(t_fork) * num_philos);
	if (forks == NULL)
		return (NULL);
    i = 0;
    while (i < num_philos)
    {
        forks[i] = available;
        i++;
    }
    return (forks);
}

int	main(int argc, char **argv)
{
    t_philo *philos_list;
    t_fork  *forks;
    int     num_philos;
    
    if (argc > 5)
        printf("Too many arguments provided.\n");
    num_philos = atoi(argv[1]);
    forks = initialize_forks(num_philos);
    philos_list = new_philo(1, atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));
    fill_philos_list(philos_list, num_philos);
    // pthread_mutex_destroy(&mutex);
    terminate_threads(philos_list, num_philos);
}

/* 
Next steps:
- understand more about routines and mutexes
- make sure that the general approach is correct
- understand how to simulate forks and how do the philosophers take them?
- understand how to finish the simulation
- How do I check the general functioning of the algorithm? 
    - Are there cases where I know what is supposed to be the final outcome?
    - Also, should it always be the same given the same input or can it be different? We can check that, but I doubt it.
- Do we need a mutex for each philo or just one in general?
- Currently, philosophers never eat
*/
