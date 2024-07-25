/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwick <cwick@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 07:51:16 by cwick             #+#    #+#             */
/*   Updated: 2024/07/25 12:43:01 by cwick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenlist.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->token->content);
	free(lst);
}
