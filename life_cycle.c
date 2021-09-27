/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:45:44 by ikhadem           #+#    #+#             */
/*   Updated: 2021/09/27 16:12:18 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	philo_eating(t_philosopher *self)
{
	(void)self;
	struct	timeval current_time;
	gettimeofday(&current_time, NULL);
	printf("id: %d eating time: %lld\n",self->id,
			current_time.tv_sec*(uint64_t)1000000+current_time.tv_usec);
	sleep(2);
}

// static void	philo_sleeping(t_philosopher *self)
// {
// 	(void)self;
// 	printf("philo is sleeping\n");
// }

// static void	philo_thinking(t_philosopher *self)
// {
// 	(void)self;
// 	printf("philo is thinking\n");
// }


void	*life_cycle(void *data)
{
	t_philosopher *self;

	self = data;
	while (1)
	{
		philo_eating(self);
		// philo_sleeping(self);
		// philo_thinking(self);
	}
	return (data);
}
