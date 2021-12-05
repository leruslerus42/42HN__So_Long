/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrajaobe <rrajaobe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 08:35:34 by rrajaobe          #+#    #+#             */
/*   Updated: 2021/12/05 02:25:01 by rrajaobe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
*	Return minum 1, because should be at least 1 column and row in the map
*/

int	ft_my_strchr(const char *s, int c)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	i = 1;
	return (i);
}

/*
*	A modified version of get next line. I store all map as a line in the buffer,
*	setting the Buffersize to 1000. I already know that due to screen size,
*	the numbers of columns and rows should be limited.
*/
char	*get_next_line(int fd)
{
	char		*buf;
	int			b;
	int			BUFFER_SIZE;

	BUFFER_SIZE = 1000;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = NULL;
	buf = malloc (sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	b = read(fd, buf, BUFFER_SIZE);
	if (b <= 0)
	{
		free(buf);
		buf = NULL;
		return (0);
	}
	buf[b] = '\0';
	return (buf);
}
