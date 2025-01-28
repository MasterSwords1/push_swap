/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:12:16 by ariyad            #+#    #+#             */
/*   Updated: 2025/01/20 11:14:46 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_issep(char s, char c)
{
	return (s == c || s == '\0');
}

static size_t	word_c(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (!ft_issep(s[i], c) && ft_issep(s[i + 1], c))
			count++;
		i++;
	}
	return (count);
}

void	free_table(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
}

static int	ft_fill(char **split, const char *s, char sep)
{
	size_t	i;
	size_t	pos;
	size_t	count;

	i = 0;
	pos = 0;
	count = 0;
	while (s[i])
	{
		if (!ft_issep(s[i], sep) && ft_issep(s[i + 1], sep))
		{
			split[pos] = ft_substr(s, i - count, count + 1);
			if (!split[pos++])
				return (free_table(split), 0);
			count = -1;
		}
		if (!ft_issep(s[i], sep))
			count++;
		i++;
	}
	split[pos] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = (char **)malloc((word_c(s, c) + 1) * sizeof(char *));
	if (!split || !ft_fill(split, s, c))
		return (NULL);
	return (split);
}
