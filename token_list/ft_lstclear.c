/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwick <cwick@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 08:11:11 by cwick             #+#    #+#             */
/*   Updated: 2024/07/29 17:22:48 by cwick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenlist.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		current = *lst;
		*lst = (*lst)->next;
		if (current->content)
			del(current->content);
		free(current);
	}
	*lst = NULL;
}
