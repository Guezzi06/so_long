/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 14:01:38 by aguezzi           #+#    #+#             */
/*   Updated: 2023/07/12 13:09:53 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	position_player_enemy(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->my_map[i])
	{
		j = 0;
		while (map->my_map[i][j])
		{
			if (map->my_map[i][j] == 'P')
			{
				map->player_x = j;
				map->player_y = i;
			}
			if (map->my_map[i][j] == 'N')
			{
				map->enemy_x = j;
				map->enemy_y = i;
			}
			j++;
		}
		i++;
	}
}

void	display_herbe_enemy(t_map *map, int yN, int xN)
{
	display_herbe(map, map->enemy_x * 60, map->enemy_y * 60);
	display_enemy(map, xN * 60, yN * 60);
}

int	ft_abs(int v)
{
	if (v < 0)
		return (-v);
	else
		return (v);
}
