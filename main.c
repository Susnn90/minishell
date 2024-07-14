#include "minishell.h"

int main (int argc, char **argv, char **envp)
{
	char	*input;

	input = (char *) NULL;
	// input checking argc und argv
	if (argc != 1 && argv[0])
	{
		printf("Wrong input: usage > ./minishell");
		return (0);
	}
	while (1)
	{
		input = readline("hamstershell > ");
		if (input)
			add_history(input);
		while (*envp)
		{
			printf("%s\n", *envp);
			envp++;
		}
		// check_input_str(argc, *argv)
	}

	//input checking -  lexing token checking
	return(0);
}

// int	check_input_str(int argc, char **argv)
// {
// 	int	i;

// 	i = 0;
// 	while (i < argc)
// 	{

// 	}

// 	return (0);
// }
