/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenlist.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwick <cwick@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:18:38 by cwick             #+#    #+#             */
/*   Updated: 2024/07/28 14:21:33 by cwick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENLIST_H
# define TOKENLIST_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../minishell.h"
# include "../libft/libft.h"

typedef struct s_list
{
	struct s_list *prev;
	struct s_list *next;
	int		index;
	int		type;
	int		len;
	char	*input;
	char	*content;
	char	*result;
	char	**envp;
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
t_list	*lexer(char *input, int n_of_token);
t_list	*create_list(t_list *token_list, char *input, int n_of_token);
t_list	*move_to_list_head(t_list *current);
t_list	*split_string(t_list *token_list, char *input);
int		malloc_for_content(t_list *token_list, t_list *new_token);
int		count_token(char *input);
int		quote_text_len(char *str);
int		other_marks(char *c);
void	token_len(t_list *token_list, char *input);
void	define_token_type(t_list *token_list);
void	print_token_list(t_list *token_list);



#endif
