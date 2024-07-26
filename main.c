#include "minishell.h"

void print_token_list(t_list *token_list) {
	t_list *current = token_list;
	// t_token	*token;

	while (current)
	{
		current->token = (t_token *)current->token;
		if (current->token && current->token->type)
			printf("Token: %s\nType: %d\n",current->token->content, current->token->type);
		current = current->next;
	}
}

int main (int argc, char **argv)//, char **envp)
{
	char	*input;
	t_list	*token_list;

	input = (char *) NULL;
	token_list = NULL;
	if (argc != 1 && argv[0])
	{
		printf("Wrong input: usage > ./minishell");
		return (0);
	}
	// init structs
	while (1)
	{
		input = readline("hamstershell > ");
		if (input)
		{
			add_history(input);
			token_type(input, token_list);
			print_token_list(token_list);
		}
	}
	return(0);
}
