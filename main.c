#include "minishell.h"

void print_token_list(t_list *token_list)
{
	t_list *current = token_list;

	while (current)
	{
		if (current->content || current->type)
			printf("Token: %s\n type: %d\n",current->content, current->type);
		if (current->next)
			current = current->next;
	}
}

int main (int argc, char **argv)			//, char **envp)
{
	char	*input;
	int		n_of_token;
	t_list	*token_list;

	input = (char *) NULL;
	n_of_token = 0;
	token_list = NULL;
	if (argc != 1 && argv[0])
	{
		printf("Wrong input: usage > ./minishell");
		return (0);
	}
	while (1)
	{
		input = readline("hamstershell > ");
		if (input)
		{
			add_history(input);
			n_of_token = count_token(input);
			lexer(input, token_list, n_of_token);
			// print_token_list(token_list);
		}
	}
	return(0);
}
