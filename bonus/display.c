/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 14:03:03 by aguezzi           #+#    #+#             */
/*   Updated: 2023/07/13 18:05:40 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	map->img.img_peach = mlx_xpm_file_to_image(map->mlx, peach_image(map),
			map->img.img_width, map->img.img_height);
	mlx_put_image_to_window(map->mlx, map->win, map->img.img_peach, x, y);
	mlx_destroy_image(map->mlx, map->img.img_peach);
}

void	display_mario(t_map *map, int x, int y)
{
	display_herbe(map, map->img.x, map->img.y);
	map->img.img_mario = mlx_xpm_file_to_image(map->mlx, mario_image(map),
			map->img.img_width, map->img.img_height);
	mlx_put_image_to_window(map->mlx, map->win, map->img.img_mario, x, y);
	mlx_destroy_image(map->mlx, map->img.img_mario);
}

void	display_enemy(t_map *map, int x, int y)
{
	display_herbe(map, map->img.x, map->img.y);
	if (nb_collectibles(map))
		map->img.img_enemy = mlx_xpm_file_to_image(map->mlx,
				"images/goomba.xpm", map->img.img_width, map->img.img_height);
	else
		map->img.img_enemy = mlx_xpm_file_to_image(map->mlx,
				"images/goomba.xpm", map->img.img_width, map->img.img_height);
	mlx_put_image_to_window(map->mlx, map->win, map->img.img_enemy, x, y);
	mlx_destroy_image(map->mlx, map->img.img_enemy);
}
