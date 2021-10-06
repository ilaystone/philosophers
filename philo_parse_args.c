/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parse_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 08:08:48 by ikhadem           #+#    #+#             */
/*   Updated: 2021/10/06 12:55:49 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	set_args_four(char **av, t_game_rules *r)
{
	int		i;

	i = 1;
	while (i < 5)
	{
		if (!ft_strisdigit(av[i]))
			return (0);
		i++;
	}
	r->number_of_philosophers = ft_atoi(av[1]);
	r->time_to_die = ft_atoi(av[2]);
	r->time_to_eat = ft_atoi(av[3]) * 1000;
	r->time_to_sleep = ft_atoi(av[4]) * 1000;
	r->number_of_times_to_eats = -1;
	return (1);
}

static int	set_args_five(char **av, t_game_rules *r)
{
	int		i;

	i = 1;
	while (i < 6)
	{
		if (!ft_strisdigit(av[i]))
			return (0);
		i++;
	}
	r->number_of_philosophers = ft_atoi(av[1]);
	r->time_to_die = ft_atoi(av[2]);
	r->time_to_eat = ft_atoi(av[3]) * 1000;
	r->time_to_sleep = ft_atoi(av[4]) * 1000;
	r->number_of_times_to_eats = ft_atoi(av[5]);
	return (1);
}

int	philo_parse_args(int ac, char **av, t_game_rules *r)
{
	if (ac == 5)
	{
		if (!set_args_four(av, r))
			return (0);
	}
	else if (ac == 6)
	{
		if (!set_args_five(av, r))
			return (0);
	}
	return (1);
}
