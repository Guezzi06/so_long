/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:02:25 by aguezzi           #+#    #+#             */
/*   Updated: 2023/04/17 15:05:39 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc == 2)
	{
		init(&map);
		check_map(argv, &map);
	}
	else
		exit(0);
	init_lenmap(&map);
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, map.width, map.height, "My Game Window");
	img_loop(&map);
	mlx_hook(map.win, 2, 0, &keypress, &map);
	mlx_hook(map.win, 17, 0, &quit, &map);
	mlx_loop(map.mlx);
	return (0);
}

int	img_loop(t_map *map)
{
	int	i;
	int	j;
	
	i = 0;
	map->x = 0;
	map->y = 0;
	while (map->my_map[i])
	{
		j = 0;
		while (map->my_map[i][j] && map->my_map[i][j] != '\n')
		{
			which_image(map, i, j);
			map->x += 60;
			j++;
		}
		map->y += 60;
		map->x = 0;
		i++;
	}
	return (0);
}

void	which_image(t_map *map, int i, int j)
{
	if (map->my_map[i][j] == '1')
		display_pierres(map, map->x, map->y);
	else if (map->my_map[i][j] == '0')
		display_herbe(map, map->x, map->y);
	else if (map->my_map[i][j] == 'P')
		display_mario(map, map->x, map->y);
}

void	display_mario(t_map *map, int x, int y)
{
	display_herbe(map, map->x, map->y);
	mlx_put_image_to_window(map->mlx, map->win, map->img_mario, x, y);
}

void	display_pierres(t_map *map, int x, int y)
{
	mlx_put_image_to_window(map->mlx, map->win, map->img_pierres, x, y);
}

void	display_herbe(t_map *map, int x, int y)
{
	mlx_put_image_to_window(map->mlx, map->win, map->img_herbe, x, y);
}

int	quit()
{
	exit(0);
}

int	keypress(int key, t_map *map)
{
	if (key == 53)
		quit();
	else if (key == 0)
		move_left(map);
	else if (key == 1)
		move_down(map);
	else if (key == 2)
		move_right(map);
	else if (key == 13)
		move_up(map);
	img_loop(map);
	return (0);
}

void	affich_map(t_map *map)
{
	int i;

    i = 0;
	ft_printf("\n\n\n\n\n");
    while (map->my_map[i])
    {
        ft_printf(map->my_map[i]);
        i++;
    }
}



/*int	run(t_map *map)
{
	map->frame++;
	if (map->frame > 100)
		map->frame = 0;
	keyall(map);
	return (0);
}

int	keyall(t_map *map)
{
	if (map->key[0] == 1)
		move_left(map);
	if (map->key[1] == 1)
		move_down(map);
	if (map->key[2] == 1)
		move_right(map);
	if (map->key[3] == 1)
		move_up(map);
	return (0);
}

// 0 = A, 1 = S, 2 = D, 13 = W
int	keypress(int key, t_map *map)
{
	if (key == 53)
		quit();
	else if (key == 0)
		map->key[0] = 1;
	else if (key == 1)
		map->key[1] = 1;
	else if (key == 2)
		map->key[2] = 1;
	else if (key == 13)
		map->key[3] = 1;
	return (0);
}

int	keyout(int key, t_map *map)
{
	if (key == 0)
		map->key[0] = 0;
	else if (key == 1)
		map->key[1] = 0;
	else if (key == 2)
		map->key[2] = 0;
	else if (key == 13)
		map->key[3] = 0;
	return (0);
}*/