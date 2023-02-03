/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20                               #+#    #+#             */
/*   Updated: 2022/11/26                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 24
# endif

char	*get_next_line(int fd);
void	gnl_read_buffer(char **rest, int fd);
char	*gnl_get_line(char **rest);
int		gnl_strlen(const char *s);
char	*gnl_substr(char const *s, unsigned int start, size_t len);
char	*gnl_strjoin(char const *s1, char const *s2);
int		gnl_find_char(const char *s, int c, int n);

#endif