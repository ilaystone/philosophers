/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:45:44 by ikhadem           #+#    #+#             */
/*   Updated: 2021/10/05 17:38:57 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	philo_sleeping(t_philosopher *self)
{
	printf("%-3lld ms %d is sleeping\n", time_stamp(self->launch_time), self->id);
	usleep(self->rules.time_to_sleep);
}

static void	philo_thinking(t_philosopher *self)
{
	printf("%-3lld ms %d is thinking\n", time_stamp(self->launch_time), self->id);
}

void	*life_cycle(void *data)
{
	t_philosopher *self;

	self = (t_philosopher *)data;
	while (1)
	{
		philo_eating(self);
		philo_sleeping(self);
		philo_thinking(self);
	}
	return (NULL);
}
