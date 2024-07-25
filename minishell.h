#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

//#define	MAX_ARGS //maximum amount of acceptable variables from an input
#define WHITESPACE  "\t\n"
#define QUOTES	"\'\""

#define T_D_QUOTES 4 //double quote "\""
#define T_S_QUOTES 2 //single quote '\''
#define T_PIPE 64 //pipe '|'
#define T_REDIR 512 //redirection '>' '<' '>>' '<<'
#define T_TEXT 1 //text 
#define T_O_BRACKET 128 //open bracket '('
#define T_C_BRACKET 256 //close bracket ')'
#define T_BI_OP 32 //binary operator '&'

//define ENVP

typedef struct	s_tools
{
	char	*args;
	char	**paths;
	char	**envp;
}	t_tools;

typedef struct s_list {
	t_token	*token;
	struct s_list *prev;
	struct s_list *next;
}	t_list;

typedef struct s_token
{
	int	type;
	char	*content;
}	t_token;

// Main & Utils
int main (int argc, char **argv, char **envp);

//lexer
static void	get_token_list(char *input);

//parse input
// void parse_command(const char *input, char **command, char **args);
// void	handle_quotes(char *input, char **args); //TODO


#endif
