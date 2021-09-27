/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 09:37:35 by ikhadem           #+#    #+#             */
/*   Updated: 2021/09/27 11:22:18 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	simulation_start(t_game_rules rules)
{
	t_game		game;

	if (!game_init(&game, rules))
		return (0);
	game_start(&game);
	game_destroy(&game);
	return (1);
}
