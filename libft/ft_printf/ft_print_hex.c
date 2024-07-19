/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwick <cwick@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:09:42 by cwick             #+#    #+#             */
/*   Updated: 2023/12/16 12:41:02 by cwick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int nbr, int data_type)
{
	char	*chars;
	int		count;

	count = 0;
	if (data_type == 'x')
		chars = "0123456789abcdef";
	else
		chars = "0123456789ABCDEF";
	count += ft_put_hex(nbr, chars);
	return (count);
}

int	ft_put_hex(unsigned int nbr, char *chars)
{
	int	count;

	count = 0;
	if (nbr >= 16)
	{
		count += ft_put_hex(nbr / 16, chars);
		count += ft_put_hex(nbr % 16, chars);
	}
	else
		count += ft_print_char(chars[nbr]);
	return (count);
}
