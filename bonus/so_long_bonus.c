/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:57:07 by aguezzi           #+#    #+#             */
/*   Updated: 2023/07/13 19:08:16 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_map	map;

	init(&map);
	if (argc == 2)
		check_map(argv, &map);
	else
		ft_quit(&map, "Arguments number incorrect", 1);
	init_lenmap(&map);
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, map.width, map.height, "So_long");
	img_loop(&map);
	mlx_loop_hook(map.mlx, &run, &map);
	mlx_hook(map.win, 2, 0, &keypress, &map);
	mlx_hook(map.win, 17, 0, &ft_escape, &map);
	mlx_loop(map.mlx);
	return (0);
}

int	ft_quit(t_map *map, char *s, int err)
{
	int	i;

	i = 0;
	if (map->my_map)
	{
		while (map->my_map[i])
		{
			free(map->my_map[i]);
			free(map->copy[i]);
			i++;
		}
		free(map->my_map);
		free(map->copy);
	}
	if (err)
		ft_printf("Error\n");
	if (s && s[0])
		ft_printf("%s", s);
	exit (0);
	return (0);
}

int	ft_escape(void)
{
	exit (0);
	return (0);
}

void	ft_lose(t_map *map)
{
	mlx_clear_window(map->mlx, map->win);
	mlx_string_put(map->mlx, map->win, map->width / 2, map->height / 2,
		0xFF0000, "GAME OVER");
	mlx_do_sync(map->mlx);
	sleep(3);
	ft_quit(map, "LOSE", 0);
}

void	ft_win(t_map *map)
{
	mlx_clear_window(map->mlx, map->win);
	mlx_string_put(map->mlx, map->win, map->width / 2, map->height / 2,
		0xFFFFFF, "WIN !!!");
	mlx_do_sync(map->mlx);
	sleep(3);
	ft_quit(map, "WIN", 0);
}
