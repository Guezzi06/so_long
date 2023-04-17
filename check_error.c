/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:47:31 by aguezzi           #+#    #+#             */
/*   Updated: 2023/04/16 11:40:52 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    check_map(char **argv, t_map *map)
{
    map->ptr = ft_strrchr(argv[1], '.');
    if (map->ptr == NULL)
        free_and_exit(map, "");
    if (ft_strcmp(map->ptr, ".ber") == 0)
    {
        map->fd = open(argv[1], O_RDONLY);
        if (map->fd != -1)
        {
            check_columns_lines(map, argv);
            copy_map(map);
            check_5char(map);
            check_doublons(map);
            check_walls(map);
            check_paths(map);
        }
        else
            free_and_exit(map, "fd fail");
    }
}

void    check_paths(t_map *map)
{
    int i;
    int j;

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
                    check_4directions(map, i, j);
                j++;
            }
            i++;
        }
    }
    check_pathfinding(map);
}

void    check_pathfinding(t_map *map)
{
    int i;
    int j;

    i = 0;
    while (map->copy[i])
    {
        j = 0;
        while (map->copy[i][j] && map->copy[i][j] != '\n')
        {
            if (map->copy[i][j] == 'E' || map->copy[i][j] == 'C')
                free_and_exit(map, "C or E not reachable");
            j++;
        }
        i++;
    }
}

void    check_4directions(t_map *map, int i, int j)
{
    if (map->copy[i - 1][j] != '1' && map->copy[i - 1][j] != 'P')
    {
        map->copy[i - 1][j] = 'P';
        map->path++;
    }
    if (map->copy[i + 1][j] != '1' && map->copy[i + 1][j] != 'P')
    {
        map->copy[i + 1][j] = 'P';
        map->path++;
    }
    if (map->copy[i][j - 1] != '1' && map->copy[i][j - 1] != 'P')
    {
        map->copy[i][j - 1] = 'P';
        map->path++;
    }
    if (map->copy[i][j + 1] != '1' && map->copy[i][j + 1] != 'P')
    {
        map->copy[i][j + 1] = 'P';
        map->path++;
    }
}

void    check_walls(t_map *map)
{
    int i;
    int j;

    i = 0;
    while (map->my_map[i])
    {
        if (i == 0 || i == map->lines - 1)
        {
            j = 0;
            while ((map->my_map)[i][j] && map->my_map[i][j] != '\n')
            {
                if (map->my_map[i][j] != '1')
                    free_and_exit(map, "walls incorrect");
                j++;
            }
        }
        else if (map->my_map[i][0] != '1' || map->my_map[i][map->columns - 2] != '1')
            free_and_exit(map, "walls incorrect");
        i++;
    }
}

void    check_doublons(t_map *map)
{
    int i;
    int j;

    i = 0;
    while (map->my_map[i])
    {
        j = 0;
        while ((map->my_map)[i][j] && (map->my_map)[i][j] != '\n')
        {
            if (map->my_map[i][j] == 'P')
                map->nb_P ++;
            if (map->my_map[i][j] == 'E')
                map->nb_E ++;
            if (map->my_map[i][j] == 'C')
                map->nb_C ++;
            j++;
        }
        i++;
    }
    if (!(map->nb_P == 1 && map->nb_E == 1 && map->nb_C >= 1))
        free_and_exit(map, "number C, or P, or E incorrect");
}

void    check_5char(t_map *map)
{
    int     i;
    int     j;

    i = 0;
    while (map->my_map[i])
    {
        j = 0;
        while ((map->my_map)[i][j] && (map->my_map)[i][j] != '\n')
        {
            if (map->my_map[i][j] != '0' && map->my_map[i][j] != '1' &&
                map->my_map[i][j] != 'P' && map->my_map[i][j] != 'E' &&
                map->my_map[i][j] != 'C')
                free_and_exit(map, "character incorrect");
            j++;
        }
        i++;
    }
}

void    copy_map(t_map *map)
{
    int i;

    i = 0;
    map->my_map = malloc(sizeof(char *) * (map->lines + 1));
    map->copy = malloc(sizeof(char *) * (map->lines + 1));
    map->ptr = get_next_line(map->fd);
    map->columns = ft_len(map->ptr);
    while (map->ptr)
    {
        map->my_map[i] = ft_strdup(map->ptr);
        map->copy[i] = ft_strdup(map->ptr);
        map->ptr = get_next_line(map->fd);
        i++;
    }
    map->my_map[i] = NULL;
    map->copy[i] = NULL;
    close(map->fd);
}

void    check_columns_lines(t_map *map, char **argv)
{
    map->ptr = get_next_line(map->fd);
    map->columns = ft_len(map->ptr);
    while (map->ptr)
    {
        map->lines ++;
        if (map->columns != ft_len(map->ptr))
        {
            if (map->ptr[ft_len(map->ptr) - 1] == '\n')
                free_and_exit(map, "Not rectangular");
            if (map->ptr[ft_len(map->ptr) - 1] == '\0')
            {
                if (!(ft_len(map->ptr) == map->columns - 1))
                    free_and_exit(map, "Not rectangular");
            }
        }
        map->ptr = get_next_line(map->fd);
    }
    if (map->lines < 3)
        free_and_exit(map, "Not enough lines");
    close(map->fd);
    map->fd = open(argv[1], O_RDONLY);
}

void    free_and_exit(t_map *map, char *s)
{
    int i;

    i = 0;
    if (map->my_map)
    {
        while (map->my_map[i])
        {
            free(map->my_map[i]);
            i++;
        }
        free(map->my_map);
    }
    ft_printf("Error\n");
    if (s && s[0])
        ft_printf("%s", s);
    exit (0);
}