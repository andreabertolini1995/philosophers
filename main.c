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

void    *routine()
{
    // printf("Philo is created.\n");
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

int	main(int argc, char **argv)
{
    t_philo *philos_list;
    int     num_philos;
    int     time_to_die;
    int     time_to_eat;
    int     time_to_sleep;
    
    if (argc > 5)
    {
        printf("Too many arguments provided.\n");
        return (1);
    }
    num_philos = atoi(argv[1]);
    time_to_die = atoi(argv[2]);
    time_to_eat = atoi(argv[3]);
    time_to_sleep = atoi(argv[4]);

    philos_list = new_philo(1);
    fill_philos_list(philos_list, num_philos);

    // philo_eat(philos[1]);
    // philo_think(philos[3]);
    // philo_sleep(philos[2]);
    // philosophers = (pthread_t*) malloc (sizeof(pthread_t));
    // if (philosophers == NULL)
    //     return (1);
    // i = 0;
    // while (i < num_philos)
    // {
    //     if (pthread_join(philosophers[i], NULL) != 0)
    //         return (1);
    //     printf("Thread %d has finished execution\n", i);
    //     i++;
    // }
	return (0);
}
