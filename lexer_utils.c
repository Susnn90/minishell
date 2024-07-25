#include "minishell.h"

int	token_len(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_strchr(str, WHITESPACE) >= 0)
			return (i);
		else if (ft_strchr(str, QUOTES) >= 0)
			return ();
		else if (other_marks(str) > 0)
			return (other_marks(str));
		i++;
	}
}

void	token_type(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if 
	}
}
int	quote_text_len(char *str)
{
	int	i;
	char	quote;

	i = 0;
	// if (str[i] != QUOTES)
	// 	return (0);
	quote = str[i];
	while (str[i] != '\0')
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
