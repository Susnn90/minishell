#include "minishell.h"

int	check_quotes(char *input)
{
	int	i;
	int	n_of_squotes;
	int	n_of_dquotes;
	int	in_squote_string;
	int	in_dquote_string;

	i = 0;
	n_of_squotes = 0;
	n_of_dquotes = 0;
	in_squote_string = 0;
	in_dquote_string = 0;
	while (input[i])
	{
		if (input[i] == S_QUOTE)
		{
			if (!in_dquote_string)
			{
				n_of_squotes++;
				in_squote_string = !in_squote_string;
			}
		}
		else if (input[i] == D_QUOTE)
		{

			if (!in_squote_string)
			{
				n_of_dquotes++;
				in_dquote_string = !in_dquote_string;
			}
		}
		i++;
	}
	if (n_of_squotes % 2 != 0)
	{
		printf("A single Quote is missing\n");
		return (1);
	}
	if (n_of_dquotes % 2 != 0)
	{
		printf("A double Quote is missing\n");
		return (1);
	}
	return (0);
}
