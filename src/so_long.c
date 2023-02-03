/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 00:45:30 by kpawlows          #+#    #+#             */
/*   Updated: 2023/02/03 10:59:41 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_everything(t_data *data)
{
	int	i;

	i = -1;
	while (i++ < data->y)
	{
		free(data->map[i]);
		free(data->path[i]);
	}
	free(data->map);
	free(data->path);
	free(data->p_name);
	free(data->f_name);
	mlx_destroy_image(data->mlx, data->bckg);
	mlx_destroy_image(data->mlx, data->wall);
	mlx_destroy_image(data->mlx, data->item);
	if (data != NULL)
		free(data);
}

int	quit(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	free_everything(data);
	exit (0);
}

void	so_long(char *s)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (read_map_init(data, s, 0, 0) == 0 || check_map_filename(s) == 0)
	{
		ft_putendl_fd("Error\ncan't open file", 2);
		return ;
	}
	find_sprite_pos(data, 0, 0);
	if (check_map_error(data) == 0)
		return ;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, (data->x + 1) * 32, \
	(data->y + 1) * 32, "Chicken vs Antichicken");
	init_img(data);
	mlx_hook(data->win, EVENT_KEYPRESS, 0, &handle_keypress, data);
	mlx_hook(data->win, EVENT_KEYRELEASE, 0, &handle_keyrelease, data);
	mlx_hook(data->win, EVENT_DESTROY, 0, &quit, data);
	mlx_loop(data->mlx);
	return ;
}
