#include "minishell.h"

int	count_token(char *input)
{
	int	i;
	int	counter;
	int	in_token;
	int in_squote_string;
	int	in_dquote_string;

	i = 0;
	counter = 0;
	in_token = 0;
	in_squote_string = 0;
	in_dquote_string = 0;
	while(input[i])
	{
		if (input[i] == S_QUOTE && input[i + 1] == S_QUOTE && !in_dquote_string)
		{
			i++;
			counter++;
		}
		else if (input[i] == D_QUOTE && input[i + 1] == D_QUOTE && !in_squote_string)
		{
			i++;
			counter++;
		}
		else if (input[i] == S_QUOTE || input[i] == D_QUOTE)
		{
			if (input[i] == S_QUOTE && !in_dquote_string)
				in_squote_string = !in_squote_string;
			else if (input[i] == D_QUOTE && !in_squote_string)
				in_dquote_string = !in_dquote_string;
		}
		else if ((input[i] == S_QUOTE && in_dquote_string) || (input[i] == D_QUOTE && in_squote_string))
		{
			i++;
			continue ;
		}
		else if (input[i] != WHITESPACE && !in_token)
		{
			counter++;
			in_token = 1;
		}
		if (input[i] == WHITESPACE  && !in_squote_string && !in_dquote_string)
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
	int in_squote_string;
	int	in_dquote_string;

	i = 0;
	counter = 0;
	current = token_list;
	in_squote_string = 0;
	in_dquote_string = 0;
	while (input[i])
	{
		if (input[i] == D_QUOTE || input[i] == S_QUOTE)
		{
			if (input[i] == S_QUOTE && !in_dquote_string)
				in_squote_string = !in_squote_string;
			else if (input[i] == D_QUOTE && !in_squote_string)
				in_dquote_string = !in_dquote_string;
			else
				counter++;
		}
		else if ((in_squote_string && !in_dquote_string) || (in_dquote_string && !in_squote_string))
			counter++;
		else if (input[i] != WHITESPACE && (!in_squote_string || !in_dquote_string))
			counter++;
		else if (input[i] == WHITESPACE && (!in_squote_string || !in_dquote_string))
		{
			current->len = counter;
			current = current->next;
			counter = 0;
		}
		i++;
	}
	if (counter >= 0 && current)
		current->len = counter;
}
