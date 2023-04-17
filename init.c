/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:39:02 by aguezzi           #+#    #+#             */
/*   Updated: 2023/04/17 13:02:32 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    init(t_map *map)
{
    map->key[0] = 0;
    map->key[1] = 0;
    map->key[2] = 0;
    map->key[3] = 0;
    map->frame = 0;
    map->my_map = NULL;
    map->copy = NULL;
    map->columns = 0;
    map->lines = 0;
    map->nb_P = 0;
    map->nb_E = 0;
    map->nb_C = 0;
    map->path = 1;
    map->img_width = malloc(sizeof(int));
    map->img_height = malloc(sizeof(int));
    map->img_herbe = mlx_xpm_file_to_image(map->mlx, "images/my_herbe.xpm", map->img_width, map->img_height);
    map->img_pierres = mlx_xpm_file_to_image(map->mlx, "images/my_pierres.xpm", map->img_width, map->img_height);
    map->img_mario = mlx_xpm_file_to_image(map->mlx, "images/marioplayer.xpm", map->img_width, map->img_height);
}

void    init_lenmap(t_map *map)
{
    int *a;
    int *b;

    map->width = (map->columns - 1) * 60;
    map->height = (map->lines) * 60;
    a = map->img_width;
    b = map->img_height;
    *a = 60;
    *b = 60;
}