/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 09:37:35 by ikhadem           #+#    #+#             */
/*   Updated: 2021/10/25 16:34:59 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_sim_ended(t_game *game)
{
	int		i;

	i = 0;
	printf("sim ended on :\n");
	while (i < game->number_of_philosophers)
	{
		printf("\t%d has eaten %d times\n",
			game->philosophers[i].id,
			game->philosophers[i].times_eaten);
		i++;
	}
}

int	simulation_start(t_game_rules *rules)
{
	t_game		game;

	if (!game_init(&game, rules))
		return (0);
	if (game_start(&game) == 1)
		print_sim_ended(&game);
	game_destroy(&game);
	return (1);
}
