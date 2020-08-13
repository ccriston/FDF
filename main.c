/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <ccriston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:36:27 by psigfry           #+#    #+#             */
/*   Updated: 2020/02/29 20:29:08 by ccriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_close(void)
{
	exit(0);
	return (0);
}

void	err_out(int e)
{
	if (e == 0)
		write(2, "Error! Don't have memory\n", 25);
	if (e == 1)
		write(1, "Usage: ./fdf <filename>\n", 24);
	if (e == 2)
		write(2, "Invalid map2\n", 12);
	if (e == 3)
		write(2, "Invalid data\n", 13);
	exit(0);
}

int		main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		err_out(1);
	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		err_out(2);
	ft_valid(argv[1], map);
	map->mid_x = (map->w - 1) * SCALE / 2;
	map->mid_y = (map->h - 1) * SCALE / 2;
	move_center(map);
	create_loop(map);
	exit(0);
}
