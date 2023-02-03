/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12                               #+#    #+#             */
/*   Updated: 2023/01/25                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*void	f(unsigned int n, char *c)
{
	(void) n;
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

/*int	main(void)
{
	char	*s;

	s = malloc(sizeof(char) * 8);
	strcpy(s, "yOlooOo");
	ft_striteri(s, f);
	printf("s = %s\n", s);
	return (0);
}*/
