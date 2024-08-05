#include "minishell.h"

int	quote_text_len(char *str)
{
	int	i;
	char	quote;

	i = 0;

	quote = str[i];
	while (str[i])
	{
		if (str[i] == quote)
			return (i + 1);
		i++;
	}
	if (str[i] != quote)
	{
		printf("QUOTE IS MISSING!\n");
		return (0);
	}
	return (0);
}

int	other_marks(char *c)
{
	if (*c == '(' || *c == ')')
		return (1);
	else if (*c == '<' && *(c + 1) != '<')
		return (1);
	else if (*c == '<' && *(c + 1) == '<')
		return (2);
	else if (*c == '>' && *(c + 1) != '>')
		return (1);
	else if (*c == '>' && *(c + 1) == '>')
		return (2);
	else if (*c == '|' && *(c + 1) != '|')
		return (1);
	else if (*c == '&' && *(c + 1) != '&')
		return (1);
	return (0);
}
