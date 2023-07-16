/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:53:40 by aguezzi           #+#    #+#             */
/*   Updated: 2023/07/16 10:38:06 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_map(char **argv, t_map *map)
{
	map->ptr = ft_strrchr(argv[1], '.');
	if (map->ptr == NULL)
		ft_quit(map, "malloc error", 1);
	if (ft_strcmp(map->ptr, ".ber") == 0)
	{
		if (!(open(argv[1], O_DIRECTORY) < 0))
			ft_quit(map, "need a file", 1);
		map->fd = open(argv[1], O_RDONLY);
		if (map->fd != -1)
		{
			check_columns_lines(map, argv);
			copy_map(map);
			check_6char(map);
			check_doublons(map);
			check_walls(map);
			check_paths(map);
		}
		else
			ft_quit(map, "fd fail", 1);
	}
	else
		ft_quit(map, "need .ber", 1);
}

void	copy_map(t_map *map)
{
	int	i;

	i = 0;
	map->my_map = malloc(sizeof(char *) * (map->lines + 1));
	map->copy = malloc(sizeof(char *) * (map->lines + 1));
	map->ptr = get_next_line(map->fd);
	if (!map->my_map || !map->copy)
		ft_quit(map, "malloc error", 1);
	map->columns = ft_len(map->ptr);
	while (map->ptr)
	{
		map->my_map[i] = ft_strdup(map->ptr);
		map->copy[i] = ft_strdup(map->ptr);
		free(map->ptr);
		map->ptr = get_next_line(map->fd);
		i++;
	}
	map->my_map[i] = NULL;
	map->copy[i] = NULL;
	close(map->fd);
}

void	check_columns_lines(t_map *map, char **argv)
{
	map->ptr = get_next_line(map->fd);
	if (!map->ptr)
		ft_quit(map, "empty file", 1);
	map->columns = ft_len(map->ptr);
	while (map->ptr)
	{
		map->lines ++;
		if (map->columns != ft_len(map->ptr))
		{
			if (map->ptr[ft_len(map->ptr) - 1] == '\n')
				ft_quit(map, "Not rectangular", 1);
		}
		if (map->ptr[ft_len(map->ptr) - 1] != '\n')
		{
			if (!(ft_len(map->ptr) == map->columns - 1))
				ft_quit(map, "Not rectangular", 1);
		}
		free(map->ptr);
		map->ptr = get_next_line(map->fd);
	}
	if (map->lines < 3)
		ft_quit(map, "Not enough lines", 1);
	close(map->fd);
	map->fd = open(argv[1], O_RDONLY);
}

void	check_6char(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->my_map[i])
	{
		j = 0;
		while ((map->my_map)[i][j] && (map->my_map)[i][j] != '\n')
		{
			if (map->my_map[i][j] != '0' && map->my_map[i][j] != '1'
				&& map->my_map[i][j] != 'P' && map->my_map[i][j] != 'E'
				&& map->my_map[i][j] != 'C' && map->my_map[i][j] != 'N')
				ft_quit(map, "character incorrect", 1);
			j++;
		}
		i++;
	}
}

void	check_doublons(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->my_map[i])
	{
		j = 0;
		while ((map->my_map)[i][j] && (map->my_map)[i][j] != '\n')
		{
			if (map->my_map[i][j] == 'P')
				map->nb_p ++;
			if (map->my_map[i][j] == 'E')
				map->nb_e ++;
			if (map->my_map[i][j] == 'C')
				map->nb_c ++;
			j++;
		}
		i++;
	}
	if (!(map->nb_p == 1 && map->nb_e == 1 && map->nb_c >= 1))
		ft_quit(map, "number C, or P, or E incorrect", 1);
}
