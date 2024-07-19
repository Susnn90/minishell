/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwick <cwick@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:08:31 by cwick             #+#    #+#             */
/*   Updated: 2024/07/19 12:46:52 by cwick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int nbr)
{
	int	count;

	count = 0;
	count += ft_putnbr(nbr);
	if (count < 0)
		return (-1);
	return (count);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (n < 0)
	{
		count += ft_print_char('-');
		n = -n;
	}
	if (n > 9)
	{
		count += ft_putnbr(n / 10);
	}
	count += ft_print_char((n % 10) + '0');
	if (count < 0)
		return (-1);
	return (count);
}
