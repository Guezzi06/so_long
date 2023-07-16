/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:02:42 by aguezzi           #+#    #+#             */
/*   Updated: 2023/07/13 19:22:30 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "libft/ft_printf.h"
# include "mlx.h"

typedef struct s_img
{
	void	*img_herbe;
	void	*img_pierres;
	void	*img_mario;
	void	*img_coin;
	void	*img_peach;
	int		*img_width;
	int		*img_height;
	int		x;
	int		y;
}	t_img;

typedef struct s_map
{
	char	**my_map;
	void	*mlx;
	void	*win;
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
	int		frame;
	int		i;
	int		j;
	t_img	img;
}	t_map;

int		keypress(int key, t_map *map);
void	init(t_map *map);
void	check_map(char **argv, t_map *map);
void	copy_map(t_map *map);
void	init_lenmap(t_map *map);
void	check_columns_lines(t_map *map, char **argv);
void	check_5char(t_map *map);
void	check_doublons(t_map *map);
void	check_walls(t_map *map);
void	check_paths(t_map *map);
void	check_path_c(t_map *map, int i, int j);;
void	check_path_e(t_map *map, int i, int j);
void	check_pathfinding(t_map *map);
void	move_left(t_map *map);
void	move_up(t_map *map);
void	move_right(t_map *map);
void	move_down(t_map *map);
void	check_collectibles(t_map *map);
int		img_loop(t_map *map);
void	display_mario(t_map *map, int x, int y);
void	display_pierres(t_map *map, int x, int y);
void	display_herbe(t_map *map, int x, int y);
void	display_coin(t_map *map, int x, int y);
void	display_peach(t_map *map, int x, int y);
void	which_image(t_map *map, int i, int j);
int		ft_quit(t_map *map, char *s, int err);
int		ft_escape(void);

#endif
