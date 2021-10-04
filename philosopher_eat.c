/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_eat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:36:11 by ikhadem           #+#    #+#             */
/*   Updated: 2021/10/04 12:58:33 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int		check_death(t_philosopher *self)
{
	uint64_t		time;

	time = get_time();
	return (time - self->last_time_eaten < self->rules.time_to_die ? 1 : 0);
}

int	philo_eating(t_philosopher *self)
{
	while (1)
	{
		if (!check_death(self))
		{
			printf("%3llu ms %d has died\n", time_stamp(self->launch_time), self->id);
			exit (1);
		}
		pthread_mutex_lock(&self->owned_fork->lock);
		if (self->owned_fork->state == FORK_CLEAN)
			pthread_mutex_unlock(&self->owned_fork->lock);
		else
			break ;
	}
	printf("%3llu ms %d has taken fork\n", time_stamp(self->launch_time), self->id);
	while (1)
	{
		if (!check_death(self))
		{
			printf("%3llu ms %d has died\n", time_stamp(self->launch_time), self->id);
			return (0);
		}
		pthread_mutex_lock(&self->rented_fork->lock);
		if (self->rented_fork->state == FORK_DIRTY)
			pthread_mutex_unlock(&self->rented_fork->lock);
		else
			break ;
	}
	printf("%3llu ms %d has taken fork\n", time_stamp(self->launch_time), self->id);
	printf("%3llu ms %d is eating\n", time_stamp(self->launch_time), self->id);
	usleep(self->rules.time_to_eat * 1000);
	self->last_time_eaten = get_time();
	self->rented_fork->state = FORK_DIRTY;
	self->owned_fork->state = FORK_CLEAN;
	pthread_mutex_unlock(&self->rented_fork->lock);
	pthread_mutex_unlock(&self->owned_fork->lock);
	return (1);
}
