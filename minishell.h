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
// # define T_S_QUOTES 2 //single quote '\''
// # define T_D_QUOTES 3 //double quote "\""
// # define T_O_BRACKET 4 //open bracket '('	not allowed in bash
// # define T_C_BRACKET 5 //close bracket ')'	not allowed in bash
# define T_PIPE 4 //pipe '|'
# define T_BI_OP 5 //binary operator '&'
# define T_REDIR 6 //redirection '>' '<' '>>' '<<'

//CMDs
# define ECHO "echo"
# define CD "cd"
# define PWD "pwd"
# define EXPORT "export"
# define UNSET "unset"
# define ENV "env"
# define EXIT "exit"

typedef struct s_cmd
{
	char *name;
	char **args;
	int input_redirect; //flag bit, to indicate whether there is in/out-put redirection： '<', if yes, set to 1
	int output_redirect; // 👆 '>', '>>'
	char *input_file;
	char *output_file;
	int append_output; //Flag bit, to indicate whether output is append node. i.e. '>>'
	struct s_cmd *next; //when the parser encounters '|', means there's a new command next, this pointer points to this new command.
} t_cmd;


// Main
int		main (int argc, char **argv);//, char **envp);
int		check_single_quotes(char *input);
int		check_double_quotes(char *input);
int		check_quotes(char *input);

//check command
// t_cmd *init_command(t_list *token_head);
// t_cmd *malloc_command(t_cmd *cmd);
// void print_command(t_list *token_list);

//process/handle command
// void deal_echo(t_list *token_list);//TODO
// void deal_pwd(token_list);//TODO
// void deal_cd(token_list);//TODO
// void deal_export(token_list);//TODO
// void deal_unset(token_list);//TODO
// void deal_env(token_list);//TODO
// void deal_exit(token_list);//TODO

#endif
