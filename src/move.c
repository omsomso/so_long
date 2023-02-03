/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 00:40:25 by kpawlows          #+#    #+#             */
/*   Updated: 2023/02/03 07:53:49 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_player_direction(int key, t_data *data)
{
	if (key == KEY_AR || key == KEY_D)
		data->p_dir = 1;
	if (key == KEY_AL || key == KEY_A)
		data->p_dir = 0;
}

int	check_allowed_move(int key, t_data *data)
{
	if (key == KEY_AR || key == KEY_D)
	{
		if (data->map[data->py][data->px + 1] == '1')
			return (0);
	}
	if (key == KEY_AL || key == KEY_A)
	{
		if (data->map[data->py][data->px - 1] == '1')
			return (0);
	}
	if (key == KEY_AU || key == KEY_W)
	{
		if (data->map[data->py - 1][data->px] == '1')
			return (0);
	}
	if (key == KEY_AD || key == KEY_S)
	{
		if (data->map[data->py + 1][data->px] == '1')
			return (0);
	}	
	return (1);
}

void	position_foe(t_data *data)
{
	if (data->px > data->fx && data->map[data->fy][data->fx + 1] != '1')
		data->fx++;
	else if (data->py > data->fy && data->map[data->fy + 1][data->fx] != '1')
		data->fy++;
	else if (data->py < data->fy && data->map[data->fy - 1][data->fx] != '1')
		data->fy--;
	else if (data->px < data->fx && data->map[data->fy][data->fx - 1] != '1')
		data->fx--;
}

void	draw_counter(t_data *data)
{
	char	*display[3];
	char	*items[3];
	void	*counter_bckg;
	int		wi;
	int		hi;

	display[0] = ft_strjoin("Moves : ", ft_itoa(data->counter));
	display[1] = ft_strjoin(display[0], " ");
	items[0] = ft_strjoin("Items : ", ft_itoa(data->items_collected));
	items[1] = ft_strjoin(items[0], "/");
	items[2] = ft_strjoin(items[1], ft_itoa(data->items));
	display[2] = ft_strjoin(display[1], items[2]);
	counter_bckg = mlx_xpm_file_to_image(data->mlx, \
	"sprites/counter_bckg.xpm", &wi, &hi);
	mlx_put_image_to_window(data->mlx, data->win, counter_bckg, 0, 0);
	mlx_string_put(data->mlx, data->win, 2, 13, 0x000000, display[2]);
	mlx_destroy_image(data->mlx, counter_bckg);
	free(display[0]);
	free(display[1]);
	free(display[2]);
	free(items[0]);
	free(items[1]);
	free(items[2]);
}

void	add_counter(t_data *data)
{
	if (data->move == 1)
		data->counter++;
}
