/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 00:53:07 by kpawlows          #+#    #+#             */
/*   Updated: 2023/02/03 11:01:27 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include "src/mlx/mlx.h"
# include "src/libft/libft.h"
# include "src/gnl/get_next_line.h"

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*bckg;
	void	*wall;
	void	*item;
	int		px;
	int		py;
	int		ex;
	int		ey;
	int		fx;
	int		fy;
	int		foe;
	int		end;
	int		move;
	int		p_dir;
	int		items;
	int		items_collected;
	int		x;
	int		y;
	int		counter;
	int		anim_frame;
	char	**map;
	char	**path;
	char	*p_name;
	char	*f_name;
}	t_data;

# define KEY_ESC 53
# define KEY_AR	124
# define KEY_AL	123
# define KEY_AU	126
# define KEY_AD	125
# define KEY_W	13
# define KEY_A	0
# define KEY_S	1
# define KEY_D	2

# define EVENT_KEYPRESS 2
# define EVENT_KEYRELEASE 3
# define EVENT_DESTROY 17

void	print_matrix(char **m, int x, int y);
void	free_everything(t_data *data);
int	draw_players(t_data *data);
void	animate_players(t_data *data);
void	init_img(t_data *data);
void	position_foe(t_data *data);
void	draw_counter(t_data *data);
void	add_counter(t_data *data);
void	draw_background(t_data *data);
void	draw_exit(t_data *data, char *filename);
void	draw_sprites(t_data *data);
int	handle_keyrelease(int key, t_data *data);
void	find_sprite_pos(t_data *data, int i, int j);
void	handle_end(t_data *data, int w, int h, int midx);
void	handle_movement(int key, t_data *data);
int	quit(t_data *data);
int	check_allowed_move(int key, t_data *data);
int	handle_keypress(int key, t_data *data);
void	init_data(t_data *data, int x, int y);
int	read_map_init(t_data *data, char *s, int y, int x);
int	check_map_borders(t_data *data, int i, int j);
int	check_map_path(t_data *data, char **test, int i, int j);
int	check_map_char(char c);
char	check_map(t_data *data, int i, int j);
char	check_map_additional(t_data *data);
int	check_map_error(t_data *data);
int	check_map_filename(char *s);
void	so_long(char *s);
void	set_player_direction(int key, t_data *data);
void	copy_map(t_data *data);
int	check_path(t_data *data, int i, int j);
int	find_map_height(char *s);

#endif