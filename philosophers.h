/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 11:06:58 by ikhadem           #+#    #+#             */
/*   Updated: 2021/09/27 16:10:43 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_game_rules
{
	int			number_of_philosophers;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			number_of_times_to_eats; // = -1
}	t_game_rules;

typedef struct s_philosopher
{
	int				id;
	int				times_eaten;
	time_t			last_time_eaten;
	pthread_t		t;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	t_game_rules	rules;
}	t_philosopher;

typedef struct s_game
{
	int					number_of_philosophers;
	t_philosopher		*philosophers;
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
int		game_init(t_game *game, t_game_rules rules);
void	game_destroy(t_game *game);
void	*life_cycle(void *data);
int		game_start(t_game *game);

#endif