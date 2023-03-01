/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 04:18:42 by kpawlows          #+#    #+#             */
/*   Updated: 2023/03/01 17:09:57 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_img(t_data *data)
{
	int	x;
	int	y;

	data->bckg = mlx_xpm_file_to_image(data->mlx, "sprites/dirt.xpm", &x, &y);
	data->wall = mlx_xpm_file_to_image(data->mlx, "sprites/wall.xpm", &x, &y);
	data->item = mlx_xpm_file_to_image(data->mlx, "sprites/item.xpm", &x, &y);
	data->counter_bckg = mlx_xpm_file_to_image(data->mlx, \
	"sprites/counter_bckg.xpm", &x, &y);
	draw_sprites(data);
}

void	find_sprite_pos(t_data *data, int i, int j)
{
	while (i < data->y)
	{
		while (j < data->x)
		{
			if (data->map[i][j] == 'P')
			{
				data->px = j;
				data->py = i;
			}
			if (data->map[i][j] == 'E')
			{
				data->ex = j;
				data->ey = i;
			}
			if (data->map[i][j] == 'F')
			{
				data->foe = 1;
				data->fx = j + 1;
				data->fy = i;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	init_data(t_data *data, int x, int y)
{
	data->y = y - 1;
	data->x = x - 2;
	data->counter = 0;
	data->items = 0;
	data->items_collected = 0;
	data->py = 0;
	data->ey = 0;
	data->p_dir = 0;
	data->move = 0;
	data->anim_frame = 0;
	data->foe = 0;
	data->end = 0;
	data->p_name = ft_strdup("sprites/player_l_1.xpm");
	data->f_name = ft_strdup("sprites/foe_l_1.xpm");
	copy_map(data);
}

int	find_map_height(char *s)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(s, O_RDONLY);
	if (fd < 0)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
		i++;
	}
	close(fd);
	return (i);
}

int	read_map_init(t_data *data, char *s, int y, int x)
{
	int	fd;
	int	height;

	height = find_map_height(s);
	data->map = NULL;
	fd = open(s, O_RDONLY);
	data->map = malloc(sizeof(char *) * height + 1);
	data->map[0] = NULL;
	if (height <= 2)
		return (0);
	if (data->map == NULL)
		return (0);
	while (1)
	{
		data->map[y] = NULL;
		data->map[y] = get_next_line(fd);
		if (data->map[y] == NULL)
			break ;
		y++;
	}
	while (data->map[0][x] != '\0')
		x++;
	init_data(data, x, y);
	return (1);
}
