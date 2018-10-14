# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zwang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/13 22:13:25 by zwang             #+#    #+#              #
#    Updated: 2018/10/13 22:31:30 by zwang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_copy
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_copy.c

all: $(NAME)

$(NAME):
	@$(CC) -o $(NAME) $(CFLAGS) $(SRCS)

fclean:
	@rm -rf $(NAME)

re: fclean all
