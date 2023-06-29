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

int	check_input(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
	{
		printf("Too many or too few arguments provided.\n");
		return (1);
	}
	if (ft_atoi(argv[1]) < 1)
	{
		printf("There should be at least one philosopher.\n");
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		if (!ft_str_is_numeric(argv[i]))
		{
			printf("All the arguments must be a positive integer.\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_dining		*dining;

	if (check_input(argc, argv) == 1)
		return (1);
	dining = initialize_dining_data(argc, argv);
	terminate_threads(dining);
	destroy_mutexes(dining);
	free_data(dining);
	return (0);
}
