/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst-manipulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:54:00 by ariyad            #+#    #+#             */
/*   Updated: 2025/01/28 22:04:50 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap(t_list	**lst)
{
	t_list	*tmp;

	if (!lst || !(*lst) || (*lst)->next == NULL)
		return ;
	tmp = (*lst)->next;
	if (tmp->next)
		tmp->next->back = (*lst);
	(*lst)->next = tmp->next;
	(*lst)->back = tmp;
	tmp->next = (*lst);
	tmp->back = NULL;
	(*lst) = tmp;
}

void	push(t_list **lst_to, t_list **lst_from)
{
	t_list	*tmp;

	if (!lst_from || !(*lst_from))
		return ;
	if (!lst_to || !(*lst_to))
	{
		(*lst_to) = (*lst_from);
		(*lst_from) = (*lst_from)->next;
		if ((*lst_from))
			(*lst_from)->back = NULL;
		(*lst_to)->next = NULL;
		return ;
	}
	tmp = (*lst_from);
	(*lst_to)->back = tmp;
	(*lst_from) = (*lst_from)->next;
	if ((*lst_from) != NULL)
		(*lst_from)->back = NULL;
	tmp->next = (*lst_to);
	(*lst_to) = tmp;
}

void	rotate(t_list **lst)
{
	t_list	*last;

	if (!lst || !(*lst))
		return ;
	last = ft_lstlast(*lst);
	(*lst)->back = last;
	last->next = (*lst);
	(*lst) = (*lst)->next;
	(*lst)->back = NULL;
	last->next->next = NULL;
}

void	rev_rotate(t_list **lst)
{
	t_list	*last;
	t_list	*before_last;

	if (!lst || !(*lst))
		return ;
	last = ft_lstlast((*lst));
	before_last = last->back;
	if (before_last != NULL)
		before_last->next = NULL;
	last->back = NULL;
	last->next = (*lst);
	(*lst)->back = last;
	(*lst) = last;
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !(*stack_a))
		return ;
	rev_rotate(stack_a);
	if (!stack_b || !(*stack_b))
		return ;
	rev_rotate(stack_b);
}
