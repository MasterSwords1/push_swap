/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sorts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:42:32 by ariyad            #+#    #+#             */
/*   Updated: 2025/01/21 21:42:52 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	send_sml_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*small_node;
	int		node_index;

	small_node = smallest_nbr(*stack_a);
	node_index = index_in_lst(*stack_a, small_node);
	if (node_index > ft_lstsize(*stack_a) / 2)
	{
		while (small_node->back != NULL)
			rra(stack_a);
	}
	else
	{
		while (small_node->back != NULL)
			ra(stack_a);
	}
	pb(stack_b, stack_a);
}

void	nano_sort(t_list **stack_a)
{
	if ((*stack_a)->num > (*stack_a)->next->num)
		ra(stack_a);
}

void	microsort(t_list **stack_a)
{
	if ((*stack_a)->num > (*stack_a)->next->num)
		sa(stack_a);
	if ((*stack_a)->next->num > (*stack_a)->next->next->num)
	{
		rra(stack_a);
		if ((*stack_a)->num > (*stack_a)->next->num)
			sa(stack_a);
	}
}

void	macrosort(t_list **stack_a, t_list **stack_b)
{
	send_sml_to_b(stack_a, stack_b);
	microsort(stack_a);
	pa(stack_a, stack_b);
}

void	millisort(t_list **stack_a, t_list **stack_b)
{
	send_sml_to_b(stack_a, stack_b);
	macrosort(stack_a, stack_b);
	pa(stack_a, stack_b);
}
