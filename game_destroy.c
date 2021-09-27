/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:50:47 by ikhadem           #+#    #+#             */
/*   Updated: 2021/09/27 14:51:09 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	game_destroy(t_game *game)
{
	int		i;

	free(game->philosophers);
	i = 0;
	while (i < game->number_of_philosophers)
	{
		pthread_mutex_destroy(&game->forks[i]);
		i++;
	}
	free(game->forks);
}
