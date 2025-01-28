/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:08:19 by ariyad            #+#    #+#             */
/*   Updated: 2025/01/28 21:16:04 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *lst)
{
	t_list	*head;

	if (!lst)
		return (0);
	head = lst;
	while (lst->next)
	{
		if (lst->num > lst->next->num)
			return (0);
		lst = lst->next;
	}
	return (ft_lstclear(&head), exit(0), 0);
}

static char	**get_nbrs(char **av, int ac)
{
	char	**split;
	char	*str;
	int		i;

	i = 1;
	str = ft_strdup(av[i]);
	while (i < ac - 1)
	{
		str = ft_strjoin_plus(str, ft_strdup(" "));
		str = ft_strjoin_plus(str, ft_strdup(av[i + 1]));
		i++;
	}
	split = ft_split(str, ' ');
	free(str);
	if (!split)
		return (NULL);
	return (split);
}

t_list	*get_nbr_lst(int ac, char **av)
{
	char	**nbrs_arr;
	t_list	*nbrs_lst;
	t_list	*nbr;
	size_t	i;

	i = 0;
	nbr = NULL;
	nbrs_lst = NULL;
	nbrs_arr = get_nbrs(av, ac);
	if (!nbrs_arr)
		return (NULL);
	while (nbrs_arr[i])
	{
		nbr = ft_lstnew(ft_atoi_plus(nbrs_arr[i], &nbrs_lst, nbrs_arr));
		if (!nbr)
			return (write(2, "Error\n", 7), ft_lstclear(&nbrs_lst),
				free_table(nbrs_arr), exit(1), NULL);
		ft_lstadd_back(&nbrs_lst, nbr);
		i++;
	}
	free_table(nbrs_arr);
	if (check_dup(nbrs_lst))
		return (ft_lstclear(&nbrs_lst), write(2, "Error\n", 7), exit(1), NULL);
	update_index(nbrs_lst);
	return (nbrs_lst);
}
