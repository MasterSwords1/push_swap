/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:48:00 by ariyad            #+#    #+#             */
/*   Updated: 2025/01/20 20:37:23 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
	new->back = last;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	(*lst)->back = new;
	*lst = new;
}

void	ft_lstclear(t_list **lst)
{
	t_list	*pp;

	if (!lst)
		return ;
	while (*lst)
	{
		pp = (*lst)->next;
		ft_lstdelone(*lst);
		(*lst) = pp;
	}
}

void	ft_lstdelone(t_list *lst)
{
	if (!lst)
		return ;
	free(lst);
}

int	check_dup(t_list *lst)
{
	t_list	*node;
	t_list	*head;

	head = lst;
	while (lst)
	{
		node = lst->next;
		while (node)
		{
			if (node->num == lst->num)
				return (1);
			node = node->next;
		}
		lst = lst->next;
	}
	return (0);
}
