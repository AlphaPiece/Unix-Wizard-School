# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/20 21:58:32 by Zexi Wang         #+#    #+#              #
#    Updated: 2019/03/20 21:59:51 by Zexi Wang        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_cal
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_cal.c

all: $(NAME)

$(NAME):
	@$(CC) -o $(NAME) $(CFLAGS) $(SRCS)

fclean:
	@rm -rf $(NAME)

re: fclean all
