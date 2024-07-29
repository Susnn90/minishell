#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include "token_list/tokenlist.h"
# include <stdio.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>

//#define	MAX_ARGS //maximum amount of acceptable variables from an input
# define WHITESPACE ' '
# define QUOTES	"'\""
# define D_QUOTE '"'
# define S_QUOTE '\''

# define T_TEXT 1 //text
# define T_S_QUOTES 2 //single quote '\''
# define T_D_QUOTES 3 //double quote "\""
// # define T_O_BRACKET 4 //open bracket '('	not allowed in bash
// # define T_C_BRACKET 5 //close bracket ')'	not allowed in bash
# define T_PIPE 4 //pipe '|'
# define T_BI_OP 5 //binary operator '&'
# define T_REDIR 6 //redirection '>' '<' '>>' '<<'

// Main
int		main (int argc, char **argv);//, char **envp);
int		check_quotes(char *input);

//parse input
// void parse_command(const char *input, char **command, char **args);
// void	handle_quotes(char *input, char **args); //TODO


#endif
