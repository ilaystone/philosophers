/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 09:42:47 by ikhadem           #+#    #+#             */
/*   Updated: 2021/10/19 11:18:27 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	error_init(t_game *game)
{
	int		i;

	i = 0;
	while (i < game->number_of_philosophers)
	{
		pthread_mutex_destroy(&game->forks[i].lock);
		pthread_mutex_destroy(&game->philosophers[i].death_lock);
		i++;
	}
	pthread_mutex_destroy(&game->logger_lock);
	if (game->philosophers)
		free(game->philosophers);
	if (game->forks)
		free(game->forks);
	return (0);
}

static int	init_philosophers(t_game *game, t_game_rules rules, uint64_t l)
{
	int			i;

	i = 0;
	(void)l;
	while (i < game->number_of_philosophers)
	{
		game->philosophers[i].id = i + 1;
		game->philosophers[i].rules = rules;
		game->philosophers[i].launch_time = get_time();
		game->philosophers[i].logger_lock = &game->logger_lock;
		if (pthread_mutex_init(&game->philosophers[i].death_lock, NULL) != 0)
			return (0);
		game->philosophers[i].last_time_eaten = get_time();
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
		if (i % 2 == 0)
			game->forks[i].state = FORK_DIRTY;
		else
			game->forks[i].state = FORK_CLEAN;
		game->forks[i].id = i + 1;
		if (pthread_mutex_init(&game->forks[i].lock, NULL) != 0)
			return (0);
		i++;
	}
	if (pthread_mutex_init(&game->logger_lock, NULL) != 0)
		return (0);
	return (1);
}

static void	set_forks(t_game *game)
{
	int		i;
	int		nbr;

	i = 0;
	nbr = game->number_of_philosophers;
	while (i < game->number_of_philosophers)
	{
		game->philosophers[i].right_fork = &game->forks[i];
		game->philosophers[i].left_fork = &game->forks[(i + 1) % nbr];
		i++;
	}
}

int	game_init(t_game *game, t_game_rules *rules)
{
	int		nbr;

	nbr = rules->number_of_philosophers;
	game->number_of_philosophers = nbr;
	game->rules = rules;
	game->philosophers = (t_philosopher *)malloc(sizeof(t_philosopher) * nbr);
	game->forks = (t_fork *)malloc(sizeof(t_fork) * nbr);
	if (!game->philosophers || !game->forks)
		return (error_init(game));
	if (!init_forks(game))
		return (error_init(game));
	set_forks(game);
	if (!init_philosophers(game, *rules, get_time()))
		return (error_init(game));
	return (1);
}
