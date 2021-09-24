# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/24 09:59:25 by ikhadem           #+#    #+#              #
#    Updated: 2021/09/24 10:17:37 by ikhadem          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN		=	\e[38;5;118m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]

NAME := philosophers

SRC :=	main.c \

OBJ := $(SRC:.c=.o)

CC = gcc
FLAG = -Wall -Wextra -Werror
HDR = philosophers.h
LIB = -L./ft_utils/ -lutils
INCLUDE = -I. -I./ft_utils

%.o : %.c $(HDR)
	@$(CC) $(FLAG) $(INCLUDE) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	@cd ./ft_utils/ && make
	@$(CC) $(FLAG) $(INCLUDE) $(LIB) $(OBJ) -o $(NAME)
	@printf "$(_SUCCESS) $(NAME) is ready!.\n"

clean :
	@cd ./ft_utils/ && make clean
	@rm -f $(OBJ)
	@printf "$(_SUCCESS) $(NAME)_objects removed!.\n"

fclean :
	@cd ./ft_utils/ && make fclean
	@rm -f $(NAME) $(OBJ)
	@printf "$(_SUCCESS) $(NAME) removed!.\n"

re : fclean all

.PHONY : all clean fclean re