/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 14:06:13 by aguezzi           #+#    #+#             */
/*   Updated: 2023/07/16 11:05:24 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init(t_map *map)
{
	map->key = 2;
	map->frame = 0;
	map->frame_enemy = 0;
	map->my_map = NULL;
	map->copy = NULL;
	map->nb_coups = 0;
	map->columns = 0;
	map->lines = 0;
	map->nb_p = 0;
	map->nb_e = 0;
	map->nb_c = 0;
	map->path = 1;
	map->enemy_x = 0;
	map->enemy_y = 0;
	map->img.img_width = malloc(sizeof(int));
	if (!map->img.img_width)
		ft_quit(map, "malloc error img_width", 1);
	map->img.img_height = malloc(sizeof(int));
	if (!map->img.img_height)
		ft_quit(map, "malloc error img_height", 1);
}

void	init_lenmap(t_map *map)
{
	int	*a;
	int	*b;

	map->width = (map->columns - 1) * 60;
	map->height = (map->lines) * 60;
	a = map->img.img_width;
	b = map->img.img_height;
	*a = 60;
	*b = 60;
}

int	keypress(int key, t_map *map)
{
	if (key == 53)
		ft_escape();
	else if (key == 0)
		move_left(map);
	else if (key == 1)
		move_down(map);
	else if (key == 2)
		move_right(map);
	else if (key == 13)
		move_up(map);
	img_loop(map);
	map->frame += 3;
	map->frame_enemy += 4;
	run(map);
	return (0);
}

int	nb_collectibles(t_map *map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map->my_map[i])
	{
		j = 0;
		while (map->my_map[i][j] && map->my_map[i][j] != '\n')
		{
			if (map->my_map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	check_collectibles(t_map *map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map->my_map[i])
	{
		j = 0;
		while (map->my_map[i][j] && map->my_map[i][j] != '\n')
		{
			if (map->my_map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	if (count == 0)
		ft_win(map);
}
