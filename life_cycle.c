/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:45:44 by ikhadem           #+#    #+#             */
/*   Updated: 2021/10/04 12:53:51 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	philo_sleeping(t_philosopher *self)
{
	printf("%3lld ms %3d is sleeping\n", time_stamp(self->launch_time), self->id);
	usleep(self->rules.time_to_sleep * 1000);
}

static void	philo_thinking(t_philosopher *self)
{
	printf("%3lld ms %3d is thinking\n", time_stamp(self->launch_time), self->id);
}

void	*life_cycle(void *data)
{
	t_philosopher *self;

	self = (t_philosopher *)data;
	while (1)
	{
		if (!philo_eating(self))
			break ;
		philo_sleeping(self);
		philo_thinking(self);
		if (self->rules.number_of_times_to_eats != -1 &&
			self->times_eaten == self->rules.number_of_times_to_eats)
			break;
	}
	return (NULL);
}
