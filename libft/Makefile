# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwick <cwick@student.42berlin.de>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 12:21:34 by cwick             #+#    #+#              #
#    Updated: 2024/07/25 12:10:07 by cwick            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
	ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strlcat.c ft_strlcpy.c \
	ft_strlen.c ft_tolower.c ft_toupper.c ft_strrchr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_memchr.c \
	ft_memcmp.c ft_strnstr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c \
	ft_striteri.c ft_split.c

OBJ = $(SRC:.c=.o)

PRINTF = ft_printf/printf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

all: $(NAME)

$(NAME): $(OBJ) $(PRINTF)
	ar rcs $@ $^

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(PRINTF):
	$(MAKE) -C ft_printf

clean:
	rm -f $(OBJ)
	$(MAKE) -C ft_printf clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re
