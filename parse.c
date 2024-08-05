#include "minishell.h"

void	parse_tokens(t_list *token)
{
	t_list *new_cmd;

	while (token)
	{
		if (token->type == T_TEXT)
		{
			define_is_scmd(token);
			if (token->is_scmd == false && token->scmd_type == EXTERNAL) // if text is not simple command
			{
				handle_external_text(token);
				printf("the first command is: %s\n", token->content);
			}
			else
				add_argument(token);
		}
		else if (token->type == T_S_QUOTES || token->type == T_D_QUOTES)
			printf("handle_quotes();//todo");
		else if (token->type == T_REDIR)
			printf("handle_redir(); //TODO");
		else if (token->type == T_PIPE)
		{
			new_cmd = token->next;
			printf("the second command after PIPE is: %s\n", new_cmd->content);
			parse_tokens(new_cmd);
		}
		token = token->next;	
	}
}

