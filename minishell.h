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
