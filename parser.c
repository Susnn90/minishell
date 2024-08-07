#include "minishell.h"

int is_type(t_list *token, int type)
{
	if (token && token->type == type)
		return (1);
	return (0);
}



int has_type(t_list *token, int type) //check if there is a certain token->type, if yes return 1, 
{
	while (token)
	{
		if (is_type(token, type))
			return (1);
		token = token->next;
	}
	return (0);
}

int	has_pipe(t_list *token)
{
	while (token && is_type(token, END) == 0)
	{
		if (is_type(token, PIPE))
			return (1);
		token = token->next;
	}
	return (0);
}
t_list	*search_type(t_list *token, int type) //search for a certain type and point to this token
{
	while (token && token->type != type)
		token = token->next;
	return (token);
}
