/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:42:44 by ikhadem           #+#    #+#             */
/*   Updated: 2021/10/05 14:04:29 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int		check_death(t_philosopher *self)
{
	uint64_t		time;

	time = get_time();
	return (time - self->last_time_eaten < self->rules.time_to_die ? 1 : 0);
}

static void	*monitor(void *data)
{
	t_game	*g;
	int		i;

	g = (t_game *)data;
	while (1)
	{
		i = 0;
		while (i < g->number_of_philosophers)
		{
			pthread_mutex_lock(&g->philosophers[i].death_lock);
			if (!check_death(&g->philosophers[i]))
			{
				printf("%3llu ms %d died\n", time_stamp(g->philosophers[i].last_time_eaten), i + 1);
				return (NULL);
			}
			pthread_mutex_unlock(&g->philosophers[i].death_lock);
			i++;
		}
	}
	return (NULL);
}

int		start_monitor(t_game *game)
{
	if (pthread_create(&game->monitor, NULL, &monitor, game) != 0)
		return (0);
	return (1);
}
