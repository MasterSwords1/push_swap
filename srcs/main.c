/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:55:44 by ariyad            #+#    #+#             */
/*   Updated: 2025/01/28 21:15:34 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int		lstsize;

	if (ac == 1)
		return (0);
	is_empty(ac, av);
	stack_a = get_nbr_lst(ac, av);
	stack_b = NULL;
	is_sorted(stack_a);
	lstsize = ft_lstsize(stack_a);
	if (lstsize == 2)
		nano_sort(&stack_a);
	else if (lstsize == 3)
		microsort(&stack_a);
	else if (lstsize == 4)
		macrosort(&stack_a, &stack_b);
	else if (lstsize == 5)
		millisort(&stack_a, &stack_b);
	else
		megasort(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
}
