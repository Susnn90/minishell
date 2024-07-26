int	count_token(char *input)
{
	int	i;
	int	counter;
	int	in_token;

	i = 0;
	counter = 0;
	in_token = 0;
	while(input[i])
	{
		if (input[i] != ' ' && in_token == 0)
		{
			in_token = 1;
			counter++;
		}
		else if (input[i] == ' ')
			in_token = 0;
		i++;
	}
	return (counter);
}
