/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_eat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:36:11 by ikhadem           #+#    #+#             */
/*   Updated: 2021/10/05 18:33:13 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	custom_try_lock(t_fork *fork)
{
	int		i;

	i = 0;
	while (1)
	{
		pthread_mutex_lock(&fork->lock);
		if (fork->state == FORK_OPEN)
		{
			fork->state = FORK_INUSE;
			i++;
		}
		pthread_mutex_unlock(&fork->lock);
		if (i != 0)
			return (1);
	}
	return (0);
}

int	custom_unlock_fork(t_fork *fork)
{
	pthread_mutex_lock(&fork->lock);
	fork->state = FORK_OPEN;
	pthread_mutex_unlock(&fork->lock);
	return (1);
}

int	philo_eating(t_philosopher *self)
{
	custom_try_lock(self->owned_fork);
	print_msg(self, "has taken a fork");
	custom_try_lock(self->left_fork);
	print_msg(self, "has taken a fork");
	print_msg(self, "is eating");
	pthread_mutex_lock(&self->death_lock);
	usleep(self->rules.time_to_eat);
	self->last_time_eaten = get_time();
	pthread_mutex_unlock(&self->death_lock);
	custom_unlock_fork(self->left_fork);
	custom_unlock_fork(self->owned_fork);
	return (1);
}
