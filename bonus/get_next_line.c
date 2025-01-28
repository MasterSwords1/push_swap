/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 01:19:13 by ariyad            #+#    #+#             */
/*   Updated: 2025/01/23 19:40:11 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	has_line(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static ssize_t	nl_index(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (i - 1);
}

static char	*get_line(char *str, int fd)
{
	char	*tmp;
	ssize_t	buff;
	int		sw;

	sw = has_line(str);
	while (!sw)
	{
		tmp = str;
		str = malloc((size_t)1 + 1);
		if (!str)
			return (free(tmp), NULL);
		buff = read(fd, str, 1);
		if (buff < 0 || buff == 0)
			return (free(str), tmp);
		str[buff] = 0;
		if (has_line(str))
			sw = 1;
		str = ft_strjoin_plus(tmp, str);
		if (!str)
			return (free(tmp), NULL);
		tmp = NULL;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char	*str;
	char	*line;
	char	*tmp;

	if (fd < 0)
		return (NULL);
	str = NULL;
	str = get_line(str, fd);
	if (!str)
		return (NULL);
	line = ft_substr(str, 0, nl_index(str) + 1);
	if (!line)
		return (free(str), str = NULL, NULL);
	tmp = str;
	str = ft_strdup(&tmp[nl_index(tmp) + 1]);
	if (!str)
		return (free(tmp), free(line), NULL);
	free(tmp);
	tmp = NULL;
	free(str);
	return (line);
}
