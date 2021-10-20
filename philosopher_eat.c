/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_eat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:36:11 by ikhadem           #+#    #+#             */
/*   Updated: 2021/10/20 08:26:36 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philo_eating(t_philosopher *self)
{
	pthread_mutex_lock(&self->right_fork->lock);
	print_msg(self, "has taken fork");
	pthread_mutex_lock(&self->left_fork->lock);
	print_msg(self, "has taken fork");
	print_msg(self, "is eating");
	pthread_mutex_lock(&self->death_lock);
	self->last_time_eaten = get_time();
	if (self->rules.number_of_times_to_eats != -1)
		self->times_eaten += 1;
	pthread_mutex_unlock(&self->death_lock);
	usleep(self->rules.time_to_eat);
	pthread_mutex_unlock(&self->left_fork->lock);
	pthread_mutex_unlock(&self->right_fork->lock);
	return (1);
}
