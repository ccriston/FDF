/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <ccriston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:36:45 by psigfry           #+#    #+#             */
/*   Updated: 2020/02/29 15:57:04 by ccriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			mouse_move(int x, int y, t_mlx *img)
{
	if (img->pres_m == 1)
	{
		destroy(img);
		move_img(img->map, x - img->pres_x, y - img->pres_y);
		img->pres_y = y;
		img->pres_x = x;
		re_draw(img);
	}
	return (0);
}

int			mouse_pres(int btn, int x, int y, t_mlx *img)
{
	if (btn == 1)
	{
		img->pres_m = 1;
		img->pres_x = x;
		img->pres_y = y;
	}
	if (btn == 4)
	{
		destroy(img);
		ft_pluscale(img->map);
		re_draw(img);
	}
	if (btn == 5)
	{
		destroy(img);
		ft_minscale(img->map);
		re_draw(img);
	}
	return (0);
}

int			mouse_release(int btn, int x, int y, t_mlx *img)
{
	x = y;
	if (btn == 1)
		img->pres_m = 0;
	return (0);
}
