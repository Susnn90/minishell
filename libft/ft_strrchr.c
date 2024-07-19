/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwick <cwick@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:46:47 by cwick             #+#    #+#             */
/*   Updated: 2023/12/02 10:09:27 by cwick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	cc;
	char	*find;

	i = 0;
	cc = (char) c;
	find = NULL;
	while (str[i] != '\0')
	{
		if (str[i] == cc)
		{
			find = ((char *) &str[i]);
		}
		i++;
	}
	if (str[i] == cc)
		find = ((char *) &str[i]);
	return (find);
}
