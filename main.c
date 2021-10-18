/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 11:06:38 by ikhadem           #+#    #+#             */
/*   Updated: 2021/10/18 11:13:24 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_game_rules	rules;

	if (ac == 5 || ac == 6)
	{
		if (!philo_parse_args(ac, av, &rules))
		{
			write(2, "Error: parsing\n", 15);
			return (1);
		}
		if (!simulation_start(&rules))
		{
			write(2, "Error: starting simulation\n", 27);
			return (1);
		}
	}
	else
		write(2, "Error: number of arguments\n", 27);
	return (0);
}
