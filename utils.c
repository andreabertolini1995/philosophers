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

double  get_timestamp()
{
    struct timeval  current_time;
    double          time_in_ms;

    gettimeofday(&current_time, NULL);
    time_in_ms = (current_time.tv_sec) * 1000 + (current_time.tv_usec) / 1000;
    // printf("seconds : %f\n", time_in_ms);
    return (time_in_ms);
}
