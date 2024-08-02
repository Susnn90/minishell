#include "minishell.h"

//define token type, with giving definiation (check minishell.h line.15-line.22)
void	define_token_type(t_list *token_list)
{
	if (token_list->content)
	{
		if (ft_strcmp(token_list->content, "|") == 0)
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
}

//move the pointer to head of the list
t_list	*move_to_list_head(t_list *current)
{
	while (current && current->prev)
		current = current->prev;
	return (current);
}

t_list	*create_list(t_list *token_list, char *input, int n_of_token)
{
	int		i;
	t_list	*new_token;
	t_list	*head;

	i = 0;
	new_token = NULL;
	head = NULL;
	while (i < n_of_token)
	{
		new_token = ft_lstnew(NULL);
		if (!new_token)
		{
			ft_lstclear(&token_list, free);
			return (NULL);
		}
		new_token->input = input;
		new_token->index = i;
		new_token->type = 0;
		new_token->len = 0;
		new_token->result = NULL;
		new_token->prev = NULL;
		new_token->next = NULL;
		new_token->content = NULL;
		ft_lstadd_back(&token_list, new_token);
		i++;
	}
	head = token_list;
	i = 0;
	token_len(token_list, input);
	while (i < n_of_token)
	{
		malloc_for_content(token_list, new_token);
		token_list = token_list->next;
		i++;
	}
	token_list = head;
	return (token_list);
}

t_list	*malloc_for_content(t_list *token_list, t_list *new_token)
{
	token_list->content = (char *)malloc(sizeof(char) * (new_token->len + 1));
	if (!token_list->content)
	{
		ft_lstclear(&token_list, free);
		return (NULL);
	}
	return (token_list);
}

//define token type
t_list	*lexer(char *input, int n_of_token)
{
	t_list	*token_list;
	t_list	*head;

	token_list = NULL;
	head = NULL;
	token_list = create_list(token_list,input, n_of_token);
	if (!token_list)
	{
		printf("Failed to create the list\n");
		return (NULL);
	}
	head = token_list;
	token_list = split_string(token_list, input, n_of_token);
	while (token_list)
	{
		define_token_type(token_list);
		token_list = token_list->next;
	}
	token_list = head;
	return(token_list);
}

t_list *split_string(t_list *token_list, char *input, int n_of_token)
{
	int	i;
	int	start;
	t_list *head = token_list;

	i = 0;
	start = 0;
	head = token_list;
	while (i < n_of_token)
	{
		while (input[start] == WHITESPACE)
			start++;
		if (input[start] == S_QUOTE && input[start + 1] == S_QUOTE)
		{
			start += 2;
			token_list->content = NULL;
			token_list = token_list->next;
			i++;
			continue ;
		}
		else if (input[start] == D_QUOTE && input[start + 1] == D_QUOTE)
		{
			start += 2;
			token_list->content = NULL;
			token_list = token_list->next;
			i++;
			continue ;
		}
		// if (input[start] == S_QUOTE || input[start] == D_QUOTE)
		// 	start++;
		ft_strlcpy(token_list->content, &input[start], token_list->len);
		start += token_list->len;
		token_list = token_list->next;
		i++;
	}
	if (input[start] && token_list)
	{
		ft_strlcpy(token_list->content, input + start, token_list->len);
		// token_list->content[token_list->len] = '\0';
	}
	token_list = head;
	return (token_list);
}
