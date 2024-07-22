#include "minishell.h"

t_node	*create_node(char *token)
{
	t_node *new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->token = ft_strdup(token);
	new_node->prev = NULL;
	new_node->next = NULL;
	return new_node;
}

void	append_node(t_node **head, t_node **tail, char *token)
{
	t_node *new_node = create_node(token);
	if (!new_node)
		return (NULL);
	if (*tail)
	{
		(*tail)->next = new_node;
		new_node->prev = *tail;
		*tail = new_node;
	}
	else
	{
		*head = new_node;
		*tail = new_node;
	}
}

void	free_list(t_node *head)
{
	t_node *temp;

	while(head)
	{
		temp = head;
		head = head->next;
		free(temp->token);
		free(temp);
	}
}
