/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25                               #+#    #+#             */
/*   Updated: 2023/01/25                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*sub;

	i = 0;
	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start + len > slen)
		len = slen;
	sub = malloc(sizeof(char) * len + 1);
	if (!sub)
		return (NULL);
	while (start < slen && i < len)
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}

/*int main(void)
{
	char    str1[] = "tripouille";
	//int		start = 0; //len = 1;

	printf("%s\n", ft_substr(str1, 0, 42000));
	//printf("%s\n", ft_substr(str1, 3, 7));
	//printf("%s\n", substr(str1, 2, 2));
	return (0);
}*/