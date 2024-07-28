#include "minishell.h"

int	check_quotes(char *input)
{
	int	i;
	int	n_of_squotes;
	int	n_of_dquotes;

	i = 0;
	n_of_squotes = 0;
	n_of_dquotes = 0;
	while (input[i])
	{
		if (input[i] == '\'')
			n_of_squotes++;
		else if (input[i] == '"')
			n_of_dquotes++;
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
