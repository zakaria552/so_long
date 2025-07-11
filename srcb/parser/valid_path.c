/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:53:46 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/07 17:39:00 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_vec2	target_vec(int x, int y);

bool	valid_path_exists(t_map *map, t_player *player)
{
	t_list	*path;
	int		x;
	int		y;

	y = -1;
	while (map->grid[++y])
	{
		x = -1;
		while (map->grid[y][++x])
		{
			if (map->grid[y][x] == '1' || map->grid[y][x] == '0'
				|| map->grid[y][x] == 'P' || map->grid[y][x] == 'X')
				continue ;
			path = dfs_target(map, map->bounds, *player->pos, target_vec(x, y));
			if (!path)
				return (false);
			ft_lstclear(&path, free);
		}
	}
	return (true);
}

static t_vec2	target_vec(int x, int y)
{
	t_vec2	target;

	target.x = x;
	target.y = y;
	return (target);
}
