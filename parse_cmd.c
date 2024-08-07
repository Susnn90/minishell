#include "minishell.h"

void	define_type(t_list *token, int separator)
{
	if (ft_strcmp(token->content, ">") == 0 && separator == 0)
		token->type = TRUNC;
	else if (ft_strcmp(token->content, ">>") == 0 && separator == 0)
		token->type = APPEND;
	else if (ft_strcmp(token->content, "<<") == 0 && separator == 0)
		token->type = DOUBLE_INPUT;
	else if (ft_strcmp(token->content, "<") == 0 && separator == 0)
		token->type = INPUT;
	else if (ft_strcmp(token->content, "|") == 0 && separator == 0)
		token->type = PIPE;
	else if (ft_strcmp(token->content, ";") == 0 && separator == 0)
		token->type = END;
	else if (token->prev == NULL || token->prev->type >= TRUNC)
		token->type = CMD;
	else
		token->type = ARG;
}
int	define_type_to_char(t_list *token, char *type)
{
	if (ft_strchr(type, 'C') && is_type(token, CMD))
		return (1);
	else if (ft_strchr(type, 'X') && is_type(token, ARG))
		return (1);
	else if (ft_strchr(type, 'T') && is_type(token, TRUNC))
		return (1);
	else if (ft_strchr(type, 'A') && is_type(token, APPEND))
		return (1);
	else if (ft_strchr(type, 'D') && is_type(token, DOUBLE_INPUT))
		return (1);
	else if (ft_strchr(type, 'I') && is_type(token, INPUT))
		return (1);
	else if (ft_strchr(type, 'P') && is_type(token, PIPE))
		return (1);
	else if (ft_strchr(type, 'E') && is_type(token, END))
		return (1);
	return (0);
}

int	is_seperator(char *input, int i) //checking both in and outside of quotes
{
	if (i > 0 && input[i - 1] == '\\' && ft_strchr("<>|;", input[i]))
		return (0);
	else if (ft_strchr("<>|;", input[i]) && quotes(input, i) == 0)
		return (1);
	else
		return (0);
}

int	define_seperator(char *input, int i) //doesnt check if the seprator is in quotes
{
	if (input[i] && input[i] == '\\' && input[i + 1] && input[i + 1] == ';')
		return (1);
	else if (input[i] && input[i] == '\\' && input[i + 1] && input[i + 1] == '|')
		return (1);
	else if (input[i] && input[i] == '\\' && input[i + 1] && input[i + 1] == '>')
		return (1);
	else if (input[i] && input[i] == '\\' && input[i + 1] && input[i + 1] == '>'
		&& input[i + 2] && input[i + 2] == '>')
		return (1);
	else if (input[i] && input[i] == '\\' && input[i + 1] && input[i + 1] == '<')
		return (1);
	else if (input[i] && input[i] == '\\' && input[i + 1] && input[i + 1] == '<'
		&& input[i + 2] && input[i + 2] == '<')
		return (1);
	return (0);
}

int	quotes(char *input, int index)
{
	int	i;
	int	open;

	i = 0;
	open = 0;
	while (input[i] && i != index)
	{
		if (i > 0 && input[i - 1] == '\\')
			;
		else if (open == 0 && input[i] == '\"')
			open = 1;
		else if (open == 0 && input[i] == '\'')
			open = 2;
		else if (open == 1 && input[i] == '\"')
			open = 0;
		else if (open == 2 && input[i] == '\'')
			open = 0;
		i++;
	}
	return (open);
}
