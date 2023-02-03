/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24                               #+#    #+#             */
/*   Updated: 2023/01/25                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*tmp;
	size_t	i;

	tmp = s;
	i = 0;
	if (!n)
		return ;
	while (i < n)
	{
		tmp[i] = 0;
		i++;
	}
}

/*int	main(void)
{
	char str1[] = "imagination";
	char str2[] = "imagination";

	ft_bzero(str1, 4);
	bzero(str2, 4);
	printf("%s\n", str1);
	printf("%s\n", str2);
	return (0);
}*/