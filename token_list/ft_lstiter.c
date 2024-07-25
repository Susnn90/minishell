/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwick <cwick@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 08:29:05 by cwick             #+#    #+#             */
/*   Updated: 2024/07/25 12:43:08 by cwick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenlist.h"

void	ft_lstiter(t_list *lst, void (*f)(void*))
{
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		f(lst->token->content);
		lst = lst->next;
	}
}
