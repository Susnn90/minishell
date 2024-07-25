# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwick <cwick@student.42berlin.de>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 12:21:34 by cwick             #+#    #+#              #
#    Updated: 2024/07/25 12:23:03 by cwick            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tokenlist.a

SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
	ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
	ft_lstiter.c ft_lstmap.c

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
