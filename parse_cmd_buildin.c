#include "minishell.h"


int cmd_is_build_in(t_list *token) //if it's build in, then execute build in functions. if not, use execve()
{
    if (token->type == CMD && ft_strcmp(token->content, "echo") == 0)
		return (1);
    if (token->type == CMD && ft_strcmp(token->content, "cd") == 0)
		return (1);
    if (token->type == CMD && ft_strcmp(token->content, "pwd") == 0)
		return (1);
    if (token->type == CMD && ft_strcmp(token->content, "export") == 0)
		return (1);
    if (token->type == CMD && ft_strcmp(token->content, "unset") == 0)
		return (1);
    if (token->type == CMD && ft_strcmp(token->content, "env") == 0)
		return (1);
    if (token->type == CMD && ft_strcmp(token->content, "exit") == 0)
		return (1);
    return (0);
}

// bool cmd_is_external(t_list *token)
// {
// 	if (token && cmd_is_build_in(token) == 0)
// 		token->is_external_cmd = true;
// 	token->is_external_cmd = false;
// }
