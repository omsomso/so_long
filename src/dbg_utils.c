/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:31:14 by kpawlows          #+#    #+#             */
/*   Updated: 2023/02/03 10:59:33 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_matrix(char **m, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= y)
	{
		while (j <= x)
		{
			ft_putchar_fd(m[i][j], 1);
			j++;
		}
		j = 0;
		i++;
		ft_putchar_fd('\n', 1);
	}
}
