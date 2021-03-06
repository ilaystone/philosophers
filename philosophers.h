/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 11:06:58 by ikhadem           #+#    #+#             */
/*   Updated: 2021/10/20 08:32:10 by ikhadem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_game_rules
{
	int					number_of_philosophers;
	int					number_of_times_to_eats;
	uint64_t			time_to_die;
	uint64_t			time_to_eat;
	uint64_t			time_to_sleep;
}	t_game_rules;

typedef struct s_fork
{
	int					id;
	pthread_mutex_t		lock;
}	t_fork;

typedef struct s_philosopher
{
	int					id;
	int					times_eaten;
	pthread_mutex_t		death_lock;
	pthread_mutex_t		*logger_lock;
	uint64_t			last_time_eaten;
	uint64_t			launch_time;
	pthread_t			t;
	t_fork				*right_fork;
	t_fork				*left_fork;
	t_game_rules		rules;
}	t_philosopher;

typedef struct s_game
{
	int					number_of_philosophers;
	t_game_rules		*rules;
	t_philosopher		*philosophers;
	pthread_mutex_t		logger_lock;
	t_fork				*forks;
}	t_game;

/*************
** ft_utils **
*************/

int				ft_isdigit(int c);
int				ft_isspace(int c);
int				ft_atoi(const char *str);
int				ft_strisdigit(char *str);

int				philo_parse_args(int ac, char **av, t_game_rules *r);
int				simulation_start(t_game_rules *rules);
int				game_init(t_game *game, t_game_rules *rules);
int				game_start(t_game *game);
void			game_destroy(t_game *game);
void			*life_cycle(void *data);
int				philo_eating(t_philosopher *self);

uint64_t		get_time(void);
uint64_t		time_stamp(uint64_t prev);
void			print_msg(t_philosopher *self, char *msg);

#endif