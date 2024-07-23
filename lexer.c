#include "minishell.h"

static void	get_token_list(char *input)
{
	int		i;
	int		start;
	t_list	*token_list;
	char	*token;

	i = 0;
	token_list= NULL;
	while (input[i] && ft_strchr(input, WHITESPACE))
		i++;
	while (input[i])
	{
		start = i;
		while (input[i] && !ft_strchr(input, WHITESPACE))
			i++;
		if (start < i)
		{
			token = ft_substr(input, start, i - start);
			if (token_list == NULL)
				token_list = ft_lstnew(token);
			else
				ft_lstadd_back(&token_list, token);
		}
		while (input[i] && ft_strchr(input, WHITESPACE))
			i++;
	}
}
