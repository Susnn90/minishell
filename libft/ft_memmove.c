/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwick <cwick@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:26:41 by cwick             #+#    #+#             */
/*   Updated: 2023/12/02 10:09:56 by cwick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*csrc;
	char	*cdest;
	size_t	i;

	csrc = (char *)src;
	cdest = (char *)dest;
	i = 0;
	if (dest == NULL && src == NULL)
		return (dest);
	if (cdest > csrc)
	{
		while (len-- > 0)
			cdest[len] = csrc[len];
	}
	else
	{
		while (i < len)
		{
			cdest[i] = csrc[i];
			i++;
		}
	}
	return (dest);
}
