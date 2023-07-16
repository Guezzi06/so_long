/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 11:36:04 by aguezzi           #+#    #+#             */
/*   Updated: 2023/07/13 18:44:06 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_pierres(t_map *map, int x, int y)
{
	map->img.img_pierres = mlx_xpm_file_to_image(map->mlx,
			"images/my_pierres.xpm", map->img.img_width, map->img.img_height);
	mlx_put_image_to_window(map->mlx, map->win, map->img.img_pierres, x, y);
	mlx_destroy_image(map->mlx, map->img.img_pierres);
}

void	display_herbe(t_map *map, int x, int y)
{
	map->img.img_herbe = mlx_xpm_file_to_image(map->mlx,
			"images/my_herbe.xpm", map->img.img_width, map->img.img_height);
	mlx_put_image_to_window(map->mlx, map->win, map->img.img_herbe, x, y);
	mlx_destroy_image(map->mlx, map->img.img_herbe);
}

void	display_peach(t_map *map, int x, int y)
{
	display_herbe(map, map->img.x, map->img.y);
	map->img.img_peach = mlx_xpm_file_to_image(map->mlx,
			"images/peach.xpm", map->img.img_width, map->img.img_height);
	mlx_put_image_to_window(map->mlx, map->win, map->img.img_peach, x, y);
	mlx_destroy_image(map->mlx, map->img.img_peach);
}

void	display_coin(t_map *map, int x, int y)
{
	display_herbe(map, map->img.x, map->img.y);
	map->img.img_coin = mlx_xpm_file_to_image(map->mlx,
			"images/coin1.xpm", map->img.img_width, map->img.img_height);
	mlx_put_image_to_window(map->mlx, map->win, map->img.img_coin, x, y);
	mlx_destroy_image(map->mlx, map->img.img_coin);
}

void	display_mario(t_map *map, int x, int y)
{
	display_herbe(map, map->img.x, map->img.y);
	map->img.img_mario = mlx_xpm_file_to_image(map->mlx,
			"images/marioplayer.xpm", map->img.img_width, map->img.img_height);
	mlx_put_image_to_window(map->mlx, map->win, map->img.img_mario, x, y);
	mlx_destroy_image(map->mlx, map->img.img_mario);
}
