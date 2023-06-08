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
    pthread_mutex_lock(&philo->mutex); // mutexes have to be used for the forks - which are the shared resources in the problem
    while (42) // infinite loop 
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
    return (NULL);
}

static void    fill_philos_list(t_philo *philos_list, int num_philos)
{
    int i;

    i = 1;
    while (i < num_philos)
	{
		add_philo(&philos_list, new_philo(i + 1, philos_list->time_to_die,
                    philos_list->time_to_eat, philos_list->time_to_sleep));
		i++;
	}
    last_philo(philos_list)->next = philos_list;
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

int	main(int argc, char **argv)
{
    t_philo *philos_list;
    int     num_philos;
    int     num_forks;
    
    if (argc > 5)
    {
        printf("Too many arguments provided.\n");
        return (1);
    }
    num_philos = atoi(argv[1]);
    num_forks = num_philos;
    philos_list = new_philo(1, atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));
    fill_philos_list(philos_list, num_philos);
	return (0);
}

/* 
Next steps:
- understand more about routines and mutexes
- make sure that the general approach is correct
- understand how to simulate forks and how do the philosophers take them?
- How do I check the general functioning of the algorithm? Are there cases where I know what is supposed to be the final outcome? Also, should it always be the same given the same input or can it be different?
*/
