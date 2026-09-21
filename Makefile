# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsoto-ga <dsoto-ga@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/14 17:19:38 by dsoto-ga          #+#    #+#              #
#    Updated: 2026/09/21 15:27:40 by dsoto-ga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= push_swap
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g3
HEADER  = push_swap.h

SOURCES	= src/main.c \
		src/parsing/parser.c src/utils/aux_functions.c \
		src/utils/ft_split.c src/utils/ft_split_utils.c \
		src/stack/stack.c src/stack/stack_utils.c \
		src/operations/operations.c \
		src/operations/ops_push_swap.c \
		src/operations/ops_rotate.c \
		src/operations/ops_reverse_rotate.c \
		src/algorithms/sort_simple.c \
		src/algorithms/sort_complex.c \
		src/utils/print_utils.c \
		src/bench/bench.c \
		src/bench/bench_ops.c


OBJECTS	= $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re