/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwick <cwick@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:09:51 by chris             #+#    #+#             */
/*   Updated: 2023/12/02 12:44:49 by cwick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_int_len(long nbr);
void	ft_copy(long *num, char *temp, int *i);

char	*ft_itoa(int n)
{
	char	*temp;
	int		n_len;
	int		i;
	long	num;

	i = 0;
	num = n;
	n_len = ft_int_len(num);
	temp = (char *) malloc((n_len + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	ft_copy(&num, temp, &i);
	temp[n_len] = '\0';
	n_len--;
	while (num != 0)
	{
		temp[n_len] = num % 10 + '0';
		num /= 10;
		n_len--;
	}
	return (temp);
}

long	ft_int_len(long nbr)
{
	int	count;

	count = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		count++;
		nbr = -nbr;
	}
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

void	ft_copy(long *num, char *temp, int *i)
{
	if (*num == 0)
	{
		temp[*i] = '0';
		(*i)++;
	}
	else if (*num < 0)
	{
		temp[*i] = '-';
		*num = -*num;
		(*i)++;
	}
}
