/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 17:44:23 by kpawlows          #+#    #+#             */
/*   Updated: 2023/01/25 18:50:38 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while ((s1[i] == s2[i]) && i < (n - 1) && (s1[i] != '\0' && s2[i] != '\0'))
		i++;
	if (s1[i] != s2[i])
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

/*int main(void)
{
	size_t	n;

	char *tab1 = "";
	char *tab2 = "AAAAAA";
	//n = strlen("the cake is a lie !\0I'm hidden lol\r\n");
	n = 6;
	printf("%d \n", ft_strncmp(tab1, tab2, n));
	printf("%d \n", strncmp(tab1, tab2, n));
	return (0);
}*/