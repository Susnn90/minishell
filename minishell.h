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

typedef struct	s_tools
{
	char	*args;
	char	**paths;
	char	**envp;
}	t_tools;

typedef struct s_list {
	char	*token;
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
