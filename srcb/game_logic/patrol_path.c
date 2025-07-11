/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patrol_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:18:15 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/09 21:25:15 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_path_to_patrol(t_ctx *ctx)
{
	t_vec2	target;
	t_vec2	start;

	start.x = ctx->enemy->pos.x / ctx->map->size;
	start.y = ctx->enemy->pos.y / ctx->map->size;
	while (true)
	{
		target.x = random_num(1, ctx->map->bounds[0] - 2);
		target.y = random_num(1, ctx->map->bounds[1] - 2);
		if (ctx->map->grid[target.y][target.x] != '0')
			continue ;
		ctx->enemy->path = dfs_target(ctx->map, ctx->map->bounds, start,
				target);
		if (!ctx->enemy->path)
			continue ;
		break ;
	}
}
