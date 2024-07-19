/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwick <cwick@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 08:11:11 by cwick             #+#    #+#             */
/*   Updated: 2023/12/05 09:00:07 by cwick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;

	if (!lst || !del)
		return ;
	while (*lst != NULL)
	{
		current = *lst;
		*lst = (*lst)->next;
		del(current->content);
		free(current);
	}
	*lst = NULL;
}
