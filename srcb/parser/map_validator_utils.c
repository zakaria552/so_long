/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:50:24 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/15 21:19:11 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	c_index(const char chars[4], char c);

bool	valid_char_set(char **map)
{
	const char	chars[4] = {'P', 'C', 'E', 'X'};
	int			counts[4];
	int			x;
	int			y;

	ft_memset(counts, 0, sizeof(int) * 4);
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (!ft_strchr("01CEPX", map[y][x]))
				return (false);
			if (map[y][x] == '1' || map[y][x] == '1')
				continue ;
			counts[c_index(chars, map[y][x])] += 1;
		}
	}
	return (counts[0] == 1 && counts[1] > 0 && counts[2] == 1
		&& counts[3] == 1);
}

static int	c_index(const char chars[4], char c)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (chars[i] == c)
			break ;
	}
	return (i);
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
