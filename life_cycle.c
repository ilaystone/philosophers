/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilay <ilay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:45:44 by ikhadem           #+#    #+#             */
/*   Updated: 2021/09/28 01:51:18 by ilay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// static unsigned long	time_diff(struct timeval t1, struct timeval t2)
// {
// 	return ((t1.tv_sec * 1000000 + t1.tv_usec) - (t2.tv_sec * 1000000 + t2.tv_usec));
// }

static void	philo_eating(t_philosopher *self)
{
	// static int	count = 0;
	pthread_mutex_lock(self->right_fork);
	pthread_mutex_lock(self->left_fork);
	printf("%d has taken a fork\n", self->id);
	printf("%d has taken a fork\n", self->id);
	usleep(200);
	printf("%d is eating\n", self->id);
	pthread_mutex_unlock(self->right_fork);
	pthread_mutex_unlock(self->left_fork);
	// count++;
	// if (count == 10)
	// 	exit(0);
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
