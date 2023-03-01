/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 00:44:50 by kpawlows          #+#    #+#             */
/*   Updated: 2023/03/01 18:01:19 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_map_char(char c)
{
	if (c == '1' || c == '0' || c == 'P' || c == 'E'
		|| c == 'C' || c == 'F' || c == '\0')
		return (0);
	return (1);
}

char	check_map_additional(t_data *data)
{
	if (data->py == 0 || data->items == 0 || data->ey == 0)
		return ('N');
	if (check_path(data, data->py, data->px) == 0)
	{
		free_map(data->path, data->y);
		return ('V');
	}
	if (check_item_path(data, data->py, data->px) != data->items)
	{
		free_map(data->path, data->y);
		free_map(data->pathit, data->y);
		return ('V');
	}
	return (1);
}

char	check_map(t_data *data, int i, int j)
{
	if (check_map_borders(data, 0, 0) == 0)
		return ('B');
	while (++i <= data->y)
	{
		while (data->map[i][++j] != '\n' || data->map[i][j] != '\0')
		{
			if (data->map[i][j] == '\0' || data->map[i][j] == '\n')
				break ;
			if (j > data->x)
				return ('L');
			if (data->map[i][j] == 'C')
				data->items++;
			if (data->map[i][j] == 'E' && !(i == data->ey && j == data->ex))
				return ('E');
			if (data->map[i][j] == 'P' && !(i == data->py && j == data->px))
				return ('P');
			if (data->map[i][j] == 'F' && !(i == data->fy && j == data->fx - 1))
				return ('F');
			if (check_map_char(data->map[i][j]) == 1)
				return ('X');
		}
		j = -1;
	}
	return (check_map_additional(data));
}

int	check_map_filename(char *s)
{
	char	*test;
	int		i;

	i = 0;
	test = ft_strdup(".ber");
	while (s[i] != 0)
	{
		if (s[i] == '.')
		{
			if (ft_strncmp(&s[i], test, 5) == 0)
			{
				free(test);
				return (1);
			}
		}
		i++;
	}
	free(test);
	return (0);
}

int	check_map_error(t_data *data)
{
	char	c;

	c = check_map(data, -1, -1);
	if (c == 1)
		return (1);
	ft_putendl_fd("Error", 2);
	if (c == 'X')
		ft_putendl_fd("There's 1 or + forbidden characters in the map.", 2);
	if (c == 'L')
		ft_putendl_fd("The map isn't a rectangle.", 2);
	if (c == 'E')
		ft_putendl_fd("The map has more than one exit (E).", 2);
	if (c == 'P')
		ft_putendl_fd("The map has more than one player (P) character.", 2);
	if (c == 'F')
		ft_putendl_fd("The map has more than one foe (F) character.", 2);
	if (c == 'N')
		ft_putendl_fd("The map lacks a necessary element.", 2);
	if (c == 'B')
		ft_putendl_fd("The map's borders aren't closed with walls or smth.", 2);
	if (c == 'V')
		ft_putendl_fd("There's no valid path in the map.", 2);
	return (0);
}
