/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_Canim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:08:07 by aguezzi           #+#    #+#             */
/*   Updated: 2023/07/13 18:03:41 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	display_c_anim(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->my_map[i])
	{
		j = 0;
		while (map->my_map[i][j] && map->my_map[i][j] != '\n')
		{
			if (map->my_map[i][j] == 'C')
			{
				if (map->frame < 14)
					display_coin1(map, j * 60, i * 60);
				else if (map->frame < 28)
					display_coin2(map, j * 60, i * 60);
				else
					display_coin3(map, j * 60, i * 60);
			}
			j++;
		}
		i++;
	}
}

void	display_coin1(t_map *map, int x, int y)
{
	display_herbe(map, x, y);
	map->img.img_coin = mlx_xpm_file_to_image(map->mlx, "images/coin1.xpm",
			map->img.img_width, map->img.img_height);
	mlx_put_image_to_window(map->mlx, map->win, map->img.img_coin, x, y);
	mlx_destroy_image(map->mlx, map->img.img_coin);
}

void	display_coin2(t_map *map, int x, int y)
{
	display_herbe(map, x, y);
	map->img.img_coin = mlx_xpm_file_to_image(map->mlx, "images/coin2.xpm",
			map->img.img_width, map->img.img_height);
	mlx_put_image_to_window(map->mlx, map->win, map->img.img_coin, x, y);
	mlx_destroy_image(map->mlx, map->img.img_coin);
}

void	display_coin3(t_map *map, int x, int y)
{
	display_herbe(map, x, y);
	map->img.img_coin = mlx_xpm_file_to_image(map->mlx, "images/coin3.xpm",
			map->img.img_width, map->img.img_height);
	mlx_put_image_to_window(map->mlx, map->win, map->img.img_coin, x, y);
	mlx_destroy_image(map->mlx, map->img.img_coin);
}
