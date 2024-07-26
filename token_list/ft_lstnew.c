/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwick <cwick@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:59:38 by cwick             #+#    #+#             */
/*   Updated: 2024/07/26 12:40:59 by cwick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenlist.h"

t_list	*ft_lstnew(void *input)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->token = (t_token *)malloc(sizeof(t_token));
	if (!new_node->token)
	{
		free(new_node);
		return (NULL);
	}
	new_node->token->content = (char*)input;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}
