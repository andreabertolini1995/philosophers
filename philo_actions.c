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

void    philo_eat(t_philo *philo)
{
    double  current_timestamp;
    
    if (philo->left_fork == taken && philo->right_fork == taken)
    {
        philo->state = eating;
        current_timestamp = get_timestamp();
        printf("%f %d is eating\n", current_timestamp, philo->number);
    }
    usleep(philo->time_to_eat/1000);
    philo->time_last_meal = get_timestamp();
}

void    philo_sleep(t_philo *philo)
{
    double  current_timestamp;
    
    philo->state = sleeping;
    current_timestamp = get_timestamp();
    printf("%f %d is sleeping\n", current_timestamp, philo->number);
    usleep(philo->time_to_sleep/1000);
}

void    philo_think(t_philo *philo)
{
    double  current_timestamp;
    
    philo->state = thinking;
    current_timestamp = get_timestamp();
    printf("%f %d is thinking\n", current_timestamp, philo->number);
}

void    philo_take_fork(t_philo *philo, char *side)
{    
    if (!ft_strncmp(side, "left", ft_strlen(side)))
    {
        if (philo->next->right_fork == available) // to change with mutexes
        {
            philo->left_fork = taken;
            printf("%f %d has taken a fork\n", get_timestamp(), philo->number);
        }
    }
    else
    {
        if (philo->next->left_fork == available)
        {
            philo->right_fork = taken;
            printf("%f %d has taken a fork\n", get_timestamp(), philo->number);
        }
    }
}

void    philo_die(t_philo *philo)
{
    double  current_timestamp;
    
    philo->state = dead;
    current_timestamp = get_timestamp();
    printf("%f %d died\n", current_timestamp, philo->number);
}
