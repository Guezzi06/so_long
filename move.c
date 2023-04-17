/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 11:13:59 by aguezzi           #+#    #+#             */
/*   Updated: 2023/04/16 11:51:12 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    move_left(t_map *map)
{
    int i;
    int j;

    i = 0;
    while (map->my_map[i])
    {
        j = 0;
        while (map->my_map[i][j] && map->my_map[i][j] != '\n')
        {
            if (map->my_map[i][j] == 'P')
            {
                if (map->my_map[i][j - 1] != '1')
                {
                    if (map->my_map[i][j - 1] == 'E')
                        check_collectibles(map);
                    else
                    {
                        map->my_map[i][j] = '0';
                        map->my_map[i][j - 1] = 'P';
                    }
                }
                return ;
            }
            j++;
        }
        i++;
    }
}

void    move_up(t_map *map)
{
    int i;
    int j;

    i = 0;
    while (map->my_map[i])
    {
        j = 0;
        while (map->my_map[i][j] && map->my_map[i][j] != '\n')
        {
            if (map->my_map[i][j] == 'P')
            {
                if (map->my_map[i - 1][j] != '1')
                {
                    if (map->my_map[i - 1][j] == 'E')
                        check_collectibles(map);
                    else
                    {
                        map->my_map[i][j] = '0';
                        map->my_map[i - 1][j] = 'P';
                    }
                }
                return ;
            }
            j++;
        }
        i++;
    }
}

void    move_right(t_map *map)
{
    int i;
    int j;

    i = 0;
    while (map->my_map[i])
    {
        j = 0;
        while (map->my_map[i][j] && map->my_map[i][j] != '\n')
        {
            if (map->my_map[i][j] == 'P')
            {
                if (map->my_map[i][j + 1] != '1')
                {
                    if (map->my_map[i][j + 1] == 'E')
                        check_collectibles(map);
                    else
                    {
                        map->my_map[i][j] = '0';
                        map->my_map[i][j + 1] = 'P';
                    }
                }
                return ;
            }
            j++;
        }
        i++;
    }
}

void    move_down(t_map *map)
{
    int i;
    int j;

    i = 0;
    while (map->my_map[i])
    {
        j = 0;
        while (map->my_map[i][j] && map->my_map[i][j] != '\n')
        {
            if (map->my_map[i][j] == 'P')
            {
                if (map->my_map[i + 1][j] != '1')
                {
                    if (map->my_map[i + 1][j] == 'E')
                        check_collectibles(map);
                    else
                    {
                        map->my_map[i][j] = '0';
                        map->my_map[i + 1][j] = 'P';
                    }
                }
                return ;
            }
            j++;
        }
        i++;
    }
}

void    check_collectibles(t_map *map)
{
    int i;
    int j;
    int count;

    i = 0;
    count = 0;
    while (map->my_map[i])
    {
        j = 0;
        while (map->my_map[i][j] && map->my_map[i][j] != '\n')
        {
            if (map->my_map[i][j] == 'C')
                count++;
            j++;
        }
        i++;
    }
    if (count == 0)
        free_and_exit(map, "WIN");
}