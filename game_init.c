/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 09:42:47 by ikhadem           #+#    #+#             */
/*   Updated: 2021/09/27 13:05:09 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	error_init(t_game *game)
{
	free(game->philosophers);
	free(game->forks);
	return (0);
}

static int	init_philosophers(t_game *game)
{
	int		i;

	i = 0;
	while (i < game->rules.number_of_philosophers)
	{
		game->philosophers[i].id = i;
		if (pthread_create(game->philosophers[i].t,
							NULL, &life_cycle, (void *)game) != 0)
			return (0);
		i++;
	}
	return (1);
}

static int	init_forks(t_game *game)
{
	int		i;

	i = 0;
	while (i < game->rules.number_of_philosophers)
	{
		if (pthread_mutex_init(&game->forks[i], NULL) != 0)
			return (0);
		game->philosophers[i].right_fork = \
			&game->forks[i % game->rules.number_of_philosophers];
		game->philosophers[i].left_fork = \
			&game->forks[(i + 1) % game->rules.number_of_philosophers];
		i++;
	}
	return (1);
}

int	game_init(t_game *game, t_game_rules rules)
{
	game->rules = rules;
	game->philosophers = (t_philosopher *)malloc(sizeof(t_philosopher));
	if (!game->philosophers)
		return (0);
	game->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!game->forks)
	{
		free(game->philosophers);
		return (0);
	}
	if (!init_philosophers(game))
		return (error_init(game));
	if (!init_forks(game))
		return (error_init(game));
	return (1);
}
