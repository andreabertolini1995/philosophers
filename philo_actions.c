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

void    philo_eat(t_philo philo)
{
    double  current_timestamp;
    
    if (philo.forks == 2)
    {
        philo.state.eating = true;
        current_timestamp = get_timestamp();
        printf("%f %d is eating\n", current_timestamp, philo.number);
    }
}

void    philo_sleep(t_philo philo)
{
    double  current_timestamp;
    
    philo.state.sleeping = true;
    current_timestamp = get_timestamp();
    printf("%f %d is sleeping\n", current_timestamp, philo.number);
}

void    philo_think(t_philo philo)
{
    double  current_timestamp;
    
    philo.state.thinking = true;
    current_timestamp = get_timestamp();
    printf("%f %d is thinking\n", current_timestamp, philo.number);
}

void    philo_fork(t_philo philo)
{
    double  current_timestamp;
    
    philo.forks++;
    current_timestamp = get_timestamp();
    printf("%f %d has taken a fork\n", current_timestamp, philo.number);
}

void    philo_die(t_philo philo)
{
    double  current_timestamp;
    
    philo.state.death = true;
    current_timestamp = get_timestamp();
    printf("%f %d died\n", current_timestamp, philo.number);
}