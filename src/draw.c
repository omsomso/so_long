/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 00:42:35 by kpawlows          #+#    #+#             */
/*   Updated: 2023/02/02 22:42:53 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_background(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i <= data->y)
	{
		while (j <= data->x)
		{
			mlx_put_image_to_window(data->mlx, data->win, \
			data->bckg, j * 32, i * 32);
			if (data->map[i][j] == '1' && data->end == 0)
				mlx_put_image_to_window(data->mlx, data->win, \
				data->wall, j * 32, i * 32);
			if (data->map[i][j] == 'C' && data->end == 0)
				mlx_put_image_to_window(data->mlx, data->win, \
				data->item, j * 32, i * 32);
			j++;
		}
		j = 0;
		i++;
	}
}

void	animate_players(t_data *data)
{
	free(data->p_name);
	free(data->f_name);
	if (data->p_dir == 1)
	{
		if (data->anim_frame % 2 == 0)
			data->p_name = ft_strdup("sprites/player_r_1.xpm");
		if (data->anim_frame % 2 != 0)
			data->p_name = ft_strdup("sprites/player_r_2.xpm");
		if (data->anim_frame % 2 == 0)
			data->f_name = ft_strdup("sprites/foe_r_1.xpm");
		if (data->anim_frame % 2 != 0)
			data->f_name = ft_strdup("sprites/foe_r_2.xpm");
	}
	if (data->p_dir == 0)
	{
		if (data->anim_frame % 2 == 0)
			data->p_name = ft_strdup("sprites/player_l_1.xpm");
		if (data->anim_frame % 2 != 0)
			data->p_name = ft_strdup("sprites/player_l_2.xpm");
		if (data->anim_frame % 2 == 0)
			data->f_name = ft_strdup("sprites/foe_l_1.xpm");
		if (data->anim_frame % 2 != 0)
			data->f_name = ft_strdup("sprites/foe_l_2.xpm");
	}
}

int	draw_players(t_data *data)
{
	int		width;
	int		height;
	void	*p_img;
	void	*f_img;

	p_img = mlx_xpm_file_to_image(data->mlx, data->p_name, &width, &height);
	mlx_put_image_to_window(data->mlx, data->win, p_img, data->px * 32, \
	data->py * 32);
	mlx_destroy_image(data->mlx, p_img);
	if (data->foe == 1)
	{
		f_img = mlx_xpm_file_to_image(data->mlx, data->f_name, &width, &height);
		mlx_put_image_to_window(data->mlx, data->win, f_img, (data->fx) * 32, \
		(data->fy) * 32);
		mlx_destroy_image(data->mlx, f_img);
	}
	return (0);
}

void	draw_exit(t_data *data, char *filename)
{
	int		len;
	int		len2;
	void	*exit_img;

	exit_img = mlx_xpm_file_to_image(data->mlx, filename, &len, &len2);
	mlx_put_image_to_window(data->mlx, data->win, exit_img, data->ex * 32 - 20, \
	data->ey * 32 - 45);
	mlx_destroy_image(data->mlx, exit_img);
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
