/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 11:13:59 by aguezzi           #+#    #+#             */
/*   Updated: 2023/07/16 10:43:22 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_map *m)
{
	m->i = 0;
	while (m->my_map[m->i])
	{
		m->j = 0;
		while (m->my_map[m->i][m->j] && m->my_map[m->i][m->j] != '\n')
		{
			if (m->my_map[m->i][m->j] == 'P')
			{
				if (m->my_map[m->i][m->j - 1] != '1')
				{
					m->nb_coups ++;
					if (m->my_map[m->i][m->j - 1] == 'E')
						check_collectibles(m);
					else
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
	while (m->my_map[m->i])
	{
		m->j = 0;
		while (m->my_map[m->i][m->j] && m->my_map[m->i][m->j] != '\n')
		{
			if (m->my_map[m->i][m->j] == 'P')
			{
				if (m->my_map[m->i - 1][m->j] != '1')
				{
					m->nb_coups ++;
					if (m->my_map[m->i - 1][m->j] == 'E')
						check_collectibles(m);
					else
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
	while (m->my_map[m->i])
	{
		m->j = 0;
		while (m->my_map[m->i][m->j] && m->my_map[m->i][m->j] != '\n')
		{
			if (m->my_map[m->i][m->j] == 'P')
			{
				if (m->my_map[m->i][m->j + 1] != '1')
				{
					m->nb_coups ++;
					if (m->my_map[m->i][m->j + 1] == 'E')
						check_collectibles(m);
					else
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
	while (m->my_map[m->i])
	{
		m->j = 0;
		while (m->my_map[m->i][m->j] && m->my_map[m->i][m->j] != '\n')
		{
			if (m->my_map[m->i][m->j] == 'P')
			{
				if (m->my_map[m->i + 1][m->j] != '1')
				{
					m->nb_coups ++;
					if (m->my_map[m->i + 1][m->j] == 'E')
						check_collectibles(m);
					else
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

void	check_collectibles(t_map *map)
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
		ft_quit(map, "WIN", 0);
}
