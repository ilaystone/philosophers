/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 09:55:26 by ikhadem           #+#    #+#             */
/*   Updated: 2021/10/18 14:45:16 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	check_death(t_philosopher *self)
{
	uint64_t		time;

	time = get_time();
	if (time - self->last_time_eaten - self->acc_loss_time < \
		self->rules.time_to_die)
		return (1);
	pthread_mutex_lock(self->logger_lock);
		printf("%-3llu ms %-3d died\n",
		time_stamp(self->launch_time),
		self->id);
	return (0);
}

int	game_start(t_game *game)
{
	int		i;
	int		count;
	uint64_t		lost_time;

	while (1)
	{
		i = 0;
		count = 0;
		while (i < game->number_of_philosophers)
		{
			pthread_mutex_lock(&game->philosophers[i].death_lock);
			lost_time = get_time();
			if (!check_death(&game->philosophers[i]))
				return (0);
			count += game->philosophers[i].times_eaten;
			pthread_mutex_unlock(&game->philosophers[i].death_lock);
			game->philosophers[i].acc_loss_time = time_stamp(lost_time);
			i++;
		}
		if (count == \
			(game->number_of_philosophers * \
			game->rules->number_of_times_to_eats))
			return (1);
	}
	return (1);
}
