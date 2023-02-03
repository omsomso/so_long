/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:15:32 by kpawlows          #+#    #+#             */
/*   Updated: 2023/01/31 19:34:49 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_get_line(char **rest)
{
	int		len;
	char	*out;
	char	*tmp;

	len = gnl_strlen(*rest);
	out = NULL;
	if (gnl_find_char(*rest, '\n', len) == 0 && rest[0][0] != '\n')
	{
		if (*rest[0] != '\0')
			out = gnl_substr(*rest, 0, gnl_find_char(*rest, '\0', len));
		free(*rest);
		*rest = NULL;
		return (out);
	}
	out = gnl_substr(*rest, 0, gnl_find_char(*rest, '\n', len) + 1);
	tmp = gnl_substr(*rest, gnl_find_char(*rest, '\n', len) + 1, len);
	free(*rest);
	*rest = gnl_substr(tmp, 0, gnl_strlen(tmp));
	free(tmp);
	return (out);
}

void	gnl_read_buffer(char **rest, int fd)
{
	char	*buf;
	char	*tmp;
	int		pos;

	pos = 1;
	while (pos > 0)
	{
		buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
		pos = read(fd, buf, BUFFER_SIZE);
		if (pos == -1)
			buf[0] = '\0';
		else
			buf[pos] = '\0';
		tmp = gnl_strjoin(rest[0], buf);
		free(buf);
		free(rest[0]);
		rest[0] = gnl_substr(tmp, 0, gnl_strlen(tmp));
		free(tmp);
		if (gnl_find_char(rest[0], '\n', gnl_strlen(rest[0])))
			break ;
	}
}

char	*get_next_line(int fd)
{
	static char		*rest;
	char			*out;

	out = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!rest)
	{
		rest = malloc(1);
		rest[0] = '\0';
	}
	gnl_read_buffer(&rest, fd);
	out = gnl_get_line(&rest);
	if (out == NULL)
		return (NULL);
	return (out);
}
