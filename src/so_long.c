/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 00:45:30 by kpawlows          #+#    #+#             */
/*   Updated: 2023/03/01 17:51:11 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdio.h>

void	free_map(char **map, int y)
{
	int	i;

	i = 0;
	while (i <= y)
	{
		if (map[i] != NULL)
			free(map[i]);
		i++;
	}
	if (map != NULL)
		free(map);
}

void	free_everything(t_data *data)
{
	if (data->map != NULL)
		free_map(data->map, data->y);
	if (data->path != NULL)
		free_map(data->path, data->y);
	if (data->pathit != NULL)
		free_map(data->pathit, data->y);
	if (data->p_name != NULL)
		free(data->p_name);
	if (data->f_name != NULL)
		free(data->f_name);
	if (data->end != 0)
	{
		mlx_destroy_image(data->mlx, data->bckg);
		mlx_destroy_image(data->mlx, data->wall);
		mlx_destroy_image(data->mlx, data->item);
		mlx_destroy_image(data->mlx, data->counter_bckg);
	}
	if (data != NULL)
		free(data);
}

int	quit(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	free_everything(data);
	exit (0);
}

void	start_window_n_hooks(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, (data->x + 1) * 32, \
	(data->y + 1) * 32, "Chicken Lite");
	init_img(data);
	mlx_hook(data->win, EVENT_KEYPRESS, 0, &handle_keypress, data);
	mlx_hook(data->win, EVENT_KEYRELEASE, 0, &handle_keyrelease, data);
	mlx_hook(data->win, EVENT_DESTROY, 0, &quit, data);
	mlx_loop(data->mlx);
}

void	so_long(char *s)
{
	t_data	*data;

	data = NULL;
	data = malloc(sizeof(t_data));
	data->map = NULL;
	if (data == NULL)
		return ;
	data->p_name = NULL;
	data->f_name = NULL;
	if (read_map_init(data, s, 0, 0) == 0 || check_map_filename(s) == 0)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Invalid file. Check its name and extension.", 2);
		free_everything(data);
		return ;
	}
	find_sprite_pos(data, 0, 0);
	if (check_map_error(data) == 0)
	{
		free_everything(data);
		return ;
	}
	start_window_n_hooks(data);
	return ;
}
