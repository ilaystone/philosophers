# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/24 09:59:25 by ikhadem           #+#    #+#              #
#    Updated: 2021/10/18 11:24:02 by ikhadem          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN		=	\e[38;5;118m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]

NAME := philo

SRC :=	main.c \
		philo_parse_args.c \
		ft_utils.c \
		simulation.c \
		game_init.c \
		game_start.c \
		life_cycle.c \
		game_destroy.c \
		philosopher_eat.c \
		custom_time.c \
		logger.c \

OBJ := $(SRC:.c=.o)

CC = gcc
FLAG = -g -Wall -Wextra -Werror -pthread
HDR = philosophers.h

%.o : %.c $(HDR)
	@$(CC) $(FLAG) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(FLAG) $(OBJ) -o $(NAME)
	@printf "$(_SUCCESS) $(NAME) is ready!.\n"

clean :
	@rm -f $(OBJ)
	@printf "$(_SUCCESS) $(NAME)_objects removed!.\n"

fclean :
	@rm -f $(NAME) $(OBJ)
	@printf "$(_SUCCESS) $(NAME) removed!.\n"

re : fclean all

.PHONY : all clean fclean re