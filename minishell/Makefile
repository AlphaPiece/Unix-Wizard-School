# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zwang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/27 16:03:21 by zwang             #+#    #+#              #
#    Updated: 2018/10/27 16:21:56 by zwang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/minishell.c srcs/receive.c srcs/echo.c srcs/cd.c srcs/setenv.c \
	   srcs/unsetenv.c srcs/env.c srcs/exit.c srcs/error.c srcs/execute.c
LIBS = libs/libft.a
INCS = -I incs -I libs/libft_incs

all: $(NAME)

$(NAME):
	$(CC) -o $(NAME) $(CFLAGS) $(SRCS) $(LIBS) $(INCS)

fclean:
	rm -rf $(NAME)

re: fclean all
