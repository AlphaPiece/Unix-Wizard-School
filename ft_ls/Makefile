# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zwang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/10 14:18:06 by zwang             #+#    #+#              #
#    Updated: 2018/10/10 16:10:34 by zwang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = libft.a

SRCS = srcs/arg_vec.c srcs/error.c srcs/ft_ls.c srcs/sort.c \
	   srcs/cmp_swap.c srcs/field.c srcs/layout.c srcs/setup.c
INCS = incs/

RESET = \033[0m
GREEN = \033[1;32m
RED = \033[1;31m

all: $(NAME)

$(NAME):
	@make -C srcs/libft/
	@mv srcs/libft/libft.a .
	@printf "\n\x1B[38;5;208mCompiling $(NAME)...\n\x1b[37m"
	@$(CC) $(CFLAGS) -o $(NAME) $(SRCS) libft.a -I $(INCS) -I srcs/libft/incs
	@printf "\n$(GREEN)[✓] $(RESET)\x1B[32m$(NAME) ready!\n\x1b[37m"

clean:
	@make -C srcs/libft/ clean
	
fclean: clean
	@rm $(NAME)
	@rm libft.a
	@printf "$(RED)[x] $(RESET)\x1B[31m$(NAME) deleted\n"

re: fclean all
