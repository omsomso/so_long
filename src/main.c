/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 00:46:20 by kpawlows          #+#    #+#             */
/*   Updated: 2023/02/02 22:56:30 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	char	*tmp;

	if (argc != 2)
	{
		ft_putendl_fd("Error : can't open file", 2);
		return (1);
	}
	tmp = ft_strdup(argv[1]);
	so_long(tmp);
	free(tmp);
	return (0);
}
