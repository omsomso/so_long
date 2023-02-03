/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:31:14 by kpawlows          #+#    #+#             */
/*   Updated: 2023/02/03 01:32:58 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_matrix(char **m, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	printf("===x = %d, y = %d===\n", x, y);
	while (i < y)
	{
		while (j < x)
		{
			printf("%c ", m[i][j]);
			j++;
		}
		j = 0;
		i++;
		printf("\n");
	}
}
