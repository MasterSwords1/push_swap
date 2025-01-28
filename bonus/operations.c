/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:10:11 by ariyad            #+#    #+#             */
/*   Updated: 2025/01/28 22:05:32 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_list	**stack_a)
{
	if (!stack_a || !(*stack_a))
		return ;
	swap(stack_a);
}

void	sb(t_list	**stack_b)
{
	if (!stack_b || !(*stack_b))
		return ;
	swap(stack_b);
}

void	ss(t_list	**stack_a, t_list	**stack_b)
{
	if (!stack_a || !(*stack_a))
		return ;
	swap(stack_a);
	if (!stack_b || !(*stack_b))
		return ;
	swap(stack_b);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	if (!stack_b || !(*stack_b))
		return ;
	push(stack_a, stack_b);
}

void	pb(t_list **stack_b, t_list **stack_a)
{
	if (!stack_a || !(*stack_a))
		return ;
	push(stack_b, stack_a);
}
