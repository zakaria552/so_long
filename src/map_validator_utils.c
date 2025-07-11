/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:50:24 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/11 17:41:22 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void init_char_set(int *e, int *c, int *p, int *y);

bool	valid_char_set(char **map)
{
	int	x;
	int	y;
	int	e;
	int	p;
	int	c;

	init_char_set(&e, &c, &p, &y);
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (!ft_strchr("01CEP", map[y][x]))
				return (false);
			if (map[y][x] == 'P')
				p++;
			if (map[y][x] == 'C')
				c++;
			if (map[y][x] == 'E')
				e++;
		}
	}
	return (p == 1 && c > 0 && e == 1);
}

static	void init_char_set(int *e, int *c, int *p, int *y)
{
	*e = 0;
	*p = 0;
	*c = 0;
	*y = 0;
}

bool	is_rectangular(char **map)
{
	int	w;
	int	h;
	int	i;

	h = 0;
	w = 0;
	while (map[h])
	{
		i = 0;
		while (map[h][i])
			i++;
		if (h && i != w)
			return (false);
		w = i;
		h++;
	}
	if (h < 2 || w < 2 || h == w)
		return (false);
	return (true);
}

bool	has_extension(char *name, char *ext)
{
	char	*last_dot;

	last_dot = ft_strrchr(name, '.');
	if (!*last_dot)
		return (false);
	if (ft_strncmp(last_dot, ext, ft_strlen(ext)) == 0)
		return (true);
	return (false);
}

bool	is_enclosed(char **map)
{
	int	w;
	int	h;
	int	i;

	w = ft_strlen(map[0]);
	h = 0;
	while (map[h])
		h++;
	i = -1;
	while (map[0][++i])
	{
		if (map[0][i] != '1' || map[h - 1][i] != '1')
			return (false);
	}
	i = -1;
	while (++i < h && map[i][0])
	{
		if (map[i][0] != '1' || map[i][w - 1] != '1')
			return (false);
	}
	return (true);
}
