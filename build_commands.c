#include "minishell.h"

t_cmd *init_command()
{
	t_cmd *cmd = malloc(sizeof(t_cmd));
	cmd->name = NULL;
	cmd->args = NULL;
	cmd->input_redirect = 0;
	cmd->output_redirect = 0;
	cmd->input_file = NULL;
	cmd->output_file = NULL;
	cmd->append_output = 0;
	cmd->next = NULL;
	return cmd;
}

t_cmd	*parse_tokens(t_list *token)
{
	t_cmd *cmd;
	t_cmd *current_cmd;
	t_cmd *new_cmd;
	int arg_count = 0;

	cmd = NULL;
	current_cmd = NULL;
	while (token)
	{
		if (token->type == T_TEXT)
		{
			new_cmd = init_command();
			new_cmd->name = ft_strdup(token->content);
			if (current_cmd = NULL)
				cmd = new_cmd;
			else
				current_cmd->next = new_cmd;
			current_cmd = new_cmd;
			arg_count = 0;
		}
		else if (token->type == T_S_QUOTES || token->type == T_D_QUOTES) // there are no quotes in the content, i skiped them
			handle_quotes();//TODO
		else if (token->type == T_REDIR)
		{
			handle_redir(other_marks(token->content));
								//TODO:
								//handle: input dir, output dir, append_output
		}
		else if (token->type = T_PIPE)
		{
			t_cmd *new_cmd = init_command();
			current_cmd->next = new_cmd;
			current_cmd = new_cmd;
		}
		// else if (token->type = T_BI_OP) //pending...
		token = token->next;
	}
	return (cmd);
}

/****************old version ********************/
// t_cmd *init_command(t_list *token_head)
// {
// 	t_cmd	*cmd;

// 	cmd = NULL;
// 	cmd = malloc_command(cmd);
// 	if (token_head->type == T_TEXT)
// 	{
// 		if (ft_strcmp(token_head->content, "echo") == 0)
// 			cmd->name = ECHO;
// 		else if (ft_strcmp(token_head->content, "cd") == 0)
// 			cmd->name = CD;
// 		else if (ft_strcmp(token_head->content, "pwd") == 0)
// 			cmd->name = PWD;
// 		else if (ft_strcmp(token_head->content, "export") == 0)
// 			cmd->name = EXPORT;
// 		else if (ft_strcmp(token_head->content, "unset") == 0)
// 			cmd->name = UNSET;
// 		else if (ft_strcmp(token_head->content, "env") == 0)
// 			cmd->name = ENV;
// 		else if (ft_strcmp(token_head->content, "exit") == 0)
// 			cmd->name = EXIT;
// 	}
// 	return (cmd);
// }


// t_cmd *malloc_command(t_cmd *cmd)
// {
// 	cmd = malloc(sizeof(t_cmd));
// 	if (!cmd)
// 	{
// 		perror("Command malloc error!");
// 		return (NULL) ;
// 	}
// 	cmd->name = NULL;
// 	cmd->args = NULL;
// 	return (cmd);
// }

// void print_command(t_list *token_list)
// {
// 	t_cmd *cmd;

// 	cmd = init_command(token_list);
// 	if (cmd == NULL)
// 	{
// 		printf("Failed to initialized command.");
// 		return ;
// 	}
// 	printf("\nCOMMAND is: %s\n\n", cmd->name);
// 	free(cmd);
// }
// void handle_command(t_list *token_list)
// {
// 	t_cmd *cmd;

// 	cmd = init_command(token_list);
// 	while (token_list)
// 	{
// 		if (cmd->name == ECHO)
// 			deal_echo(token_list); //TODO
// 		else if (cmd->name == PWD)
// 			deal_pwd(token_list);//TODO
// 		else if (cmd->name == CD)
// 			deal_cd(token_list);//TODO
// 		else if (cmd->name == EXPORT)
// 			deal_export(token_list);//TODO
// 		else if (cmd->name == UNSET)
// 			deal_unset(token_list);//TODO
// 		else if (cmd->name == ENV)
// 			deal_env(token_list);//TODO
// 		else if (cmd->name == EXIT)
// 			deal_exit(token_list);//TODO
// 		else
// 			printf("Unknown command: %s\n", cmd->name);

// 	}
// 	free(cmd);
// }
