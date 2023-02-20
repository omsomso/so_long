/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 00:40:25 by kpawlows          #+#    #+#             */
/*   Updated: 2023/02/21 00:15:33 by kpawlows         ###   ########.fr       */
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
	char	*display;
	char	*items;
	char	*items_collected;
	char	*items_all;
	char	*moves;

	moves = ft_itoa(data->counter);
	items_collected = ft_itoa(data->items_collected);
	items_all = ft_itoa(data->items);
	display = ft_strjoin("Moves : ", moves);
	display = ft_strjoin_free(display, " ");
	items = ft_strjoin("Items : ", items_collected);
	items = ft_strjoin_free(items, "/");
	items = ft_strjoin_free(items, items_all);
	display = ft_strjoin_free(display, items);
	mlx_put_image_to_window(data->mlx, data->win, data->counter_bckg, 0, 0);
	mlx_string_put(data->mlx, data->win, 2, 13, 0x000000, display);
	free(moves);
	free(items_all);
	free(items_collected);
	free(display);
	free(items);
}

void	add_counter(t_data *data)
{
	if (data->move == 1 && data->end == 0)
		data->counter++;
}
