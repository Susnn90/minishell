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

t_list	*create_list(t_list *token_list, char *input, int n_of_token)
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
		new_token->input = input;
		new_token->index = i;
		new_token->type = 0;
		new_token->len = 0;
		new_token->result = NULL;
		new_token->prev = NULL;
		new_token->next = NULL;
		new_token->content = NULL;
		ft_lstadd_back(&token_list, new_token);
		token_len(token_list, input);
		malloc_for_content(token_list, new_token);
		i++;
	}
	return (token_list);
}

int	malloc_for_content(t_list *token_list, t_list *new_token)
{
	new_token->content = (char *)malloc(sizeof(char) * (new_token->len + 1));
	if (!new_token->content)
	{
		ft_lstclear(&token_list, free);
		return (1);
	}
	return (0);
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
	head = move_to_list_head(token_list);
	token_list = head;
	token_list = split_string(token_list, input);
	while (token_list)
	{
		define_token_type(token_list);
		token_list = token_list->next;
	}
	token_list = head;
	return(token_list);
}

t_list *split_string(t_list *token_list, char *input)	// WOrks not correct
{
	int i;
	int start;
	int token_len;
	int	in_dquote_string;
	t_list *current = token_list;

	i = 0;
	start = 0;
	token_len = 0;
	in_dquote_string = 0;
	while (input[i])
	{
		while (input[i] == WHITESPACE)
			i++;
		start = i;
		while (input[i])
		{
			if (input[i] == D_QUOTE)
			{
				in_dquote_string = !in_dquote_string;
				i++;
			}
			else if (input[i] == WHITESPACE && in_dquote_string)
				i++;
			else if (input[i] == WHITESPACE && !in_dquote_string)
			{
				i++;
				goto fill_token;
			}
			else
				i++;
		}
		fill_token:
			token_len = i - start;
			if (token_len > 0 && current)
			{
				ft_strlcpy(current->content, input + start, token_len);
				// current->content[token_len] = '\0';
				current = current->next;
			}
	}
	if (input[i] && current)
	{
		ft_strlcpy(current->content, input + start, token_len);
		current->content[token_len] = '\0';
	}
	return token_list;
}
