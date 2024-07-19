/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwick <cwick@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:51:06 by chris             #+#    #+#             */
/*   Updated: 2023/12/02 10:09:59 by cwick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, size_t c, size_t n)
{
	size_t				i;
	const unsigned char	*sc;
	unsigned char		cc;

	i = 0;
	sc = (unsigned char *) s;
	cc = (unsigned char) c;
	while (i < n)
	{
		if (sc[i] == cc)
			return ((void *) sc + i);
		i++;
	}
	return (NULL);
}
