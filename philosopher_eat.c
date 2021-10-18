
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_eat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:36:11 by ikhadem           #+#    #+#             */
/*   Updated: 2021/10/18 09:39:37 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	lock_owned(t_philosopher *self)
{
	while (1)
	{
		pthread_mutex_lock(&self->right_fork->lock);
		if (self->right_fork->state == FORK_DIRTY)
		{
			self->right_fork->state = FORK_INUSE;
			pthread_mutex_unlock(&self->right_fork->lock);
			break ;
		}
		pthread_mutex_unlock(&self->right_fork->lock);
	}
	print_msg(self, "has taken a fork");
}

static void	lock_neighbor(t_philosopher *self)
{
	while (1)
	{
		pthread_mutex_lock(&self->left_fork->lock);
		if (self->left_fork->state == FORK_CLEAN)
		{
			self->left_fork->state = FORK_INUSE;
			pthread_mutex_unlock(&self->left_fork->lock);
			break ;
		}
		pthread_mutex_unlock(&self->left_fork->lock);
	}
	print_msg(self, "has taken a fork");
}

static void	set_forks(t_philosopher *self)
{
	pthread_mutex_lock(&self->right_fork->lock);
	self->right_fork->state = FORK_CLEAN;
	pthread_mutex_unlock(&self->right_fork->lock);
	pthread_mutex_lock(&self->left_fork->lock);
	self->left_fork->state = FORK_DIRTY;
	pthread_mutex_unlock(&self->left_fork->lock);
}

int	philo_eating(t_philosopher *self)
{
	lock_owned(self);
	lock_neighbor(self);
	print_msg(self, "is eating");
	pthread_mutex_lock(&self->death_lock);
	self->last_time_eaten = get_time();
	usleep(self->rules.time_to_eat);
	if (self->rules.number_of_times_to_eats != -1)
		self->times_eaten++;
	pthread_mutex_unlock(&self->death_lock);
	set_forks(self);
	return (1);
}
