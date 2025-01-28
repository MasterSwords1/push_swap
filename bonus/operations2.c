/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:21:07 by ariyad            #+#    #+#             */
/*   Updated: 2025/01/28 22:06:05 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_list **stack_a)
{
	if (!stack_a || !(*stack_a))
		return ;
	rotate(stack_a);
}

void	rb(t_list **stack_b)
{
	if (!stack_b || !(*stack_b))
		return ;
	rotate(stack_b);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !(*stack_a))
		return ;
	rotate(stack_a);
	if (!stack_b || !(*stack_b))
		return ;
	rotate(stack_b);
}

void	rra(t_list	**stack_a)
{
	if (!stack_a || !(*stack_a))
		return ;
	rev_rotate(stack_a);
}

void	rrb(t_list	**stack_b)
{
	if (!stack_b || !(*stack_b))
		return ;
	rev_rotate(stack_b);
}
