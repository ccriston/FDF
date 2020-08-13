/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <ccriston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:38:20 by psigfry           #+#    #+#             */
/*   Updated: 2020/02/29 20:29:45 by ccriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_pluscale(t_map *fdf)
{
	int x;
	int y;

	y = 0;
	if (fdf->scale < 100)
	{
		fdf->scale *= 2;
		move_mid(fdf);
		while (y < fdf->h)
		{
			x = 0;
			while (x < fdf->w)
			{
				fdf->points[y][x].x *= 2;
				fdf->points[y][x].y *= 2;
				fdf->points[y][x].z *= 2;
				x++;
			}
			y++;
		}
		move_back(fdf);
	}
}

void			ft_minscale(t_map *fdf)
{
	int x;
	int y;

	y = 0;
	if (fdf->scale > 2)
	{
		fdf->scale /= 2;
		move_mid(fdf);
		while (y < fdf->h)
		{
			x = 0;
			while (x < fdf->w)
			{
				fdf->points[y][x].x /= 2;
				fdf->points[y][x].y /= 2;
				fdf->points[y][x].z /= 2;
				++x;
			}
			y++;
		}
		move_back(fdf);
	}
}
