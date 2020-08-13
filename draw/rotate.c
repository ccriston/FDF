/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <ccriston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:38:08 by psigfry           #+#    #+#             */
/*   Updated: 2020/02/29 14:10:02 by ccriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			rotate_x(t_map *map, double angle)
{
	int		i;
	int		j;
	float	tmp_y;
	float	tmp_z;

	i = -1;
	move_mid(map);
	while (++i < map->h)
	{
		j = -1;
		while (++j < map->w)
		{
			tmp_y = map->points[i][j].y;
			tmp_z = map->points[i][j].z;
			map->points[i][j].y = tmp_y * cos(angle) + tmp_z * sin(angle);
			map->points[i][j].z = -tmp_y * sin(angle) + tmp_z * cos(angle);
		}
	}
	move_back(map);
}

void			rotate_y(t_map *map, double angle)
{
	int		i;
	int		j;
	float	tmp_x;
	float	tmp_z;

	i = -1;
	move_mid(map);
	while (++i < map->h)
	{
		j = -1;
		while (++j < map->w)
		{
			tmp_x = map->points[i][j].x;
			tmp_z = map->points[i][j].z;
			map->points[i][j].x = tmp_x * cos(angle) + tmp_z * sin(angle);
			map->points[i][j].z = -tmp_x * sin(angle) + tmp_z * cos(angle);
		}
	}
	move_back(map);
}

void			rotate_z(t_map *map, double angle)
{
	int		i;
	int		j;
	float	tmp_x;
	float	tmp_y;

	i = -1;
	move_mid(map);
	while (++i < map->h)
	{
		j = -1;
		while (++j < map->w)
		{
			tmp_x = map->points[i][j].x;
			tmp_y = map->points[i][j].y;
			map->points[i][j].x = tmp_x * cos(angle) - tmp_y * sin(angle);
			map->points[i][j].y = tmp_x * sin(angle) + tmp_y * cos(angle);
		}
	}
	move_back(map);
}
