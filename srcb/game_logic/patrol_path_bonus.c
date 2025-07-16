/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patrol_path_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:18:15 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/16 18:33:42 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static bool	is_valid_target(t_vec2 parol_paths[5], t_vec2 target);
static void	init_patrol_paths(t_ctx *ctx);

void	set_path_to_patrol(t_ctx *ctx)
{
	static int	i;
	t_vec2		target;
	t_vec2		start;

	start.x = ctx->enemy->pos.x / ctx->map->size;
	start.y = ctx->enemy->pos.y / ctx->map->size;
	if (i == 5)
		i = 0;
	target = ctx->enemy->patrol_paths[i];
	ctx->enemy->path = bfs_target(ctx, start, target);
	i++;
}

void	set_patrol_paths(t_ctx *ctx)
{
	t_vec2	target;
	t_vec2	start;
	int		i;

	start.x = ctx->enemy->pos.x;
	start.y = ctx->enemy->pos.y;
	init_patrol_paths(ctx);
	i = 0;
	while (true && i < 5)
	{
		target.x = random_num(1, ctx->map->bounds[0] - 2);
		target.y = random_num(1, ctx->map->bounds[1] - 2);
		if (ctx->map->grid[target.y][target.x] != '0'
			|| !is_valid_target(ctx->enemy->patrol_paths, target))
			continue ;
		ctx->enemy->path = dfs_target(ctx, start, target);
		if (!ctx->enemy->path)
			continue ;
		ctx->enemy->patrol_paths[i].x = target.x;
		ctx->enemy->patrol_paths[i].y = target.y;
		i++;
		ft_lstclear(&(ctx->enemy->path), free);
	}
}

static bool	is_valid_target(t_vec2 parol_paths[5], t_vec2 target)
{
	int	i;

	i = -1;
	while (++i < 5)
	{
		if (parol_paths[i].x == target.x && parol_paths[i].y == target.y)
			return (false);
	}
	return (true);
}

static void	init_patrol_paths(t_ctx *ctx)
{
	int i;

	i = -1;
	while (++i < 5)
	{
		ctx->enemy->patrol_paths[i].x = -1;
		ctx->enemy->patrol_paths[i].y = -1;
	}
}