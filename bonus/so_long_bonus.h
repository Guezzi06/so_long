/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:57:00 by aguezzi           #+#    #+#             */
/*   Updated: 2023/07/13 19:09:57 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include "mlx.h"

typedef struct s_img
{
	void	*img_herbe;
	void	*img_pierres;
	void	*img_mario;
	void	*img_coin;
	void	*img_peach;
	void	*img_enemy;
	int		*img_width;
	int		*img_height;
	int		x;
	int		y;
}	t_img;

typedef struct s_map
{
	int		key;
	int		frame;
	int		frame_enemy;
	char	**my_map;
	void	*mlx;
	void	*win;
	int		i;
	int		j;
	int		player_x;
	int		player_y;
	int		enemy_x;
	int		enemy_y;
	int		nb_coups;
	int		columns;
	int		lines;
	int		width;
	int		height;
	char	*ptr;
	char	**copy;
	int		fd;
	int		nb_p;
	int		nb_e;
	int		nb_c;
	int		path;
	t_img	img;
}	t_map;

// run
void	init(t_map *map);
int		keypress(int key, t_map *map);
int		run(t_map *map);
int		img_loop(t_map *map);

// map
void	check_map(char **argv, t_map *map);
void	copy_map(t_map *map);
void	init_lenmap(t_map *map);
void	check_columns_lines(t_map *map, char **argv);
void	check_6char(t_map *map);
void	check_doublons(t_map *map);
void	check_walls(t_map *map);
void	check_paths(t_map *map);
void	check_path_c(t_map *map, int i, int j);;
void	check_path_e(t_map *map, int i, int j);
void	check_pathfinding(t_map *map);

//moves
void	move_left(t_map *map);
void	move_up(t_map *map);
void	move_right(t_map *map);
void	move_down(t_map *map);
void	move_conditions(t_map *map, int a, int b);
void	check_collectibles(t_map *map);
int		nb_collectibles(t_map *map);

// enemy
void	move_enemy(t_map *map);
void	move_enemy_1(t_map *map);
void	move_enemy_2(t_map *map);
void	move_enemy_3(t_map *map);
void	move_enemy_4(t_map *map);
void	position_player_enemy(t_map *map);
void	display_herbe_enemy(t_map *map, int yN, int xN);
int		ft_abs(int v);

// displays
void	display_pierres(t_map *map, int x, int y);
void	display_herbe(t_map *map, int x, int y);
void	display_mario(t_map *map, int x, int y);
char	*mario_image(t_map *map);
void	display_peach(t_map *map, int x, int y);
char	*peach_image(t_map *map);
void	display_enemy(t_map *map, int x, int y);
void	display_c_anim(t_map *map);
void	display_coin1(t_map *map, int x, int y);
void	display_coin2(t_map *map, int x, int y);
void	display_coin3(t_map *map, int x, int y);
void	which_image(t_map *map, int i, int j);

// endgame
int		ft_quit(t_map *map, char *s, int err);
int		ft_escape(void);
void	ft_win(t_map *map);
void	ft_lose(t_map *map);

#endif