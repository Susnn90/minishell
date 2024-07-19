/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwick <cwick@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:09:23 by cwick             #+#    #+#             */
/*   Updated: 2023/12/17 14:16:58 by cwick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *input_str, ...)
{
	int		i;
	va_list	data_type;
	int		count;

	va_start(data_type, input_str);
	i = 0;
	count = 0;
	while (input_str[i] != '\0')
	{
		if (input_str[i] == '%')
		{
			count += ft_formatcheck(input_str, data_type, ++i);
			if (count < 0)
				return (-1);
		}
		else
		{
			count += ft_print_char(input_str[i]);
			if (count < 0)
				return (-1);
		}
		i++;
	}
	va_end(data_type);
	return (count);
}

int	ft_formatcheck(const char *str, va_list data_type, int i)
{
	int	count;

	count = 0;
	if (str[i] == 'c')
		count += ft_print_char((char) va_arg(data_type, int));
	else if (str[i] == 's')
		count += ft_print_str((char *) va_arg(data_type, char *));
	else if (str[i] == 'd' || str[i] == 'i')
		count += ft_print_nbr((int) va_arg(data_type, int));
	else if (str[i] == 'u')
		count += ft_print_u_nbr((unsigned int) va_arg(data_type, unsigned int));
	else if (str[i] == 'p')
		count += ft_print_ptr((unsigned long) va_arg(data_type, void *));
	else if (str[i] == 'x' || str[i] == 'X')
		count += ft_print_hex((int) va_arg(data_type, int), str[i]);
	else if (str[i] == '%')
		count += ft_print_char('%');
	return (count);
}
