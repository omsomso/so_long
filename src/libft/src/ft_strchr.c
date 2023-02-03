/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24                               #+#    #+#             */
/*   Updated: 2023/01/25                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	tmp;

	i = -1;
	tmp = (unsigned char) c;
	while (i == -1 || s[i])
	{
		i++;
		if (s[i] == tmp)
			return ((char *) &s[i]);
	}
	return (NULL);
}

/*int	main(void)
{
	char	str1[] = "tst1e";
	int		c = 1024;
	int		d = 357; //somethign with char limits
	
	printf("%s\n%s\n", ft_strchr(str1, c), strchr(str1, c));
	printf("%s\n%s\n", ft_strchr(str1, d), strchr(str1, d));
	c = '\0';
	printf("%s\n%s\n", ft_strchr(str1, c), strchr(str1, c));
	return (0);
}*/