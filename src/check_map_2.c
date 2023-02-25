/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 00:45:57 by kpawlows          #+#    #+#             */
/*   Updated: 2023/02/25 18:48:30 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_path(t_data *data, int i, int j)
{
	static int	ret = 0;

	if (data->path[i][j] == 'E')
		return (1);
	if (ret > 0)
		return (1);
	if (j <= 0 || i <= 0 || i >= data->y || j >= data->x)
		return (0);
	data->path[i][j] = 'X';
	if (data->path[i][j + 1] != '1' && data->path[i][j + 1] != 'X')
		ret = check_path(data, i, j + 1);
	if (data->path[i][j - 1] != '1' && data->path[i][j - 1] != 'X')
		ret = check_path(data, i, j - 1);
	if (data->path[i + 1][j] != '1' && data->path[i + 1][j] != 'X')
		ret = check_path(data, i + 1, j);
	if (data->path[i - 1][j] != '1' && data->path[i - 1][j] != 'X')
		ret = check_path(data, i - 1, j);
	return (ret);
}

int	check_item_path(t_data *data, int i, int j)
{
	static int	ret = 0;

	if (data->pathit[i][j] == 'C')
	{
		data->pathit[i][j] = 'X';
		ret++;
	}
	data->pathit[i][j] = 'X';
	if (data->pathit[i][j + 1] != '1' && data->pathit[i][j + 1] != 'X')
		check_item_path(data, i, j + 1);
	if (data->pathit[i][j - 1] != '1' && data->pathit[i][j - 1] != 'X')
		check_item_path(data, i, j - 1);
	if (data->pathit[i + 1][j] != '1' && data->pathit[i + 1][j] != 'X')
		check_item_path(data, i + 1, j);
	if (data->pathit[i - 1][j] != '1' && data->pathit[i - 1][j] != 'X')
		check_item_path(data, i - 1, j);
	return (ret);
}

int	check_map_borders(t_data *data, int i, int j)
{
	while (j <= data->x)
	{
		if (data->map[0][j] != '1' || data->map[data->y][j] != '1')
			return (0);
		j++;
	}
	while (i <= data->y)
	{
		if (data->map[i][0] != '1' || data->map[i][data->x] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	copy_map(t_data *data)
{
	int	y;

	y = 0;
	data->path = malloc(sizeof(char *) * data->y + 1);
	if (data->path == NULL)
		return ;
	while (y <= data->y)
	{
		data->path[y] = ft_strdup(data->map[y]);
		y++;
	}
	data->pathit = malloc(sizeof(char *) * data->y + 1);
	if (data->pathit == NULL)
		return ;
	y = 0;
	while (y <= data->y)
	{
		data->pathit[y] = ft_strdup(data->map[y]);
		y++;
	}
	return ;
}
