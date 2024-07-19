/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwick <cwick@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:36:10 by cwick             #+#    #+#             */
/*   Updated: 2023/12/03 18:00:07 by cwick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	src_length;

	i = 0;
	src_length = ft_strlen(src);
	if (src_length == 0)
	{
		if (destsize > 0)
		{
			dest[0] = '\0';
		}
		return (0);
	}
	if (destsize < 1)
		return (src_length);
	while (i < destsize - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_length);
}
