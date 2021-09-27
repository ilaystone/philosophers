/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 11:06:58 by ikhadem           #+#    #+#             */
/*   Updated: 2021/09/27 09:39:45 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>

typedef struct	s_game_rules
{
	int			number_of_philosophers;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			number_of_times_to_eats;
}	t_game_rules;

typedef struct		s_game
{
	t_game_rules		rules;
	pthread_t			*philosophers;
	pthread_mutex_t		*forks;
}	t_game;

/*************
** ft_utils **
*************/

int		ft_isdigit(int c);
int		ft_isspace(int c);
int		ft_atoi(const char *str);
int		ft_strisdigit(char *str);

int		philo_parse_args(int ac, char **av, t_game_rules *r);
int		simulation_start(t_game_rules rules);

#endif