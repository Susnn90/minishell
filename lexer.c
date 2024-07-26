#include "minishell.h"

//create a double link list from input
t_list	*get_token_list(char *input, t_list *token_list)
{
	int		i;
	int		start;
	t_list	*new_token;

	i = 0;
	while (input[i])
	{
		start = i;
		while (input[i] && !ft_strchr(WHITESPACE, input[i]))
			i++;
		if (start < i)
		{
			// new_token = ft_lstnew(ft_substr(input, start, i - start));
			new_token = ft_lstnew(input);
			if (!new_token || !new_token->token->content)
			{
				ft_lstclear(&token_list, free);
				return (NULL);
			}
			ft_lstadd_back(&token_list, new_token);
		}
		while (input[i] && ft_strchr(WHITESPACE, input[i]))
			i++;
	}
	return (token_list);
}

//move the pointer to head of the list
t_list	*move_to_list_head(t_list *current)
{
	while (current && current->prev)
		current = current->prev;
	return (current);
}

//define token type, with giving definiation (check minishell.h line.15-line.22)
void	define_token_type(t_token *token)
{
	if (ft_strcmp(token->content, "'") == 0)
		token->type = T_S_QUOTES;
	else if (ft_strcmp(token->content, "\"") == 0)
		token->type = T_D_QUOTES;
	else if (ft_strcmp(token->content, "|") == 0)
		token->type = T_PIPE;
	else if (ft_strcmp(token->content, ">") == 0
		|| ft_strcmp(token->content, "<") == 0
		|| ft_strcmp(token->content, "<<") == 0
		|| ft_strcmp(token->content, ">>") == 0)
		token->type = T_REDIR;
	else if (ft_strcmp(token->content, "&") == 0)
		token->type = T_BI_OP;
	else
		token->type = T_TEXT;
}
//define token type
t_list	*token_type(char *input, t_list *token_list, int n_of_token)
{
	token_list = get_token_list(input, token_list);
	token_list = move_to_list_head(token_list);
	while (token_list)
	{
		define_token_type(token_list->token);
		token_list = token_list->next;
	}
	token_list = move_to_list_head(token_list);
	return(token_list);
}
