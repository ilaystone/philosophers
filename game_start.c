/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 09:55:26 by ikhadem           #+#    #+#             */
/*   Updated: 2021/10/11 13:59:25 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	check_death(t_philosopher *self)
{
	uint64_t		time;

	time = get_time();
	if (time - self->last_time_eaten < self->rules.time_to_die)
		return (1);
	pthread_mutex_lock(self->logger_lock);
		printf("%-3llu ms %-3d died\n",
		time_stamp(self->launch_time),
		self->id);
	return (0);
}

static int	number_of_times_eaten(t_game *game)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (i < game->number_of_philosophers)
	{
		if (game->philosophers[i].times_eaten == \
			game->philosophers[i].rules.number_of_times_to_eats)
			res++;
		i++;
	}
	return (res);
}

int	game_start(t_game *game, t_game_rules *rules)
{
	int		i;

	while (1)
	{
		i = 0;
		while (i < game->number_of_philosophers)
		{
			pthread_mutex_lock(&game->philosophers[i].death_lock);
			if (!check_death(&game->philosophers[i]))
				return (0);
			if (number_of_times_eaten(game) == game->number_of_philosophers)
			{
				pthread_mutex_lock(&game->logger_lock);
				printf("SIMULATION ENDED ON: %d times eaten\n",
						rules->number_of_times_to_eats);
				return (0);
			}
			pthread_mutex_unlock(&game->philosophers[i].death_lock);
			i++;
		}
	}
	return (1);
}
