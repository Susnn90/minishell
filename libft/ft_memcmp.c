/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwick <cwick@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:22:55 by chris             #+#    #+#             */
/*   Updated: 2023/12/02 10:09:58 by cwick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*sc1;
	unsigned char	*sc2;

	i = 0;
	sc1 = (unsigned char *) s1;
	sc2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (sc1[i] == sc2[i])
			i++;
		else if (sc1[i] < sc2[i])
			return (-1);
		else if (sc1[i] > sc2[i])
			return (1);
	}
	return (0);
}
