/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:50:47 by ikhadem           #+#    #+#             */
/*   Updated: 2021/10/04 09:31:37 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	game_destroy(t_game *game)
{
	int		i;

	i = 0;
	if (game->philosophers)
		free(game->philosophers);
	while (i < game->number_of_philosophers)
	{
		pthread_mutex_destroy(&game->forks[i].lock);
		i++;
	}
	if (game->forks)
		free(game->forks);
}
