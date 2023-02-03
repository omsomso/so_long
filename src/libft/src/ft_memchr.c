/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24                               #+#    #+#             */
/*   Updated: 2023/01/25                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*s2;
	char		tmp;

	i = 0;
	tmp = (char) c;
	if (!s)
		return (NULL);
	s2 = s;
	while (i < n)
	{
		if (s2[i] == tmp)
			return ((void *) &s2[i]);
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	char	str1[] = "abcde";
	char	*str2;
	char	*str3;
	int		n = 'b' + 1024;
	
	//printf("%s -> mine \n%s -> og\n", ft_memchr((void*)0, '\0', 1), 
		memchr("yo", '\0', 1));//wtf
	str2 = ft_memchr(str1, 'c', n);
	str3 = memchr(str1, 'c', n);
	printf("%s\n%s\n", str2, str3);
	return (0);
}*/