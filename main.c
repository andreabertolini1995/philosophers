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

t_philo *initialize_philos(int num_philos)
{
    t_philo *philos;
    int     i;

    philos = (t_philo*) malloc (sizeof(t_philo) * num_philos);
    if (philos == NULL)
        return (NULL);
    i = 0;
    while (i < num_philos)
    {
        if (pthread_create(&philos[i].thread, NULL, &routine, NULL) != 0)
            perror("Failed to create thread.\n");
        philos[i].number = i + 1;
        printf("Thread %d has started\n", i);
        i++;
    }
    return (philos);
}


int	main(int argc, char **argv)
{
    t_philo *philos;
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
    philos = initialize_philos(num_philos);
    
    philo_eat(philos[1]);
    philo_think(philos[3]);
    philo_sleep(philos[2]);
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
