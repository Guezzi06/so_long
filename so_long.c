/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:02:25 by aguezzi           #+#    #+#             */
/*   Updated: 2023/07/13 19:21:17 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	mlx_hook(map.win, 2, 0, &keypress, &map);
	mlx_hook(map.win, 17, 0, &ft_escape, &map);
	mlx_loop(map.mlx);
	return (0);
}

int	ft_quit(t_map *map, char *s, int err)
{
	if (err)
		ft_printf("Error\n");
	else
		ft_printf("%d\n", map->nb_coups + 1);
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
