/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:41:34 by ariyad            #+#    #+#             */
/*   Updated: 2025/01/28 21:52:43 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_empty(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac)
	{
		j = 0;
		while (ft_isspace(av[i][j]))
			j++;
		if (av[i][j] == 0)
			return (write(2, "Error\n", 7), exit(1), 1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_data	*ops_lst;

	if (ac == 1)
		return (1);
	is_empty(ac, av);
	stack_a = NULL;
	stack_a = get_nbr_lst(ac, av);
	stack_b = NULL;
	ops_lst = NULL;
	if (!do_ops(&ops_lst, &stack_a, &stack_b))
		return (ft_lstclear(&stack_a),
		ft_lstclear(&stack_a),
		ft_clear_ops(&ops_lst), exit(1), 1);
	op_sorted(stack_a, stack_b);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_a);
	ft_clear_ops(&ops_lst);
}
