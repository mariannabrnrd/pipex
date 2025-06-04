# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mariaber <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/26 12:39:03 by mariaber          #+#    #+#              #
#    Updated: 2024/12/27 14:33:14 by mariaber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_isalnum.c  \
	   ft_isdigit.c \
	   ft_isalpha.c  \
	   ft_isprint.c  \
	   ft_strlen.c   \
	   ft_toupper.c  \
	   ft_tolower.c  \
	   ft_atoi.c     \
	   ft_memset.c   \
	   ft_strrchr.c  \
	   ft_strlcat.c  \
	   ft_strncmp.c  \
	   ft_memmove.c  \
	   ft_memcmp.c   \
	   ft_bzero.c    \
	   ft_isascii.c  \
	   ft_strchr.c   \
	   ft_memcpy.c   \
	   ft_strdup.c   \
	   ft_strdup.c   \
	   ft_strlcpy.c  \
	   ft_calloc.c   \
	   ft_memchr.c   \
	   ft_substr.c   \
	   ft_strnstr.c  \
	   ft_strjoin.c  \
	   ft_strtrim.c  \
	   ft_split.c	 \
	   ft_putchar_fd.c	\
	   ft_putstr_fd.c 	\
	   ft_putendl_fd.c	\
	   ft_putnbr_fd.c 	\
	   ft_itoa.c		\
	   ft_strmapi.c		\
	   ft_striteri.c	\

FLAGS = -Wall -Wextra -Werror
CC = gcc
OBJS = $(SRCS:.c=.o)
.o:.c
	$(CC) $(FLAGS) -c $< -o ${<:.c=.o}
$(NAME): ${OBJS}
	ar rcs $(NAME) $(OBJS)
all: $(NAME)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
