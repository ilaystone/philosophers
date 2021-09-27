/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilay <ilay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 09:55:26 by ikhadem           #+#    #+#             */
/*   Updated: 2021/09/27 18:42:32 by ilay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	game_start(t_game *game)
{
	int		i;

	i = 0;
	while (i < game->number_of_philosophers)
	{
		pthread_join(game->philosophers[i].t, NULL);
		i++;
	}
	return (1);
}
