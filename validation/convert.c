/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <ccriston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 10:55:56 by ccriston          #+#    #+#             */
/*   Updated: 2020/02/29 20:28:54 by ccriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int			ft_isint(const char *str)
{
	long long int	num;
	int				sign;

	num = 0;
	while (('\t' <= *str && *str <= '\r') || *str == ' ')
		++str;
	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		++str;
	while ('0' <= *str && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		if ((sign == -1 && -num < -2147483648) ||
		(sign == 1 && num > 2147483647))
			return (0);
		++str;
	}
	if (*str != '\0' && *str != ' ')
		return (0);
	return (1);
}

static unsigned int	ft_atoi16(const char *str)
{
	unsigned int	f;
	unsigned int	i;
	unsigned int	result;
	unsigned int	res;
	char			*arr;

	arr = "0123456789ABCDEF";
	f = 0;
	while ((str[f] >= '0' && str[f] <= '9') || (str[f] >= 'A' && str[f] <= 'F'))
		f++;
	i = f;
	result = 16;
	while (--i)
		result = result * 16;
	res = 0;
	while ((result = result / 16) > 0)
	{
		f = 0;
		while (arr[f] != str[i] && str[i] != '\0')
			f++;
		res = f * result + res;
		i++;
	}
	return (res);
}

static void			ft_fillcoord(int x, int y, int z, t_point *new)
{
	new->x = x * SCALE;
	new->y = y * SCALE;
	new->z = z * SCALE;
}

static int			ft_checkcolor(char *str, int i, t_point *new)
{
	int j;

	j = 0;
	if (str[i] == ',')
	{
		new->clr = ft_atoi16(str + (i + 3));
		j = 0;
		while (str[i] != ' ' && str[i] != '\0')
		{
			if (str[i] != ',' && str[i] != 'x' && (str[i] < '0' || str[i] > '9')
			&& (str[i] < 'A' || str[i] > 'F'))
				return (0);
			i++;
			j++;
		}
		if (j != 9)
			return (0);
	}
	else
		new->clr = 0xFFFFFF - new->z / SCALE * 0x808;
	return (i);
}

t_point				*ft_mkint(char *str, int n, int y)
{
	t_point		*new;
	int			i[2];

	if (!(new = (t_point *)malloc(sizeof(t_point) * (n + 1))))
		exit(0);
	i[0] = 0;
	i[1] = 0;
	while (str[i[0]] != '\0' && i[1] <= n)
		if (str[i[0]] == ' ')
			i[0]++;
		else if ((str[i[0]] >= '0' && str[i[0]] <= '9') || ((str[i[0]] == '-' ||
		str[i[0]] == '+') && (str[i[0] + 1] >= '0' && str[i[0] + 1] <= '9')))
		{
			if (ft_isint(str + i[0]) == 0)
				err_out(3);
			ft_fillcoord(i[1], y, ft_atoi(str + i[0]), &new[i[1]]);
			i[1]++;
			while ((str[i[0]] >= '0' && str[i[0]] <= '9') || str[i[0]] == '-')
				i[0]++;
			if ((i[0] = ft_checkcolor(str, i[0], &new[i[1] - 1])) == 0)
				return (0);
		}
		else
			return (0);
	return (new);
}
