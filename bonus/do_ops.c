/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:00:24 by ariyad            #+#    #+#             */
/*   Updated: 2025/01/28 22:02:09 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	valid_op(const char *str, char **ops)
{
	int	i;

	if (*str == '\n')
		return (0);
	i = 0;
	while (ops[i])
	{
		if (ft_strcmp(str, ops[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

static int	get_ops(t_data **lst)
{
	char	*input;
	char	*str;
	char	**ops;

	str = "sa\n sb\n ss\n pa\n pb\n ra\n rb\n rr\n rra\n rrb\n rrr\n";
	ops = ft_split(str, ' ');
	if (!ops)
		return (0);
	input = get_next_line(0);
	if (!input)
		return (free_table(ops), 1);
	if (!valid_op(input, ops))
		return (write(2, "Error\n", 7), free(input), free_table(ops), 0);
	while (input)
	{
		ft_lstadd_op(lst, ft_new_op(input));
		input = get_next_line(0);
		if (!input)
			break ;
		if (!valid_op(input, ops))
			return (write(2, "Error\n", 7), free_table(ops),
				ft_clear_ops(lst), free(input), 0);
	}
	free_table(ops);
	return (1);
}

static int	exec_op(t_data *ops_lst, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(ops_lst->ops, "sa\n") == 0)
		return (sa(stack_a), 1);
	else if (ft_strcmp(ops_lst->ops, "sb\n") == 0)
		return (sb(stack_b), 1);
	else if (ft_strcmp(ops_lst->ops, "ss\n") == 0)
		return (ss(stack_a, stack_b), 1);
	else if (ft_strcmp(ops_lst->ops, "pa\n") == 0)
		return (pa(stack_a, stack_b), 1);
	else if (ft_strcmp(ops_lst->ops, "pb\n") == 0)
		return (pb(stack_b, stack_a), 1);
	else if (ft_strcmp(ops_lst->ops, "ra\n") == 0)
		return (ra(stack_a), 1);
	else if (ft_strcmp(ops_lst->ops, "rb\n") == 0)
		return (rb(stack_b), 1);
	else if (ft_strcmp(ops_lst->ops, "rr\n") == 0)
		return (rr(stack_a, stack_b), 1);
	else if (ft_strcmp(ops_lst->ops, "rra\n") == 0)
		return (rra(stack_a), 1);
	else if (ft_strcmp(ops_lst->ops, "rrb\n") == 0)
		return (rrb(stack_b), 1);
	else if (ft_strcmp(ops_lst->ops, "rrr\n") == 0)
		return (rrr(stack_a, stack_b), 1);
	return (0);
}

int	do_ops(t_data **ops_lst, t_list **stack_a, t_list **stack_b)
{
	t_data	*head;

	if (!get_ops(ops_lst))
		return (0);
	head = (*ops_lst);
	while (head)
	{
		exec_op(head, stack_a, stack_b);
		head = head->next;
	}
	return (1);
}

int	op_sorted(t_list *stack_a, t_list *stack_b)
{
	if (stack_b)
		return (write(1, "KO\n", 4), 0);
	while (stack_a->next)
	{
		if (stack_a->num > stack_a->next->num)
			return (write(1, "KO\n", 4), 0);
		stack_a = stack_a->next;
	}
	return (write(1, "OK\n", 4), 1);
}
