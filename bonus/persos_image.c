/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   persos_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 14:08:45 by aguezzi           #+#    #+#             */
/*   Updated: 2023/07/12 13:01:27 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*peach_image(t_map *map)
{
	int	i;
	int	j;
	int	count;

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
		return ("images/peach_win.xpm");
	else
		return ("images/peach_start.xpm");
}

char	*mario_image(t_map *map)
{
	if (map->key == 0)
		return ("images/mario_left.xpm");
	else if (map->key == 1)
		return ("images/mario_front.xpm");
	else if (map->key == 2)
		return ("images/mario_right.xpm");
	else
		return ("images/mario_behind.xpm");
}
