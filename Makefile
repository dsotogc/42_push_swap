# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsoto-ga <dsoto-ga@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/14 17:19:38 by dsoto-ga          #+#    #+#              #
#    Updated: 2026/09/14 17:43:21 by dsoto-ga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= push_swap
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
HEADER  = push_swap.h

SOURCES	= main.c

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