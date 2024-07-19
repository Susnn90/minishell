/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwick <cwick@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:52:29 by cwick             #+#    #+#             */
/*   Updated: 2023/12/02 10:09:11 by cwick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int c);
int	ft_issign(int c, int *sign);

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		ft_issign(str[i], &sign);
		i++;
	}
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	return (result * sign);
}

int	ft_isspace(int c)
{
	if ((c == 9 || c == 10 || c == 11 || c == 12 || c == 13 || c == 32))
		return (1);
	return (0);
}

int	ft_issign(int c, int *sign2)
{
	if (c == '-')
	{
		*sign2 *= -1;
	}
	else if (c == '+')
	{
		*sign2 *= 1;
	}
	return (*sign2);
}
