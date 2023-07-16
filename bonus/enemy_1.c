/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:59:14 by aguezzi           #+#    #+#             */
/*   Updated: 2023/07/15 11:20:09 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_enemy(t_map *map)
{
	position_player_enemy(map);
	map->frame_enemy = 0;
	if (ft_abs(map->player_x - map->enemy_x)
		+ ft_abs(map->player_y - map->enemy_y) <= 1)
		ft_lose(map);
	if (ft_abs(map->player_x - map->enemy_x)
		> ft_abs(map->player_y - map->enemy_y))
	{
		if (map->player_x > map->enemy_x)
			move_enemy_1(map);
		else
			move_enemy_2(map);
	}
	else
	{
		if (map->player_y < map->enemy_y)
			move_enemy_3(map);
		else
			move_enemy_4(map);
	}
}

void	move_enemy_1(t_map *map)
{
	if (map->my_map[map->enemy_y][map->enemy_x + 1] == '0')
	{
		map->my_map[map->enemy_y][map->enemy_x + 1] = 'N';
		map->my_map[map->enemy_y][map->enemy_x] = '0';
		display_herbe_enemy(map, map->enemy_y, map->enemy_x + 1);
	}
	else if (map->player_y < map->enemy_y)
	{
		if (map->my_map[map->enemy_y - 1][map->enemy_x] == '0')
		{
			map->my_map[map->enemy_y - 1][map->enemy_x] = 'N';
			map->my_map[map->enemy_y][map->enemy_x] = '0';
			display_herbe_enemy(map, map->enemy_y - 1, map->enemy_x);
		}
	}
	else
	{
		if (map->my_map[map->enemy_y + 1][map->enemy_x] == '0')
		{
			map->my_map[map->enemy_y + 1][map->enemy_x] = 'N';
			map->my_map[map->enemy_y][map->enemy_x] = '0';
			display_herbe_enemy(map, map->enemy_y + 1, map->enemy_x);
		}
	}
}

void	move_enemy_2(t_map *map)
{
	if (map->my_map[map->enemy_y][map->enemy_x - 1] == '0')
	{
		map->my_map[map->enemy_y][map->enemy_x - 1] = 'N';
		map->my_map[map->enemy_y][map->enemy_x] = '0';
		display_herbe_enemy(map, map->enemy_y, map->enemy_x - 1);
	}
	else if (map->player_y < map->enemy_y)
	{
		if (map->my_map[map->enemy_y - 1][map->enemy_x] == '0')
		{
			map->my_map[map->enemy_y - 1][map->enemy_x] = 'N';
			map->my_map[map->enemy_y][map->enemy_x] = '0';
			display_herbe_enemy(map, map->enemy_y - 1, map->enemy_x);
		}
	}
	else
	{
		if (map->my_map[map->enemy_y + 1][map->enemy_x] == '0')
		{
			map->my_map[map->enemy_y + 1][map->enemy_x] = 'N';
			map->my_map[map->enemy_y][map->enemy_x] = '0';
			display_herbe_enemy(map, map->enemy_y + 1, map->enemy_x);
		}
	}
}

void	move_enemy_3(t_map *map)
{
	if (map->my_map[map->enemy_y - 1][map->enemy_x] == '0')
	{
		map->my_map[map->enemy_y - 1][map->enemy_x] = 'N';
		map->my_map[map->enemy_y][map->enemy_x] = '0';
		display_herbe_enemy(map, map->enemy_y - 1, map->enemy_x);
	}
	else if (map->player_x > map->enemy_x)
	{
		if (map->my_map[map->enemy_y][map->enemy_x + 1] == '0')
		{
			map->my_map[map->enemy_y][map->enemy_x + 1] = 'N';
			map->my_map[map->enemy_y][map->enemy_x] = '0';
			display_herbe_enemy(map, map->enemy_y, map->enemy_x + 1);
		}
	}
	else
	{
		if (map->my_map[map->enemy_y][map->enemy_x - 1] == '0')
		{
			map->my_map[map->enemy_y][map->enemy_x - 1] = 'N';
			map->my_map[map->enemy_y][map->enemy_x] = '0';
			display_herbe_enemy(map, map->enemy_y, map->enemy_x - 1);
		}
	}
}

void	move_enemy_4(t_map *map)
{
	if (map->my_map[map->enemy_y + 1][map->enemy_x] == '0')
	{
		map->my_map[map->enemy_y + 1][map->enemy_x] = 'N';
		map->my_map[map->enemy_y][map->enemy_x] = '0';
		display_herbe_enemy(map, map->enemy_y + 1, map->enemy_x);
	}
	else if (map->player_x > map->enemy_x)
	{
		if (map->my_map[map->enemy_y][map->enemy_x + 1] == '0')
		{
			map->my_map[map->enemy_y][map->enemy_x + 1] = 'N';
			map->my_map[map->enemy_y][map->enemy_x] = '0';
			display_herbe_enemy(map, map->enemy_y, map->enemy_x + 1);
		}
	}
	else
	{
		if (map->my_map[map->enemy_y][map->enemy_x - 1] == '0')
		{
			map->my_map[map->enemy_y][map->enemy_x - 1] = 'N';
			map->my_map[map->enemy_y][map->enemy_x] = '0';
			display_herbe_enemy(map, map->enemy_y, map->enemy_x - 1);
		}
	}
}
