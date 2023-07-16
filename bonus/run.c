/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 14:04:48 by aguezzi           #+#    #+#             */
/*   Updated: 2023/07/16 10:40:54 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	run(t_map *map)
{
	display_c_anim(map);
	map->frame ++;
	map->frame_enemy ++;
	if (map->frame_enemy >= 25 && nb_collectibles(map))
		move_enemy(map);
	else if (map->frame_enemy >= 1400)
		move_enemy(map);
	if (map->frame >= 42)
		map->frame = 0;
	return (0);
}

int	img_loop(t_map *map)
{
	int		i;
	int		j;
	char	*str_coups;

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
	str_coups = ft_itoa(map->nb_coups);
	mlx_string_put(map->mlx, map->win, 10, 10, 0xFFFFFF, str_coups);
	free(str_coups);
	return (0);
}

void	which_image(t_map *map, int i, int j)
{
	if ((map->my_map[i][j] == '1' && map->nb_coups == 0) || (i == 0 && j == 0))
		display_pierres(map, map->img.x, map->img.y);
	else if (map->my_map[i][j] == '0' || map->my_map[i][j] == 'C')
		display_herbe(map, map->img.x, map->img.y);
	else if (map->my_map[i][j] == 'P')
		display_mario(map, map->img.x, map->img.y);
	else if (map->my_map[i][j] == 'E')
		display_peach(map, map->img.x, map->img.y);
	else if (map->my_map[i][j] == 'N')
		display_enemy(map, map->img.x, map->img.y);
}
