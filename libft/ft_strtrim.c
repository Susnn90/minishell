/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwick <cwick@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:56:32 by chris             #+#    #+#             */
/*   Updated: 2023/12/02 14:09:53 by cwick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_trim_cmp(const char *set, char c);
static char	*ft_temp_str(const char *s1, size_t start, size_t len);

char	*ft_strtrim(const char *s1, const char *set)
{
	int		start;
	int		end;
	char	*temp;

	start = 0;
	end = ft_strlen(s1) -1;
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	while (ft_trim_cmp(set, s1[start]))
		start++;
	while (ft_trim_cmp(set, s1[end]))
		end--;
	temp = ft_temp_str(s1, start, end - (start - 1));
	return (temp);
}

static int	ft_trim_cmp(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_temp_str(const char *s1, size_t start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (len <= 0 || start >= ft_strlen(s1))
		return (ft_strdup(""));
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s1[start + i];
		i++;
	}
	return (str);
}
