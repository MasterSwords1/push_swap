/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:10:11 by ariyad            #+#    #+#             */
/*   Updated: 2025/01/22 22:19:01 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list	**stack_a)
{
	if (!stack_a || !(*stack_a))
		return ;
	swap(stack_a);
	ft_printf("sa\n");
}

void	sb(t_list	**stack_b)
{
	if (!stack_b || !(*stack_b))
		return ;
	swap(stack_b);
	ft_printf("sb\n");
}

void	ss(t_list	**stack_a, t_list	**stack_b)
{
	if (!stack_a || !stack_b || !(*stack_a) || !(*stack_b))
		return ;
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	if (!stack_b || !(*stack_b))
		return ;
	push(stack_a, stack_b);
	ft_printf("pa\n");
}

void	pb(t_list **stack_b, t_list **stack_a)
{
	if (!stack_a || !(*stack_a))
		return ;
	push(stack_b, stack_a);
	ft_printf("pb\n");
}
