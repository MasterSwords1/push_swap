/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:26:27 by ariyad            #+#    #+#             */
/*   Updated: 2025/01/24 15:12:36 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_data	*ft_new_op(char *str)
{
	t_data	*new;

	new = malloc(sizeof(t_data));
	if (!new)
		return (NULL);
	new->ops = str;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_op(t_data **lst, t_data *new)
{
	t_data	*last;

	if (!lst)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
}

void	ft_clear_ops(t_data **lst)
{
	t_data	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->ops);
		free((*lst));
		(*lst) = tmp;
	}
}
