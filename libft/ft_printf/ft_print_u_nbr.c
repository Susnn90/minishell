/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwick <cwick@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:09:03 by cwick             #+#    #+#             */
/*   Updated: 2023/12/15 17:33:36 by cwick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_u_nbr(unsigned int nbr)
{
	int	count;

	count = 0;
	count += ft_put_u_nbr(nbr);
	if (count < 0)
		return (-1);
	return (count);
}

int	ft_put_u_nbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		count += ft_put_u_nbr(n / 10);
	}
	count += ft_print_char((n % 10) + '0');
	return (count);
}
