/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_eat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:36:11 by ikhadem           #+#    #+#             */
/*   Updated: 2021/09/30 10:42:09 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static pthread_mutex_t	*lowest_value_fork(t_philosopher *self)
{
	int		left;
	int		right;

	left = self->id % self->rules.number_of_philosophers;
	right = (self->id + 1) % self->rules.number_of_philosophers;
	if (left < right)
		return (self->left_fork);
	return (self->right_fork);
}

static pthread_mutex_t	*highest_value_fork(t_philosopher *self)
{
	int		left;
	int		right;

	left = self->id % self->rules.number_of_philosophers;
	right = (self->id + 1) % self->rules.number_of_philosophers;
	if (left > right)
		return (self->left_fork);
	return (self->right_fork);
}

static int		check_death(t_philosopher *self)
{
	uint64_t		time;

	time = get_time();
	printf("%d is eating: %llu %llu\n", self->id + 1,
		time - self->last_time_eaten,
		self->rules.time_to_die);
	return (time - self->last_time_eaten < self->rules.time_to_die ? 1 : 0);
}

void	philo_eating(t_philosopher *self)
{
	pthread_mutex_t		*lowest;
	pthread_mutex_t		*highest;

	lowest = lowest_value_fork(self);
	highest = highest_value_fork(self);
	// if (self->fork_state == FORK_DIRTY)
	// {
	// 	usleep(self->rules.time_to_eat);
	// 	self->fork_state = FORK_CLEAN;
	// }
	pthread_mutex_lock(lowest);
	printf("%d has taken fork\n", self->id + 1);
	pthread_mutex_lock(highest);
	printf("%d has taken fork\n", self->id + 1);
	if (!check_death(self))
	{
		printf("%d has died\n", self->id + 1);
		exit(EXIT_FAILURE);
	}
	// printf("%d is eating\n", self->id + 1);
	self->last_time_eaten = get_time();
	usleep(self->rules.time_to_eat * 1000);
	pthread_mutex_unlock(lowest);
	pthread_mutex_unlock(highest);
	self->fork_state = FORK_DIRTY;
}
