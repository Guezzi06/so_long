/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 11:38:10 by aguezzi           #+#    #+#             */
/*   Updated: 2023/07/16 10:42:28 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init(t_map *map)
{
	map->frame = 0;
	map->ptr = NULL;
	map->my_map = NULL;
	map->copy = NULL;
	map->nb_coups = 0;
	map->columns = 0;
	map->lines = 0;
	map->nb_p = 0;
	map->nb_e = 0;
	map->nb_c = 0;
	map->path = 1;
	map->img.img_width = malloc(sizeof(int));
	map->img.img_height = malloc(sizeof(int));
	if (!map->img.img_width || !map->img.img_height)
		ft_quit(map, "malloc error", 1);
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

int	img_loop(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->img.x = 0;
	map->img.y = 0;
	while (map->my_map[i])
	{
		j = 0;
		while (map->my_map[i][j] && map->my_map[i][j] != '\n')
		{
			which_image(map, i, j);
			map->img.x += 60;
			j++;
		}
		map->img.y += 60;
		map->img.x = 0;
		i++;
	}
	return (0);
}

void	which_image(t_map *map, int i, int j)
{
	if (map->my_map[i][j] == '1')
		display_pierres(map, map->img.x, map->img.y);
	else if (map->my_map[i][j] == '0')
		display_herbe(map, map->img.x, map->img.y);
	else if (map->my_map[i][j] == 'P')
		display_mario(map, map->img.x, map->img.y);
	else if (map->my_map[i][j] == 'C')
		display_coin(map, map->img.x, map->img.y);
	else if (map->my_map[i][j] == 'E')
		display_peach(map, map->img.x, map->img.y);
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
	ft_printf("%d\n", map->nb_coups);
	return (0);
}
