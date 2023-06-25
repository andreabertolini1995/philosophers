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

long int	get_current_time(void)
{
	struct timeval	current_time;
	long int		time_in_ms;

	gettimeofday(&current_time, NULL);
	time_in_ms = (current_time.tv_sec) * 1000 + (current_time.tv_usec) / 1000;
	return (time_in_ms);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	i = 0;
	while ((str1[i] != '\0' || str2[i] != '\0') && i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	count;

	if (str == NULL)
		return (0);
	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	final_number;
	int	i;

	sign = 1;
	final_number = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
			i++;
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				sign = -1;
			i++;
		}
		while ((str[i] >= '0') && (str[i] <= '9'))
		{
			final_number = final_number * 10 + (str[i] - 48);
			i++;
		}
		return (final_number * sign);
	}
	return (final_number * sign);
}

int	error(char *str)
{
	printf("%s\n", str);
	return (1);
}
