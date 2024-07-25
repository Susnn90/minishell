/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwick <cwick@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:59:38 by cwick             #+#    #+#             */
/*   Updated: 2024/07/25 16:26:08 by cwick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenlist.h"

t_list	*ft_lstnew()//void *content)
{
	t_list	*new_node;

	new_node = (t_list *) malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node = NULL;
	// new_node->token->content = content;
	if (new_node)
		new_node->next = NULL;
	return (new_node);
}
