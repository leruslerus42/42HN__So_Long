/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrajaobe <rrajaobe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 08:35:34 by rrajaobe          #+#    #+#             */
/*   Updated: 2021/12/05 22:31:31 by rrajaobe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*rest_check(char **rest)
{
	char	*current_line;
	char	*temp;
	int		new_line_position;

	current_line = NULL;
	new_line_position = ft_my_strchr(*rest, '\n');
	if ((new_line_position >= 0))
	{
		temp = ft_strdup(&rest[0][new_line_position + 1]);
		current_line = ft_substr(*rest, 0, new_line_position + 1);
		free(*rest);
		*rest = ft_strdup(temp);
		free(temp);
		return (current_line);
	}
	if (*rest[0] != '\0')
		current_line = ft_strdup(*rest);
	free(*rest);
	*rest = NULL;
	return (current_line);
}

static char	*buffer_check(int fd, char *buf, char **rest, int b)
{
	char	*temp;

	while (b > 0)
	{
		buf[b] = '\0';
		if (!(*rest))
			*rest = ft_strdup(buf);
		else
		{
			temp = ft_strjoin(*rest, buf);
			free(*rest);
			*rest = ft_strdup(temp);
			free(temp);
		}
		if (ft_my_strchr(buf, '\n') >= 0)
			break ;
		else
			b = read (fd, buf, BUFFER_SIZE);
	}
	free (buf);
	buf = NULL;
	return (rest_check(rest));
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*rest;
	int			b;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = NULL;
	buf = malloc (sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	b = read(fd, buf, BUFFER_SIZE);
	if (b <= 0)
	{
		if (rest == 0)
		{
			free(buf);
			buf = NULL;
			return (0);
		}
	}
	return (buffer_check(fd, buf, &rest, b));
}
