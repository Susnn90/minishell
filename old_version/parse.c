#include "minishell.h"

//split input with " ", set command(the first token, store all token in args)
// void parse_command(const char *input, char **command, char **args)
// {
// 	char	*token;
// 	int		i;

// 	i = 0;
// 	token = ft_split(input, " ");
// 	if (token == NULL)
// 	{
// 		*command = NULL;
// 		args[0] = NULL;
// 		return (0);
// 	}
// 	while (token[i] != NULL && i < MAX_ARGS - 1)
// 	{
// 		args[i] = token[i];
// 		i++;
// 	}
// 	args[i] = NULL;
// 	*command = args[0];
// 	free(token);
// }

//handle quote:
//echo 'hello $USER' -> hello $USER
//echo "hello $USER" -> hello babybird
//env and command will be meaningless in SINGLE quote, but not in double quote
// "\" works the same as DOUBLE quote
/**********TODO********************/
// void	handle_quotes(char *input, char **args) 
// {
// 	char *token;
// 	int	i = 0;

// 	while (*token)
// 	{
// 		if (*token == '"' )
// 		{
			
// 		}
// 		if (*token == '\'') 
// 		{

// 		}
// 		if (*token == '\\')
// 		{

// 		}
// 	}
// }
//handle escapes

//replace environment variables (with getenv)
