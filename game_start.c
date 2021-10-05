/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 09:55:26 by ikhadem           #+#    #+#             */
/*   Updated: 2021/10/05 18:31:44 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int		check_death(t_philosopher *self)
{
	uint64_t		time;

	time = get_time();
	return (time - self->last_time_eaten < self->rules.time_to_die ? 1 : 0);
}

int	game_start(t_game *game)
{
	int		i;

	while (1)
	{
		i = 0;
		while (i < game->number_of_philosophers)
		{
			pthread_mutex_lock(&game->philosophers[i].death_lock);
			if (!check_death(&game->philosophers[i]))
			{
				print_msg(&game->philosophers[i], "died");
				return (0);
			}
			pthread_mutex_unlock(&game->philosophers[i].death_lock);
			i++;
		}
	}
	return (1);
}
