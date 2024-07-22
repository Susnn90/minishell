#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

#define	MAX_ARGS //maximum amount of acceptable variables from an input

typedef struct	s_tools
{
	char	*args;
	char	**paths;
	char	**envp;
}	t_tools;

typedef struct s_node {
	char	*token;
	struct s_node *prev;
	struct s_node *next;
}	t_node;

// Main & Utils
int main (int argc, char **argv, char **envp);

//parse input
void parse_command(const char *input, char **command, char **args);
void	handle_quotes(char *input, char **args); //TODO

//create double link list for tokens
t_node	*create_node(char *token);
void	append_node(t_node **head, t_node **tail, char *token);
void	free_list(t_node *head);
#endif
