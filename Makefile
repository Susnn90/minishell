# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: babybird <babybird@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/14 12:35:11 by cwick             #+#    #+#              #
#    Updated: 2024/08/07 15:30:45 by babybird         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = main.c lexer.c count_utils.c check_quotes.c parse_cmd.c parse.c parse_cmd_buildin.c
OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a
TOKEN_LIST = token_list/tokenlist.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
LFLAGS = -lreadline			#linker flags

all: $(NAME) clean

$(NAME): $(OBJ) $(LIBFT) $(TOKEN_LIST)
	$(CC) $(OBJ) $(LIBFT) $(TOKEN_LIST) -o $(NAME) $(LFLAGS)

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
