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

# define ECHO 7
# define CD 8
# define PWD 9
# define EXPORT 10
# define UNSET 11
# define ENV 12
# define EXIT 13
# define EXTERNAL 14 

# define T_REDIR_FILE 16
# define REDIR_INPUT 17
# define REDIR_OUTPUT 18
# define REDIR_APPEND 19
# define REDIR_HEREDOC 20
// typedef struct s_cmd
// {
// 	char *name;
// 	char **args;
// 	int input_redirect; //flag bit, to indicate whether there is in/out-put redirection： '<', if yes, set to 1
// 	int output_redirect; // 👆 '>', '>>'
// 	char *input_file; 
// 	char *output_file;
// 	int append_output; //Flag bit, to indicate whether output is append node. i.e. '>>'
// 	struct s_cmd *next; //when the parser encounters '|', means there's a new command next, this pointer points to this new command.
// } t_cmd;


// Main
int		main (int argc, char **argv);//, char **envp);
int check_single_quotes(char *input);
int check_double_quotes(char *input);
int		check_quotes(char *input);

//check command
// t_list *init_command(t_list *token_head);
// t_list *malloc_command(t_list *cmd);
// void print_command(t_list *token_list);

//parse
int		cmd_type_from_token(t_list *token);
void	define_scmd_type(t_list *token);
void	define_is_scmd(t_list *token);
void	handle_external_text(t_list *token);
void	add_argument(t_list *token);
void	parse_tokens(t_list *token);

#endif
