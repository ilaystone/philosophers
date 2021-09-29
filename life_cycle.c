/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:45:44 by ikhadem           #+#    #+#             */
/*   Updated: 2021/09/29 14:34:37 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	philo_sleeping(t_philosopher *self)
{
	printf("%d is sleeping\n", self->id + 1);
	usleep(self->rules.time_to_sleep * 1000);
}

static void	philo_thinking(t_philosopher *self)
{
	printf("%d is thinking\n", self->id + 1);
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
