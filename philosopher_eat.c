/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_eat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:36:11 by ikhadem           #+#    #+#             */
/*   Updated: 2021/09/28 16:08:53 by ikhadem          ###   ########.fr       */
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

void	philo_eating(t_philosopher *self)
{
	pthread_mutex_t		*lowest;
	pthread_mutex_t		*highest;

	lowest = lowest_value_fork(self);
	highest = highest_value_fork(self);
	pthread_mutex_lock(lowest);
	printf("%d has taken a fork lowest\n", self->id + 1);
	pthread_mutex_lock(highest);
	printf("%d has taken a fork highest\n", self->id + 1);
	printf("%d is eating\n", self->id + 1);
	sleep(1);
	pthread_mutex_unlock(highest);
	pthread_mutex_unlock(lowest);
}
