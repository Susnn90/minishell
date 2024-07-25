/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwick <cwick@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 06:52:00 by cwick             #+#    #+#             */
/*   Updated: 2024/07/25 12:42:46 by cwick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenlist.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_pos;

	if (!new)
		return ;
	last_pos = ft_lstlast(*lst);
	if (!last_pos)
		*lst = new;
	else
		last_pos->next = new;
}
