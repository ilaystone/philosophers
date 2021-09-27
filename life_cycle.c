/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilay <ilay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:45:44 by ikhadem           #+#    #+#             */
/*   Updated: 2021/09/27 20:06:25 by ilay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static unsigned long	time_diff(struct timeval t1, struct timeval t2)
{
	return ((t1.tv_sec * 1000000 + t1.tv_usec) - (t2.tv_sec * 1000000 + t2.tv_usec));
}

static void	philo_eating(t_philosopher *self)
{
	(void)self;
	struct	timeval current_time;
	struct	timeval next_time;
	gettimeofday(&current_time, NULL);
	sleep(2);
	gettimeofday(&next_time, NULL);
	printf("id: %d eating time: %ld\n",self->id, time_diff(next_time, current_time) / 1000000);
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
