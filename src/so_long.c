/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 00:45:30 by kpawlows          #+#    #+#             */
/*   Updated: 2023/02/24 07:43:08 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdio.h>

void	free_map(t_data *data, int st)
{
	int	i;

	i = 0;
	while (i <= data->y)
	{
		if (data->map[i] != NULL)
			free(data->map[i]);
		i++;
	}
	if (data->map != NULL)
		free(data->map);
	if (st == 1)
		free(data);
}

void	free_everything(t_data *data)
{
	int	i;

	i = 0;
	free_map(data, 0);
	while (i <= data->y)
	{
		free(data->path[i]);
		i++;
	}
	free(data->path);
	free(data->p_name);
	free(data->f_name);
	mlx_destroy_image(data->mlx, data->bckg);
	mlx_destroy_image(data->mlx, data->wall);
	mlx_destroy_image(data->mlx, data->item);
	mlx_destroy_image(data->mlx, data->counter_bckg);
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
	if (data == NULL)
		return ;
	if (read_map_init(data, s, 0, 0) == 0 || check_map_filename(s) == 0)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Invalid file. Check its name and extension.", 2);
		free_map(data, 1);
		return ;
	}
	find_sprite_pos(data, 0, 0);
	if (check_map_error(data) == 0)
	{
		free_map(data, 1);
		return ;
	}
	start_window_n_hooks(data);
	return ;
}
