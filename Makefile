# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwick <cwick@student.42berlin.de>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/14 12:35:11 by cwick             #+#    #+#              #
#    Updated: 2024/07/26 12:47:14 by cwick            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = main.c lexer.c lexer_utils.c
OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a
PRINTF = libft/ft_printf/printf.a
TOKEN_LIST = token_list/tokenlist.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
LFLAGS = -lreadline			#linker flags

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF) $(TOKEN_LIST)
	$(CC) $(OBJ) $(LIBFT) $(PRINTF) $(TOKEN_LIST) -o $(NAME) $(LFLAGS)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
	# $(MAKE) -C libft

$(LIBFT):
	$(MAKE) -C libft

 $(TOKEN_LIST):
	$(MAKE) -C token_list

clean:
	rm -f $(OBJ)
	$(MAKE) -C libft clean
	$(MAKE) -C token_list clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean
	$(MAKE) -C token_list fclean

re: fclean all

.PHONY: all clean fclean re
