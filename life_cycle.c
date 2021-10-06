/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:45:44 by ikhadem           #+#    #+#             */
/*   Updated: 2021/10/06 12:31:15 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void philo_sleeping(t_philosopher *self)
{
	print_msg(self, "is sleeping");
	usleep(self->rules.time_to_sleep);
}

static void philo_thinking(t_philosopher *self)
{
	print_msg(self, "is thinking");
}

void *life_cycle(void *data)
{
	t_philosopher *self;

	self = (t_philosopher *)data;
	while (1)
	{
		if (self->times_eaten != self->rules.number_of_times_to_eats)
		{
			philo_eating(self);
			philo_sleeping(self);
			philo_thinking(self);
		}
	}
	return (NULL);
}
