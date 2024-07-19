/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwick <cwick@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:08:10 by cwick             #+#    #+#             */
/*   Updated: 2023/12/17 14:12:52 by cwick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int	i;

	i = 0;
	if (str != NULL)
	{
		while (str[i])
		{
			ft_print_char(str[i]);
			i++;
		}
		return (i);
	}
	write(1,"(null)", 6);
	return (6);
}
