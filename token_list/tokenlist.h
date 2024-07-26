/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenlist.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwick <cwick@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:18:38 by cwick             #+#    #+#             */
/*   Updated: 2024/07/26 12:42:11 by cwick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENLIST_H
# define TOKENLIST_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../minishell.h"
# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"

typedef struct s_token
{
	int		type;
	char	*content;
	char	**envp;
}	t_token;

typedef struct s_list
{
	t_token	*token;
	struct s_list *prev;
	struct s_list *next;
}	t_list;

t_list	*ft_lstnew(void *input);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*));
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void*));

// LEXER
t_list	*get_token_list(char *input, t_list *token_list);
t_list	*move_to_list_head(t_list *current);
int		token_len(char *str);
int		quote_text_len(char *str);
int		other_marks(char *c);
void	token_type(char *input, t_list *token_list);
void	define_token_type(t_token *token);

#endif
