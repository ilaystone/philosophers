/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilay <ilay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 09:42:47 by ikhadem           #+#    #+#             */
/*   Updated: 2021/09/28 01:45:39 by ilay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	error_init(t_game *game)
{
	free(game->philosophers);
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
		game->philosophers[i].last_time_eaten = 0;
		if (pthread_create(&game->philosophers[i].t,
							NULL,
							&life_cycle,
							&(game->philosophers[i])) != 0)
			return (0);
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
	if (!game->philosophers)
		return (0);
	game->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * nbr);
	if (!game->forks)
	{
		free(game->philosophers);
		return (0);
	}
	if (!init_forks(game))
		return (error_init(game));
	set_forks(game);
	if (!init_philosophers(game, rules))
		return (error_init(game));
	// for (int i = 0; i < rules.number_of_philosophers; i++)
	// 	printf("fork %d add %p\n", i, &game->forks[i]);
	// for (int i = 0; i < rules.number_of_philosophers; i++)
	// 	printf ("philo[%d] right: \'%p\' left: \'%p\'\n", i,
	// 		game->philosophers[i].right_fork,
	// 		game->philosophers[i].left_fork);
	return (1);
}
