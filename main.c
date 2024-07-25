#include "minishell.h"

int main (int argc, char **argv)//, char **envp)
{
	char	*input;
	t_list	*token_list;

	input = (char *) NULL;
	token_list = NULL;
	if (argc != 1 && argv[0])
	{
		printf("Wrong input: usage > ./minishell");
		return (0);
	}
	// init structs
	while (1)
	{
		input = readline("hamstershell > ");
		if (input)
		{
			add_history(input);
			token_type(input, token_list);
		}
		// check_input_str(argc, *argv)
	}

	//input checking -  lexing token checking
	return(0);
}
