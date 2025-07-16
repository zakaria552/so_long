/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:41:21 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/16 14:38:23 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_game_state(t_ctx *ctx);

t_ctx	*ctx_init(char *map_name)
{
	t_ctx	*ctx;

	ctx = malloc(sizeof(t_ctx));
	if (!ctx)
		clean_exit(ctx, strerror(errno), errno);
	ctx->map = NULL;
	ctx->player = NULL;
	ctx->mlx = NULL;
	ctx->state = NULL;
	ctx->map = parse_map(map_name);
	if (!ctx->map)
		clean_exit(ctx, NULL, errno);
	init_game_state(ctx);
	return (ctx);
}

static void	init_game_state(t_ctx *ctx)
{
	int		x;
	int		y;
	t_map	*map;

	x = -1;
	y = -1;
	map = ctx->map;
	ctx->state = malloc(sizeof(t_game_state));
	if (!ctx->state)
		clean_exit(ctx, strerror(errno), errno);
	ctx->state->collected = 0;
	ctx->state->total_orbs = 0;
	ctx->state->exited = false;
	ctx->state->ready_to_exit = false;
	while (map->grid[++y])
	{
		x = -1;
		while (map->grid[y][++x])
		{
			if (map->grid[y][x] == 'C')
				ctx->state->total_orbs += 1;
		}
	}
}
