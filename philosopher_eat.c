/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_eat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:36:11 by ikhadem           #+#    #+#             */
/*   Updated: 2021/10/05 10:43:38 by ikhadem          ###   ########.fr       */
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
		pthread_mutex_lock(&self->owned_fork->lock);
		if (self->right_fork->state == FORK_OPEN)
		{
			printf("%-3lld ms %d has taken a fork\n", time_stamp(self->launch_time), self->id);
			self->owned_fork->state = FORK_INUSE;
			pthread_mutex_lock(&self->left_fork->lock);
			printf("%-3lld ms %d has taken a fork\n", time_stamp(self->launch_time), self->id);
			if (!check_death(self))
			{
				printf("%-3lld ms %d died\n", time_stamp(self->launch_time), self->id);
				exit (1);
			}
			self->last_time_eaten = get_time();
			printf("%-3lld ms %d is eating\n", time_stamp(self->launch_time), self->id);
			usleep(self->rules.time_to_eat * 1000);
			self->owned_fork->state = FORK_OPEN;
			pthread_mutex_unlock(&self->left_fork->lock);
			pthread_mutex_unlock(&self->owned_fork->lock);
			return (1);
		}
		pthread_mutex_unlock(&self->owned_fork->lock);
	}
	return (0);
}
