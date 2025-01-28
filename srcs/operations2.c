/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:21:07 by ariyad            #+#    #+#             */
/*   Updated: 2025/01/22 22:18:10 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack_a)
{
	if (!stack_a || !(*stack_a))
		return ;
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(t_list **stack_b)
{
	if (!stack_b || !(*stack_b))
		return ;
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !stack_b || !(*stack_a) || !(*stack_b))
		return ;
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}

void	rra(t_list	**stack_a)
{
	if (!stack_a || !(*stack_a))
		return ;
	rev_rotate(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_list	**stack_b)
{
	if (!stack_b || !(*stack_b))
		return ;
	rev_rotate(stack_b);
	ft_printf("rrb\n");
}
