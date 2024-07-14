/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwick <cwick@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 13:36:09 by cwick             #+#    #+#             */
/*   Updated: 2024/07/14 14:04:30 by cwick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_arrdup(char **arr)
{
	char	**dup;
	int		i;

	i = 0;
	while (dup[i] != NULL)
		i++;
	dup = calloc(sizeof(char *), i + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (dup[i])
	{


	}



	return (dup);
}
