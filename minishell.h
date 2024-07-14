#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct	s_tools
{
	char	*args;
	char	**paths;
	char	**envp;
}	t_tools;


// Main & Utils
int main (int argc, char **argv, char **envp);

#endif
