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

    philo = (t_philo*)arg;
    pthread_mutex_lock(&philo->mutex);
    while (42)
    {
        // philo_take_fork(philo, "left");
        // philo_eat(philo);
        philo_sleep(philo);
        philo_think(philo);
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
		add_philo(&philos_list, new_philo(i + 1));
		i++;
	}
    last_philo(philos_list)->next = philos_list;
}

void    terminate_threads(t_philo *philos_list, int num_philos)
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
}

int	main(int argc, char **argv)
{
    t_philo *philos_list;
    int     num_philos;
    int     num_forks;
    int     time_to_die;
    int     time_to_eat;
    int     time_to_sleep;
    
    if (argc > 5)
    {
        printf("Too many arguments provided.\n");
        return (1);
    }
    num_philos = atoi(argv[1]);
    num_forks = num_philos;
    time_to_die = atoi(argv[2]);
    time_to_eat = atoi(argv[3]);
    time_to_sleep = atoi(argv[4]);

    philos_list = new_philo(1);
    fill_philos_list(philos_list, num_philos);
	return (0);
}

/* 
Next steps:
- understand more about routines and mutexes
- understand how to use the input parameters to make the philos sleeping/eating accordingly
- make sure that the general approach is correct
*/
