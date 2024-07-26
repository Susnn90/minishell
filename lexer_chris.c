#include "minishell.h"

//define token type, with giving definiation (check minishell.h line.15-line.22)
void	define_token_type(t_list *token_list)
{
	if (ft_strcmp(token_list->content, "'") == 0)
		token_list->type = T_S_QUOTES;
	else if (ft_strcmp(token_list->content, "\"") == 0)
		token_list->type = T_D_QUOTES;
	else if (ft_strcmp(token_list->content, "|") == 0)
		token_list->type = T_PIPE;
	else if (ft_strcmp(token_list->content, ">") == 0
		|| ft_strcmp(token_list->content, "<") == 0
		|| ft_strcmp(token_list->content, "<<") == 0
		|| ft_strcmp(token_list->content, ">>") == 0)
		token_list->type = T_REDIR;
	else if (ft_strcmp(token_list->content, "&") == 0)
		token_list->type = T_BI_OP;
	else
		token_list->type = T_TEXT;
}

//move the pointer to head of the list
t_list	*move_to_list_head(t_list *current)
{
	while (current && current->prev)
		current = current->prev;
	return (current);
}

t_list	*create_list(t_list *token_list, int n_of_token)
{
	int		i;
	t_list	*new_token;

	i = 0;
	new_token = NULL;
	while (i < n_of_token)
	{
			new_token = ft_lstnew(NULL);
			if (!new_token)
			{
				ft_lstclear(&token_list, free);
				return (NULL);
			}
			new_token->content = "";
			new_token->index = i;
			new_token->type = 0;
			new_token->prev = NULL;
			new_token->next = NULL;
			ft_lstadd_back(&token_list, new_token);
		i++;
	}
	return (token_list);
}

//define token type
t_list	*lexer(char *input, t_list *token_list, int n_of_token)
{
	token_list = create_list(token_list, n_of_token);
	if (!token_list)
	{
		printf("Failed to create the list\n");
		return (NULL);
	}
	token_list = move_to_list_head(token_list);
	while (token_list)
	{
		printf("index: %d input %s\n", token_list->index, input);
		// define_token_type(token_list);
		token_list = token_list->next;
	}
	token_list = move_to_list_head(token_list);
	return(token_list);
}
