/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:07:55 by ariyad            #+#    #+#             */
/*   Updated: 2025/01/28 19:08:18 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && (s1[i] || s2[i]))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\v' || c == '\n'
		|| c == '\r' || c == '\f');
}

static int	check_of(char *s, int sign)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (s[i] == '0')
		i++;
	while (s[i + k] >= '0' && s[i + k] <= '9')
		k++;
	if (k > ft_strlen("2147483647"))
		return (write(2, "Error\n", 7), 0);
	if (k == ft_strlen("2147483648") && sign == -1
		&& ft_strncmp(&s[i], "2147483648", k) > 0)
		return (write(2, "Error\n", 7), 0);
	else if (k == ft_strlen("2147483647") && sign == 1
		&& ft_strncmp(&s[i], "2147483647", k) > 0)
		return (write(2, "Error\n", 7), 0);
	return (1);
}

int	ft_atoi_plus(char *str, t_list **stack_a, char **nbrs)
{
	size_t	i;
	long	num;
	int		sign;

	(1) && (i = 0, num = 0, sign = 1);
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!check_of(&str[i], sign))
		return (ft_lstclear(stack_a), free_table(nbrs), exit(1), 0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - 48);
		i++;
	}
	if (str[i] != '\0')
		return (write(2, "Error\n", 7), ft_lstclear(stack_a),
			free_table(nbrs), exit(1), 0);
	return (sign * num);
}
