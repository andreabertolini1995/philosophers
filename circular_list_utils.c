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

t_philo	*new_philo(int philo_number, double time_to_die,
				double time_to_eat, double time_to_sleep)
{
	t_philo	*tmp;

	tmp = (t_philo*) malloc (sizeof(t_philo));
	if (tmp == NULL)
		return (NULL);
	tmp->number = philo_number;
	tmp->next = NULL;
	tmp->prev = NULL;
	tmp->left_fork = available;
	tmp->right_fork = available;
	tmp->num_forks = 0;
	tmp->time_to_die = time_to_die;
	tmp->time_to_eat = time_to_eat;
	tmp->time_to_sleep = time_to_sleep;
	if (pthread_mutex_init(&tmp->mutex, NULL) != 0)
    {
        printf("Failed to initialize the mutex.\n");
    }
	if (pthread_create(&tmp->thread, NULL, &routine, tmp) != 0)
	{
		perror("Failed to create thread.\n");
	}
	//printf("Thread %d has started\n", philo_number);
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
		new->prev = last_node;
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
