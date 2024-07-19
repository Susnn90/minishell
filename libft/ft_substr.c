/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwick <cwick@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:05:08 by chris             #+#    #+#             */
/*   Updated: 2023/12/02 10:09:24 by cwick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	actual_len;

	actual_len = len;
	if (!s)
		return (NULL);
	if ((size_t) start >= ft_strlen(s))
		return (ft_strdup(""));
	if (actual_len > ft_strlen(s + start))
		actual_len = ft_strlen(s + start);
	substring = (char *)malloc((actual_len + 1) * sizeof(char));
	if (substring == NULL)
		return (NULL);
	ft_strlcpy(substring, s + start, actual_len + 1);
	return (substring);
}
