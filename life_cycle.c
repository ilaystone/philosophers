/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:45:44 by ikhadem           #+#    #+#             */
/*   Updated: 2021/09/27 11:23:32 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	philo_eating()
{

}

static void	philo_sleeping()
{

}

static void	philo_thinking()
{

}


void	*life_cycle(void *data)
{
	(void)data;
	printf("startiing philo\n");
	while (1)
	{
		philo_eating();
		philo_sleeping();
		philo_thinking();
		// orchestrator_check_death();
	}
}
