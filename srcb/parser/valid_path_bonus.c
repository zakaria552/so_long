/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:53:46 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/15 23:09:48 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

bool	valid_path_exists(t_ctx *ctx)
{
	const t_player	*player = ctx->player;
	const t_map		*map = ctx->map;
	t_list			*path;
	int				x;
	int				y;

	y = -1;
	while (map->grid[++y])
	{
		x = -1;
		while (map->grid[y][++x])
		{
			if (map->grid[y][x] == '1' || map->grid[y][x] == '0'
				|| map->grid[y][x] == 'P' || map->grid[y][x] == 'X')
				continue ;
			path = dfs_target(ctx, *player->pos, target_vec(x, y));
			if (!path)
				return (false);
			ft_lstclear(&path, free);
		}
	}
	return (true);
}

t_vec2	target_vec(int x, int y)
{
	t_vec2	target;

	target.x = x;
	target.y = y;
	return (target);
}
