/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25                               #+#    #+#             */
/*   Updated: 2023/01/25                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	ft_tolower(int c)
{
	if (ft_isupper(c) == 1)
		return (c + 32);
	return (c);
}

/*int	main(void)
{
	char	c = 'T';

	printf("%c\n", ft_tolower(c));
	printf("%c\n", tolower(c));
}*/