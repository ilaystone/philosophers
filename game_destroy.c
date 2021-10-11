/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:50:47 by ikhadem           #+#    #+#             */
/*   Updated: 2021/10/11 13:38:07 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	game_destroy(t_game *game)
{
	int		i;

	i = 0;
	while (i < game->number_of_philosophers)
	{
		pthread_mutex_destroy(&game->forks[i].lock);
		pthread_detach(game->philosophers[i].t);
		i++;
	}
	pthread_mutex_destroy(&game->logger_lock);
	if (game->philosophers)
		free(game->philosophers);
	if (game->forks)
		free(game->forks);
}
