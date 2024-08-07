#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include "token_list/tokenlist.h"
# include <stdio.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>

# define WHITESPACE ' '
# define QUOTES	"'\""
# define D_QUOTE '"'
# define S_QUOTE '\''

# define CMD 1
# define ARG 2
# define TRUNC 3 // '>'
# define APPEND 4 // '>>'
# define DOUBLE_INPUT 8 // '>>'
# define INPUT 5 // '<'
# define PIPE 6
# define END 7 //';' echo "Hello"; echo "World - excute first echo "hello", then excute echo "World"

//# define T_TEXT 111
//# define T_REDIR_FILE 16
//# define REDIR_APPEND 19 //'>>' append given contento into the end of file. if the file doesnt exits, create file.
//# define REDIR_HEREDOC 20 //'<<' allow multiple lines input,read given file until meet the given seperator, seperator follows after the '<<', then end input
// # define T_TEXT 1 //text
// // # define T_S_QUOTES 2 //single quote '\''
// // # define T_D_QUOTES 3 //double quote "\""
// // # define T_O_BRACKET 4 //open bracket '('	not allowed in bash
// // # define T_C_BRACKET 5 //close bracket ')'	not allowed in bash
// # define T_PIPE 4 //pipe '|'
// # define T_BI_OP 5 //binary operator '&'
// # define T_REDIR 6 //redirection '>' '<' '>>' '<<'

// Main
int		main (int argc, char **argv);//, char **envp);
int check_single_quotes(char *input);
int check_double_quotes(char *input);
int		check_quotes(char *input);

//parse
int		cmd_type_from_token(t_list *token);
void	define_scmd_type(t_list *token);
void	define_is_scmd(t_list *token);
void	handle_external_text(t_list *token);
void	add_argument(t_list *token);
void	parse_tokens(t_list *token);
//parse
void	define_type(t_list *token, int separator);
int		define_type_to_char(t_list *token, char *type);
int		is_seperator(char *input, int i);
int		define_seperator(char *input, int i);
int		quotes(char *input, int index);
int		is_type(t_list *token, int type);
t_list	*search_type(t_list *token, int type);
int		define_type_to_char(t_list *token, char *type);
int		has_type(t_list *token, int type);
int		has_pipe(t_list *token);

int		cmd_is_build_in(t_list *token);
//bool cmd_is_external(t_list *token);

#endif
