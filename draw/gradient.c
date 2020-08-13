/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psigfry <psigfry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:10:37 by psigfry           #+#    #+#             */
/*   Updated: 2020/03/02 15:15:53 by psigfry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			rgb_to_int(t_rgb rgb)
{
	return ((int)(rgb.r << 16) + (int)(rgb.g << 8) + (int)(rgb.b));
}

t_rgb		get_rgb_color(int color)
{
	t_rgb	rgb;

	rgb.r = color >> 16 & 0xFF;
	rgb.g = color >> 8 & 0xFF;
	rgb.b = color & 0xFF;
	return (rgb);
}

int			get_color(int color1, int color2, double f)
{
	t_rgb	rgb1;
	t_rgb	rgb2;
	t_rgb	rgb3;

	rgb1 = get_rgb_color(color1);
	rgb2 = get_rgb_color(color2);
	rgb3.r = rgb1.r + (rgb2.r - rgb1.r) * f;
	rgb3.g = rgb1.g + (rgb2.g - rgb1.g) * f;
	rgb3.b = rgb1.b + (rgb2.b - rgb1.b) * f;
	return (rgb_to_int(rgb3));
}

double		get_coeff(int *cr)
{
	double		length;
	double		dist;

	length = sqrt(pow(cr[2] - cr[6], 2) + pow(cr[3] - cr[7], 2));
	dist = sqrt(pow(cr[6] - cr[0], 2) + pow(cr[7] - cr[1], 2));
	return (dist / length);
}
