#include <stdio.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

int main (int argc, char **argv)//, char **envp)
{
	char	*input;

	// input checking argc und argv
	if (argc != 1 && argv[0])
	{
		printf("Wrong input: usage > ./minishell");
		return (0);
	}
	while (1)
	{
		input = readline("hamstershell > ");
	}
	printf("%s\n", input);

	//show prompt hamstershell >

	//input history

	//input checking -  lexing token checking
	return(0);
}

//yuan branches
