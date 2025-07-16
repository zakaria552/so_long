/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:50:24 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/16 16:10:34 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static bool	splitted_by_line(char *map);

bool	validate_map(char *fname, char *map)
{
	char	**split;

	if (!has_extension(fname, ".ber") || !splitted_by_line(map))
		return (false);
	split = ft_split(map, '\n');
	if (!split)
		return (false);
	if (!valid_char_set(split))
	{
		free_matrix_mem(split);
		return (false);
	}
	if (!is_rectangular(split))
	{
		free_matrix_mem(split);
		return (false);
	}
	if (!is_enclosed(split))
	{
		free_matrix_mem(split);
		return (false);
	}
	free_matrix_mem(split);
	return (true);
}

static bool	splitted_by_line(char *map)
{
	int	i;

	i = -1;
	if (map[0] == '\n')
		return (false);
	while (map[++i])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
			return (false);
	}
	if (map[i - 1] == '\n' && map[i - 2])
		return (false);
	return (true);
}
