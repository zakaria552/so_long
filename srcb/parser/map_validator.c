/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:50:24 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/01 18:32:24 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	validate_map(char *fname, char *map)
{
	char	**split;

	if (!has_extension(fname, ".ber"))
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
