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
    printf("Philo is created.");
    return (NULL);
}

int	main(int argc, char **argv)
{
    pthread_t   *philosophers;
    int         num_philos;
    int         i;
    
    num_philos = atoi(argv[0]);
    philosophers = (pthread_t*) malloc (sizeof(pthread_t));
    if (philosophers == NULL)
        return (1);
    i = 0;
    while (i < num_philos)
    {
        if (pthread_create(&philosophers[i], NULL, &routine, NULL) != 0)
        {
            perror("Failed to create thread.\n");
            return (1);
        }
        printf("Thread %d has started\n", i);
    }
    while (i < num_philos)
    {
        if (pthread_join(philosophers[i], NULL) != 0)
            return (1);
        printf("Thread %d has finished execution\n", i);
    }
    (void) argc;
	return (0);
}
