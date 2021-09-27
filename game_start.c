/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 09:55:26 by ikhadem           #+#    #+#             */
/*   Updated: 2021/09/27 15:17:05 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	game_start(t_game *game)
{
	int		i;

	i = 0;
	while (i < game->number_of_philosophers)
	{
		// pthread_join(game->philosophers[i].t, NULL);
		printf("PHILO: %d ==> %d\n", game->philosophers[i].id, i);
		i++;
	}
	return (1);
}
