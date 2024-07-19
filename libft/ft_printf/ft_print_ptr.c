/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwick <cwick@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:09:22 by cwick             #+#    #+#             */
/*   Updated: 2023/12/17 14:14:49 by cwick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(unsigned long mem_adress)
{
	int	count;

	count = 0;
	if (!mem_adress)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	count += ft_print_str("0x");
	if (count < 0)
		return (-1);
	count += ft_put_ptr(mem_adress);
	return (count);
}

int	ft_put_ptr(unsigned long mem_adress)
{
	int		count;
	char	*chars;

	count = 0;
	chars = "0123456789abcdef";
	if (mem_adress >= 16)
	{
		count += ft_put_ptr(mem_adress / 16);
		count += ft_put_ptr(mem_adress % 16);
	}
	else
	{
		count += ft_print_char(chars[mem_adress]);
	}
	if (count < 0)
		return (-1);
	return (count);
}
