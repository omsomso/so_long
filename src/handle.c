/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 00:48:48 by kpawlows          #+#    #+#             */
/*   Updated: 2023/02/06 12:35:57 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	handle_movement(int key, t_data *data)
{
	set_player_direction(key, data);
	if ((key == KEY_AR || key == KEY_D) && data->move == 1)
		data->px++;
	if ((key == KEY_AL || key == KEY_A) && data->move == 1)
		data->px--;
	if ((key == KEY_AD || key == KEY_S) && data->move == 1)
		data->py++;
	if ((key == KEY_AU || key == KEY_W) && data->move == 1)
		data->py--;
	if (data->map[data->py][data->px] == 'C')
	{
		data->map[data->py][data->px] = '0';
		data->items_collected++;
	}
	if ((key <= 127 && key >= 123) || (key <= 3 && key >= 0) || key == KEY_W)
		draw_sprites(data);
	if (data->py == data->fy && data->px == data->fx)
		data->end = -1;
	if (data->map[data->py][data->px] == 'E'
			&& data->items_collected == data->items)
		data->end = 1;
}

int	handle_keypress(int key, t_data *data)
{
	if (key == KEY_ESC)
		quit(data);
	data->move = check_allowed_move(key, data);
	if (data->end == 0)
		handle_movement(key, data);
	if (data->end != 0)
		handle_end(data, 0, 0, 0);
	return (0);
}

void	draw_sprites(t_data *data)
{
	data->anim_frame++;
	mlx_clear_window(data->mlx, data->win);
	draw_background(data);
	add_counter(data);
	if (data->foe == 1)
		position_foe(data);
	animate_players(data);
	draw_players(data);
	draw_exit(data, "sprites/exit.xpm");
	draw_counter(data);
}

int	handle_keyrelease(int key, t_data *data)
{
	(void) key;
	if (data->end == 0)
	{
		data->anim_frame++;
		mlx_clear_window(data->mlx, data->win);
		draw_background(data);
		animate_players(data);
		draw_players(data);
		draw_exit(data, "sprites/exit.xpm");
		draw_counter(data);
	}
	return (1);
}

void	handle_end(t_data *data, int w, int h, int midx)
{
	void		*e;
	static int	freeze = 0;

	if (freeze == 0)
	{
		mlx_clear_window(data->mlx, data->win);
		draw_background(data);
		if (data->x <= 10 && data->end == -1)
		e = mlx_xpm_file_to_image(data->mlx, "sprites/los.xpm", &w, &h);
		if (data->x <= 10 && data->end == 1)
			e = mlx_xpm_file_to_image(data->mlx, "sprites/win.xpm", &w, &h);
		if (data->x > 10 && data->end == -1)
			e = mlx_xpm_file_to_image(data->mlx, "sprites/los_l.xpm", &w, &h);
		if (data->x > 10 && data->end == 1)
			e = mlx_xpm_file_to_image(data->mlx, "sprites/win_l.xpm", &w, &h);
		midx = (data->x * 32) / 2 - (w / 2);
		mlx_put_image_to_window(data->mlx, data->win, e, midx, 0);
		add_counter(data);
		draw_counter(data);
		ft_putendl_fd("//art by shubibubi and Elthen on itch.io//", 1);
		ft_putendl_fd("\t////press exit to quit////", 1);
		mlx_destroy_image(data->mlx, e);
	}
	if (data->end != 0)
		freeze = 1;
}
