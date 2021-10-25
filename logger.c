/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:42:44 by ikhadem           #+#    #+#             */
/*   Updated: 2021/10/25 14:25:16 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_msg(t_philosopher *self, char *msg)
{
	pthread_mutex_lock(self->logger_lock);
	printf("%-3llu ms %-3d %s\n",
		time_stamp(self->launch_time),
		self->id,
		msg);
	pthread_mutex_unlock(self->logger_lock);
}
