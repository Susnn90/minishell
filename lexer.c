#include "minishell.h"

t_token	*create_token(char *input, t_token *token, int i, int start)
{
	token = (t_token *)malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->content = ft_substr(input, start, i - start);
	if (!token->content)
	{
		free(token);
		return (NULL);
	}
	return (token);
}

//create a double link list from input
t_list	*get_token_list(char *input)
{
	int		i;
	int		start;
	t_list	*token_list;
	t_token	*token;

	i = 0;
	token_list = NULL;
	token = NULL;
	while (input[i])
	{
		start = i;
		while (input[i] && !ft_strchr(WHITESPACE, input[i]))
			i++;
		if (start < i)
			create_token(input, token, i, start);
		if (token_list == NULL)
			token_list = ft_lstnew(token);
		else
			ft_lstadd_back(&token_list, ft_lstnew(token));
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
void	token_type(char *input, t_list *token_list)
{
	t_list	*current;

	token_list = get_token_list(input);
	current = move_to_list_head(token_list);
	while (current)
	{
		define_token_type(current->token);
		current = current->next;
	}
}
