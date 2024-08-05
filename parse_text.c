#include "minishell.h"



/*************04.08*************/

int cmd_type_from_token(t_list *token)
{
    if (ft_strcmp(token->content, "echo") == 0)
		return ECHO;
    if (ft_strcmp(token->content, "cd") == 0)
		return CD;
    if (ft_strcmp(token->content, "pwd") == 0)
		return PWD;
    if (ft_strcmp(token->content, "export") == 0)
		return EXPORT;
    if (ft_strcmp(token->content, "unset") == 0)
		return UNSET;
    if (ft_strcmp(token->content, "env") == 0)
		return ENV;
    if (ft_strcmp(token->content, "exit") == 0)
		return EXIT;
    return EXTERNAL;
}

void define_scmd_type(t_list *token)
{
    while (token) 
	{
        if (token->type == T_TEXT) 
			token->scmd_type = cmd_type_from_token(token);
        token = token->next;
    }
}

void define_is_scmd(t_list *token)
{
	while (token)
	{
		define_scmd_type(token);
		if (token->type == T_TEXT && token->scmd_type != EXTERNAL)
			token->is_scmd = true;
		token = token->next;
	}
}

void	handle_external_text(t_list *token)
{
	token->args = (char **)malloc(sizeof(char *) * 2);
	if (!token->args)
	{
		perror("Malloc Error for token_args!\n");
		exit(EXIT_FAILURE);
	}
	token->args[0] = ft_strdup(token->content);
	token->args[1] = NULL;
}

void add_argument(t_list *token)
{
    int count;
	int	i;
	char **new_args;
	
	count = 0;
	i = 0;
    while (token->args && token->args[count]) 
		count++;
    new_args = (char **)malloc(sizeof(char *) * (count + 2)); // +1 for new arg +1 for NULL
    if (!new_args)
    {
        perror("Malloc Error for add_args!\n");
        exit(EXIT_FAILURE);
    }
   while (i < count)
    {
        new_args[i] = token->args[i];
		i++;
    }
    new_args[count] = ft_strdup(token->content);
    new_args[count + 1] = NULL;
    free(token->args);
    token->args = new_args;
}
