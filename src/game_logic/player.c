/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:48:01 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/17 12:50:53 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_player(t_ctx *ctx);
static void	init_player_pos(t_ctx *ctx);

void	initialize_player(t_ctx *ctx)
{
	ctx->player = malloc(sizeof(t_player));
	if (!ctx->player)
		clean_exit(ctx, NULL, errno);
	ctx->player->pos = malloc(sizeof(t_vec2));
	if (!ctx->player->pos)
		clean_exit(ctx, NULL, errno);
	ctx->player->vision = malloc(sizeof(t_vision));
	if (!ctx->player->vision)
		clean_exit(ctx, NULL, errno);
	ctx->player->vision->img = NULL;
	ctx->player->ani_info = malloc(sizeof(t_animation_info));
	if (!ctx->player->ani_info)
		clean_exit(ctx, NULL, errno);
	init_player(ctx);
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

static void	init_player(t_ctx *ctx)
{
	ctx->player->orbs = 0;
	ctx->player->speed = 150;
	ctx->player->vision->r = 150;
	ctx->player->idle = true;
	ctx->player->ani_info->frame_index = 0;
	ctx->player->ani_info->frame = 0;
	ctx->player->ani_info->lt = 0;
	ctx->player->dir = IDLE;
	ctx->player->prev_dir = IDLE;
	ctx->player->steps = 0;
	init_player_pos(ctx);
	ctx->player->grid_pos.x = ctx->player->pos->x;
	ctx->player->grid_pos.y = ctx->player->pos->y;
}
