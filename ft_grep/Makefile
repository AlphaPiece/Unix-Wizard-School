# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zwang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/13 10:59:47 by zwang             #+#    #+#              #
#    Updated: 2018/10/13 15:52:44 by zwang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_grep
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_grep.c
LIBS = libft.a

all: $(NAME)

$(NAME):
	@$(CC) -o $(NAME) $(CFLAGS) $(SRCS) $(LIBS)

fclean:
	@rm -rf $(NAME)

re: fclean all
