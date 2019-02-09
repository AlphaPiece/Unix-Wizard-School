# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zwang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/10 14:18:06 by zwang             #+#    #+#              #
#    Updated: 2019/02/09 12:54:28 by Zexi Wang        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = libft.a

SRCS = srcs/handler.c srcs/error.c srcs/sort.c srcs/field.c srcs/layout.c \
	   srcs/setup.c srcs/free.c srcs/ft_ls.c
LIBS = libs/libft/libft.a
INCS = -I incs -I libs/libft/incs

RESET = \033[0m
GREEN = \033[1;32m
RED = \033[1;31m

all: $(NAME)

$(NAME):
	@printf "\n\x1B[38;5;208mCompiling $(NAME)...\n\x1b[37m"
	@$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(LIBS) $(INCS)
	@printf "\n$(GREEN)[✓] $(RESET)\x1B[32m$(NAME) ready!\n\x1b[37m"

fclean:
	@rm -rf $(NAME)
	@printf "$(RED)[x] $(RESET)\x1B[31m$(NAME) deleted\n"

re: fclean all

.PHONY: all fclean re
