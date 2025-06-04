# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mariaber <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/21 10:49:48 by mariaber          #+#    #+#              #
#    Updated: 2025/01/21 12:05:03 by mariaber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
AR = ar rcs
RM = rm -f
FLAGS = -g -Wall -Werror -Wextra 

SOURCES = ft_printf.c utils.c utils2.c

OBJECTS = $(SOURCES:.c=.o)

$(NAME): $(OBJECTS)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re test
