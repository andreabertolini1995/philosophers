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

t_philo	*last_philo(t_philo *lst)
{
	t_philo	*last_node;

	if (lst == NULL)
		last_node = NULL;
	while (lst != NULL)
	{
		last_node = lst;
		lst = lst->next;
	}
	return (last_node);
}

t_philo	*new_philo(int philo_number)
{
	t_philo	*tmp;

	tmp = malloc (sizeof(t_philo));
	if (tmp == NULL)
		return (NULL);
    if (pthread_create(&tmp->thread, NULL, &routine, NULL) != 0)
	{
		perror("Failed to create thread.\n");
	}
	tmp->number = philo_number;
    printf("Thread %d has started\n", philo_number);
	tmp->next = NULL;
	return (tmp);
}

void	add_philo(t_philo **lst, t_philo *new)
{
	t_philo	*last_node;

	if ((*lst) == NULL)
	{
		new->next = NULL;
		*lst = new;
	}
	else
	{
		last_node = last_philo(*lst);
		last_node->next = new;
	}
}

int	get_list_size(t_philo *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
