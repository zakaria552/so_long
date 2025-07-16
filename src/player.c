/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:48:01 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/16 13:36:35 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_player_pos(t_ctx *ctx);

void	initialize_player(t_ctx *ctx)
{
	ctx->player = malloc(sizeof(t_player));
	if (!ctx->player)
		clean_exit(ctx, NULL, errno);
	ctx->player->pos = NULL;
	ctx->player->pos = malloc(sizeof(t_vec2));
	if (!ctx->player->pos)
		clean_exit(ctx, NULL, errno);
	ctx->player->orbs = 0;
	ctx->player->speed = 6;
	init_player_pos(ctx);
	ctx->player->grid_pos.x = ctx->player->pos->x;
	ctx->player->grid_pos.y = ctx->player->pos->y;
}

static void	init_player_pos(t_ctx *ctx)
{
	char	**grid;
	int		x;
	int		y;

	grid = ctx->map->grid;
	y = -1;
	while (grid[++y])
	{
		x = -1;
		while (grid[y][++x])
		{
			if (grid[y][x] == 'P')
			{
				ctx->player->pos->x = x;
				ctx->player->pos->y = y;
				return ;
			}
		}
	}
}
