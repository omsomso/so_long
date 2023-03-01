/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:07:13 by kpawlows          #+#    #+#             */
/*   Updated: 2023/03/02 00:27:22 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	gnl_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	gnl_find_char(const char *s, int c, int n)
{
	int				i;
	unsigned char	tmp;

	i = -1;
	tmp = (unsigned char) c;
	while (i == -1 || s[i] || i < n)
	{
		i++;
		if (s[i] == tmp)
			return (i);
	}
	return (0);
}

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*sub;

	i = 0;
	if (!s)
		return (NULL);
	slen = gnl_strlen(s);
	if (start + len > slen)
		len = slen;
	sub = malloc(sizeof(char) * len + 1);
	if (!sub)
	{
		free(sub);
		return (NULL);
	}
	while (start < slen && i < len)
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	s1len;
	size_t	s2len;
	char	*join;

	i = -1;
	j = 0;
	s1len = gnl_strlen(s1);
	s2len = gnl_strlen(s2);
	join = malloc(sizeof(char) * (s1len + s2len) + 1);
	if (join == NULL)
		return (NULL);
	while (++i < s1len)
		join[i] = s1[i];
	while (j < s2len)
	{
		join[i] = s2[j];
		i++;
		j++;
	}
	join[i] = '\0';
	return (join);
}
