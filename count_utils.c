#include "minishell.h"

int	count_token(char *input)
{
	int	i;
	int	counter;
	int	in_token;

	i = 0;
	counter = 0;
	in_token = 0;
	while(input[i])
	{
		if (input[i] != WHITESPACE)
		{
			if (in_token == 0)
			{
				counter++;
				in_token = 1;
			}
		}
		else if (input[i] == WHITESPACE)
			in_token = 0;
		i++;
	}
	return (counter);
}

void	token_len(t_list *token_list, char *input)
{
	int	i;
	int	counter;
	t_list	*current;

	i = 0;
	counter = 0;
	current = token_list;
	while (input[i])
	{
		if (input[i] != WHITESPACE)
			counter++;
		else if (counter > 0 && current)
		{
			current->len = counter;
			current = current->next;
			counter = 0;
		}
		i++;
	}
	if (counter > 0 && current)
		current->len = counter;
}
