/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwick <cwick@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:53:42 by cwick             #+#    #+#             */
/*   Updated: 2023/12/04 18:10:30 by cwick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(const char *s, char c);
static int	word_len(const char *s, char c);
static void	ft_free(char **strs, int count);

char	**ft_split(const char *s, char c)
{
	char	**result;
	int		i;
	int		word_count;

	i = 0;
	word_count = ft_word_count(s, c);
	result = (char **) malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while ((word_count--) > 0)
	{
		while (*s && *s == c)
			s++;
		result[i] = (char *) malloc((word_len(s, c) + 1) * sizeof(char));
		if (!result[i])
		{
			ft_free(result, i);
			return (NULL);
		}
		ft_strlcpy(result[i], s, word_len(s, c) + 1);
		s += word_len(s, c);
		i++;
	}
	result[i] = 0;
	return (result);
}

static int	ft_word_count(const char *s, char c)
{
	int	word;
	int	flag;

	word = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c && flag == 0)
		{
			flag = 1;
			word++;
		}
		else if (*s == c)
			flag = 0;
		s++;
	}
	return (word);
}

static int	word_len(const char *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static void	ft_free(char **strs, int count)
{
	int	i;

	if (!strs)
		return ;
	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free (strs);
}
