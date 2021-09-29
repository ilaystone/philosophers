/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 09:42:47 by ikhadem           #+#    #+#             */
/*   Updated: 2021/09/29 14:13:56 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	error_init(t_game *game)
{
	if (game->philosophers)
		free(game->philosophers);
	if (game->forks)
		free(game->forks);
	return (0);
}

static int	init_philosophers(t_game *game, t_game_rules rules)
{
	int			i;

	i = 0;
	while (i < game->number_of_philosophers)
	{
		game->philosophers[i].id = i;
		game->philosophers[i].rules = rules;
		get_time(&(game->philosophers[i].last_time_eaten));
		if (pthread_create(&game->philosophers[i].t,
							NULL,
							&life_cycle,
							&(game->philosophers[i])) != 0)
			return (0);
		usleep(100);
		i++;
	}
	return (1);
}

static int	init_forks(t_game *game)
{
	int		i;

	i = 0;
	while (i < game->number_of_philosophers)
	{
		if (pthread_mutex_init(&game->forks[i], NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}

static void	set_forks(t_game *game)
{
	int		i;

	i = 0;
	while (i < game->number_of_philosophers)
	{
		game->philosophers[i].right_fork = \
			&game->forks[i % game->number_of_philosophers];
		game->philosophers[i].left_fork = \
			&game->forks[(i + 1) % game->number_of_philosophers];
		i++;
	}
}

int	game_init(t_game *game, t_game_rules rules)
{
	int		nbr;

	nbr = rules.number_of_philosophers;
	game->number_of_philosophers = nbr;
	game->philosophers = (t_philosopher *)malloc(sizeof(t_philosopher) * nbr);
	game->forks = \
		(pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * nbr);
	if (!game->philosophers || !game->forks)
		return (error_init(game));
	if (!init_forks(game))
		return (error_init(game));
	set_forks(game);
	if (!init_philosophers(game, rules))
		return (error_init(game));
	return (1);
}
