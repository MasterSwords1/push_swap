/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_sorts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:40:26 by ariyad            #+#    #+#             */
/*   Updated: 2025/01/28 16:37:24 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	chunk_size(t_list *lst)
{
	int	lstsize;
	int	chunk;
	int	n;

	lstsize = ft_lstsize(lst);
	if (lstsize <= 100)
		n = 5;
	else
		n = 14;
	chunk = lstsize / n;
	return (chunk);
}

static int	p_rot(t_list **stack_a, t_list **stack_b, int *range, int chunk)
{
	if ((*stack_a)->sorted_index <= *range)
	{
		pb(stack_b, stack_a);
		*range += 1;
		return (1);
	}
	else if ((*stack_a)->sorted_index < *range + chunk)
	{
		pb(stack_b, stack_a);
		rb(stack_b);
		*range += 1;
		return (1);
	}
	return (0);
}

void	hourglass(t_list **stack_a, t_list **stack_b, int chunk, int lstsize)
{
	int	range;
	int	dominant;

	range = 0;
	dominant = dominant_side(*stack_a);
	while ((*stack_a))
	{
		if (!p_rot(stack_a, stack_b, &range, chunk))
		{
			if (dominant > lstsize / 3)
				rra(stack_a);
			else
				ra(stack_a);
		}
	}
}

static void	back_to_stack(t_list **stack_a, t_list **stack_b)
{
	int		lstsize;
	t_list	*biggest_node;
	int		node_index;

	while ((*stack_b))
	{
		lstsize = ft_lstsize(*stack_b);
		biggest_node = biggest_nbr(*stack_b);
		node_index = index_in_lst(*stack_b, biggest_node);
		if (node_index > lstsize / 2)
		{
			while (biggest_node->back != NULL)
				rrb(stack_b);
			pa(stack_a, stack_b);
		}
		else
		{
			while (biggest_node->back != NULL)
				rb(stack_b);
			pa(stack_a, stack_b);
		}
	}
}

void	megasort(t_list **stack_a, t_list **stack_b)
{
	int	chunk;
	int	lstsize;

	lstsize = ft_lstsize(*stack_a);
	chunk = chunk_size(*stack_a);
	hourglass(stack_a, stack_b, chunk, lstsize);
	back_to_stack(stack_a, stack_b);
}
