/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:13:51 by ariyad            #+#    #+#             */
/*   Updated: 2025/01/23 11:13:47 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_index(t_list *lst)
{
	t_list	*head;

	head = lst;
	while (head)
	{
		while (lst)
		{
			if (head->num > lst->num)
				head->sorted_index++;
			lst = lst->next;
		}
		lst = ft_lstfirst(head);
		head = head->next;
	}
}

t_list	*smallest_nbr(t_list *lst)
{
	int		index;
	t_list	*smallest_node;

	index = lst->sorted_index;
	smallest_node = lst;
	while (lst)
	{
		if (index > lst->sorted_index)
		{
			index = lst->sorted_index;
			smallest_node = lst;
		}
		lst = lst->next;
	}
	return (smallest_node);
}

t_list	*biggest_nbr(t_list *lst)
{
	int		index;
	t_list	*biggest_node;

	index = lst->sorted_index;
	biggest_node = lst;
	while (lst)
	{
		if (index < lst->sorted_index)
		{
			index = lst->sorted_index;
			biggest_node = lst;
		}
		lst = lst->next;
	}
	return (biggest_node);
}

int	index_in_lst(t_list *lst, t_list *node)
{
	int	index;

	index = 0;
	while (lst)
	{
		if (lst == node)
			return (index);
		index++;
		lst = lst->next;
	}
	return (0);
}

int	dominant_side(t_list *lst)
{
	int		ascending;
	t_list	*head;
	int		middle;
	int		i;

	(1) && (head = lst, ascending = 0, i = 0);
	middle = ft_lstsize(lst) / 2;
	while (i < middle)
	{
		if (lst->num < lst->next->num)
			ascending--;
		ascending++;
		lst = lst->next;
		i++;
	}
	return (ascending);
}
