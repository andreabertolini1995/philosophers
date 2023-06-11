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

extern long int g_start_time;

void    philo_eat(t_philo *philo)
{
    long int  current_timestamp;
    
    if (philo->num_forks == 2)
    {
        philo->state = eating;
        current_timestamp = get_timestamp();
        printf("%ld %d is eating\n", current_timestamp - g_start_time, philo->number);
    }
    usleep((philo->time_to_eat) * 1000);
    philo->time_last_meal = get_timestamp();
    philo->num_forks = 0;
}

void    philo_sleep(t_philo *philo)
{
    long int  current_timestamp;

    if (philo->state == eating)
    {
        philo->state = sleeping;
        current_timestamp = get_timestamp();
        printf("%ld %d is sleeping\n", current_timestamp - g_start_time, philo->number);
        usleep((philo->time_to_sleep) * 1000);
    }
}

void    philo_think(t_philo *philo)
{
    long int  current_timestamp;
    
    if (philo->state == eating)
    {
        philo->state = thinking;
        current_timestamp = get_timestamp();
        printf("%ld %d is thinking\n", current_timestamp - g_start_time, philo->number);
    }
}

void    philo_take_fork(t_philo *philo, char *side)
{    
    if (!ft_strncmp(side, "left", ft_strlen(side)))
    {
        if (philo->left_fork == available)
        {
            philo->left_fork = taken;
            philo->next->right_fork = taken;
            philo->num_forks++;
            printf("%ld %d has taken its left fork\n", get_timestamp() - g_start_time, philo->number);
        }
    }
    else
    {
        if (philo->right_fork == available)
        {
            philo->right_fork = taken;
            philo->prev->left_fork = taken;
            philo->num_forks++;
            printf("%ld %d has taken its right fork\n", get_timestamp() - g_start_time, philo->number);
        }
    }
}

void    philo_die(t_philo *philo)
{
    long int  current_timestamp;
    
    philo->state = dead;
    current_timestamp = get_timestamp();
    printf("%ld %d died\n", current_timestamp - g_start_time, philo->number);
}
