# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsoto-ga <dsoto-ga@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/14 17:19:38 by dsoto-ga          #+#    #+#              #
#    Updated: 2026/09/15 17:00:41 by dsoto-ga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= push_swap
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g3
HEADER  = push_swap.h

SOURCES	= src/main.c \
		src/parsing/parser.c 
		

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