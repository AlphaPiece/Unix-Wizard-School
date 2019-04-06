# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zwang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/27 16:03:21 by zwang             #+#    #+#              #
#    Updated: 2019/04/06 19:19:37 by Zexi Wang        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/minishell.c srcs/receive.c srcs/echo.c srcs/cd.c \
	   srcs/env.c srcs/execute.c
LIBS = libs//libft/libft.a
INCS = -I incs -I libs/libft/incs

all: $(NAME)

$(NAME):
	@$(CC) -o $(NAME) $(CFLAGS) $(SRCS) $(LIBS) $(INCS)

fclean:
	@rm -rf $(NAME)

re: fclean all
