/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:42:44 by ikhadem           #+#    #+#             */
/*   Updated: 2021/10/18 14:48:26 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_msg(t_philosopher *self, char *msg)
{
	uint64_t		lost_time;

	lost_time = get_time();
	pthread_mutex_lock(self->logger_lock);
	self->last_time_eaten += time_stamp(lost_time);
	printf("%-3llu ms %-3d %s\n",
		time_stamp(self->launch_time),
		self->id,
		msg);
	pthread_mutex_unlock(self->logger_lock);
}
