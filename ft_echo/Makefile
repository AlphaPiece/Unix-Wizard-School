# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zwang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/13 10:16:01 by zwang             #+#    #+#              #
#    Updated: 2018/10/13 21:08:55 by zwang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_echo
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_echo.c

all: $(NAME)

$(NAME):
	@$(CC) -o $(NAME) $(CFLAGS) $(SRCS)

fclean:
	@rm -rf $(NAME)

re: fclean all
