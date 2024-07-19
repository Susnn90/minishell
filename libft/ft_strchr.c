/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwick <cwick@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:29:34 by cwick             #+#    #+#             */
/*   Updated: 2023/12/02 10:09:49 by cwick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	cc;

	i = 0;
	cc = (char) c;
	while (str[i] != '\0')
	{
		if (str[i] == cc)
		{
			return ((char *) &str[i]);
		}
		i++;
	}
	if (str[i] == cc)
		return ((char *) &str[i]);
	return (NULL);
}
