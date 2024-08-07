#include "minishell.h"

void print_token_list(t_list *token_list)
{
	int		i;
	t_list *current;

	i = 0;
	current = move_to_list_head(token_list);
	while (current)
	{
		printf("NODE %d\n", i);
		printf("index %d\nlen %d\ninput %s\nresult %s\ncontent %s\ntype %d\n",
			current->index, current->len,current->input,
			current->result, current->content, current->type);
		//printf("is token a simple command: %s\n", current->is_scmd ? "true" : "false");
		//printf("simple command type is: %d\n", current->scmd_type);
		if (current->next)
			printf("\n");
		i++;
		current = current->next;
	}
}

void	lstclear(t_list *token_list)
{
	t_list	*current;

	if (!token_list)
		return ;
	while (token_list)
	{
		current = token_list;
		token_list = token_list->next;
		if (current->content)
			free(current->content);
		free(current);
	}
	token_list = NULL;
}

int main (int argc, char **argv)			//, char **envp)
{
	char	*input;
	int		n_of_token;
	t_list	*token_list;

	input = NULL;
	n_of_token = 0;
	token_list = NULL;
	if (argc != 1 && argv[0])
	{
		printf("Wrong input: usage > ./minishell\n");
		return (0);
	}
	while (1)
	{
		input = readline("h@m$t3r$h3ll$> ");
		if (input)
		{
			add_history(input);
			if (check_quotes(input))
				continue ;
			n_of_token = count_token(input);
			token_list = lexer(input, n_of_token);
			if (token_list)
			{
				//print_command(token_list);
				parse_tokens(token_list);
				print_token_list(token_list);
				lstclear(token_list);
			}
			free (input);
		}
	}
	return(0);
}
