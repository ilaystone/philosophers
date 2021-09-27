/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:45:44 by ikhadem           #+#    #+#             */
/*   Updated: 2021/09/27 13:01:00 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	philo_eating(t_game *game)
{
	pthread_mutex_lock(game->forks[game->])
}

static void	philo_sleeping(t_game *game)
{
	printf("philo is sleeping\n");
}

static void	philo_thinking(t_game *game)
{
	printf("philo is thinking\n");
}


void	*life_cycle(void *data)
{
	t_game	*game;

	game = (t_game *)data;
	while (1)
	{
		philo_eating(game);
		philo_sleeping(game);
		philo_thinking(game);
	}
}
