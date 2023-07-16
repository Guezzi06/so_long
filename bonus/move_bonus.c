/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:15:03 by aguezzi           #+#    #+#             */
/*   Updated: 2023/07/12 13:08:47 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_left(t_map *m)
{
	m->i = 0;
	m->key = 0;
	while (m->my_map[m->i])
	{
		m->j = 0;
		while (m->my_map[m->i][m->j] && m->my_map[m->i][m->j] != '\n')
		{
			if (m->my_map[m->i][m->j] == 'P')
			{
				if (m->my_map[m->i][m->j - 1] != '1')
				{
					move_conditions(m, m->i, m->j - 1);
					if (m->my_map[m->i][m->j - 1] != 'E')
					{
						m->my_map[m->i][m->j] = '0';
						m->my_map[m->i][m->j - 1] = 'P';
					}
				}
				return ;
			}
			m->j++;
		}
		m->i++;
	}
}

void	move_up(t_map *m)
{
	m->i = 0;
	m->key = 13;
	while (m->my_map[m->i])
	{
		m->j = 0;
		while (m->my_map[m->i][m->j] && m->my_map[m->i][m->j] != '\n')
		{
			if (m->my_map[m->i][m->j] == 'P')
			{
				if (m->my_map[m->i - 1][m->j] != '1')
				{
					move_conditions(m, m->i - 1, m->j);
					if (m->my_map[m->i - 1][m->j] != 'E')
					{
						m->my_map[m->i][m->j] = '0';
						m->my_map[m->i - 1][m->j] = 'P';
					}
				}
				return ;
			}
			m->j++;
		}
		m->i++;
	}
}

void	move_right(t_map *m)
{
	m->i = 0;
	m->key = 2;
	while (m->my_map[m->i])
	{
		m->j = 0;
		while (m->my_map[m->i][m->j] && m->my_map[m->i][m->j] != '\n')
		{
			if (m->my_map[m->i][m->j] == 'P')
			{
				if (m->my_map[m->i][m->j + 1] != '1')
				{
					move_conditions(m, m->i, m->j + 1);
					if (m->my_map[m->i][m->j + 1] != 'E')
					{
						m->my_map[m->i][m->j] = '0';
						m->my_map[m->i][m->j + 1] = 'P';
					}
				}
				return ;
			}
			m->j++;
		}
		m->i++;
	}
}

void	move_down(t_map *m)
{
	m->i = 0;
	m->key = 1;
	while (m->my_map[m->i])
	{
		m->j = 0;
		while (m->my_map[m->i][m->j] && m->my_map[m->i][m->j] != '\n')
		{
			if (m->my_map[m->i][m->j] == 'P')
			{
				if (m->my_map[m->i + 1][m->j] != '1')
				{
					move_conditions(m, m->i + 1, m->j);
					if (m->my_map[m->i + 1][m->j] != 'E')
					{
						m->my_map[m->i][m->j] = '0';
						m->my_map[m->i + 1][m->j] = 'P';
					}
				}
				return ;
			}
			m->j++;
		}
		m->i++;
	}
}

void	move_conditions(t_map *map, int a, int b)
{
	if (map->my_map[a][b] == 'N')
		ft_lose(map);
	map->nb_coups ++;
	if (map->my_map[a][b] == 'E')
		check_collectibles(map);
}
