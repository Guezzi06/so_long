/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:25:34 by aguezzi           #+#    #+#             */
/*   Updated: 2023/07/13 19:21:50 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_walls(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->my_map[i])
	{
		if (i == 0 || i == map->lines - 1)
		{
			j = 0;
			while ((map->my_map)[i][j] && map->my_map[i][j] != '\n')
			{
				if (map->my_map[i][j] != '1')
					ft_quit(map, "walls incorrect", 1);
				j++;
			}
		}
		else if (map->my_map[i][0] != '1'
			|| map->my_map[i][map->columns - 2] != '1')
			ft_quit(map, "walls incorrect", 1);
		i++;
	}
}

void	check_paths(t_map *map)
{
	int	i;
	int	j;

	while (map->path)
	{
		i = 0;
		map->path = 0;
		while (i < map->lines)
		{
			j = 0;
			while (map->copy[i][j] && map->copy[i][j] != '\n')
			{
				if (map->copy[i][j] == 'P')
					check_path_c(map, i, j);
				j++;
			}
			i++;
		}
	}
	check_pathfinding(map);
}

void	check_pathfinding(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->copy[i])
	{
		j = 0;
		while (map->copy[i][j] && map->copy[i][j] != '\n')
		{
			if (map->copy[i][j] == 'C')
				ft_quit(map, "C not reachable", 1);
			j++;
		}
		i++;
	}
	check_path_e(map, i, j);
}

void	check_path_e(t_map *map, int i, int j)
{
	i = 0;
	while (map->copy[i])
	{
		j = 0;
		while (map->copy[i][j] && map->copy[i][j] != '\n')
		{
			if (map->copy[i][j] == 'E')
			{
				if (!(map->copy[i - 1][j] == 'P' 
					|| map->copy[i + 1][j] == 'P'
					|| map->copy[i][j - 1] == 'P'
					|| map->copy[i][j + 1] == 'P'))
					ft_quit(map, "E not reachable", 1);
			}
			j++;
		}
		i++;
	}
}

void	check_path_c(t_map *map, int i, int j)
{
	if (map->copy[i - 1][j] != '1' && map->copy[i - 1][j] != 'P'
		&& map->copy[i - 1][j] != 'E')
	{
		map->copy[i - 1][j] = 'P';
		map->path++;
	}
	if (map->copy[i + 1][j] != '1' && map->copy[i + 1][j] != 'P'
		&& map->copy[i + 1][j] != 'E')
	{
		map->copy[i + 1][j] = 'P';
		map->path++;
	}
	if (map->copy[i][j - 1] != '1' && map->copy[i][j - 1] != 'P'
		&& map->copy[i][j - 1] != 'E')
	{
		map->copy[i][j - 1] = 'P';
		map->path++;
	}
	if (map->copy[i][j + 1] != '1' && map->copy[i][j + 1] != 'P'
		&& map->copy[i][j + 1] != 'E')
	{
		map->copy[i][j + 1] = 'P';
		map->path++;
	}
}
