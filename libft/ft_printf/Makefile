 # **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwick <cwick@student.42berlin.de>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 12:21:34 by cwick             #+#    #+#              #
#    Updated: 2023/12/09 11:55:56 by cwick            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf.a

SRC = ft_printf.c ft_print_char.c ft_print_str.c ft_print_nbr.c ft_print_u_nbr.c ft_print_ptr.c ft_print_hex.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
