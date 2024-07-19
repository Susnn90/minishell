/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwick <cwick@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:04:55 by chris             #+#    #+#             */
/*   Updated: 2023/12/02 10:09:35 by cwick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	char	*str_join;

	i = 0;
	j = 0;
	str_join = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str_join)
		return (NULL);
	while (s1[i] != '\0')
	{
		str_join[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str_join[i] = s2[j];
		i++;
		j++;
	}
	str_join[i] = '\0';
	return (str_join);
}
