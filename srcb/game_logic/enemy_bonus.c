/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:22:53 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/16 17:02:39 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	init_enemy_pos(t_ctx *ctx);

void	initialize_enemy(t_ctx *ctx)
{
	ctx->enemy = malloc(sizeof(t_enemy));
	if (!ctx->enemy)
		clean_exit(ctx, NULL, errno);
	ctx->enemy->vision = malloc(sizeof(t_vision));
	if (!ctx->enemy->vision)
		clean_exit(ctx, NULL, errno);
	ctx->enemy->vision->r = 20;
	ctx->enemy->pos.x = 0;
	ctx->enemy->pos.y = 0;
	ctx->enemy->dir = IDLE;
	ctx->enemy->speed = 1;
	ctx->enemy->path = NULL;
	ctx->enemy->ani_info.frame_index = 0;
	ctx->enemy->ani_info.frame = 0;
	ctx->enemy->ani_info.lt = 0;
	ctx->enemy->persuing = false;
	init_enemy_pos(ctx);
	set_patrol_paths(ctx);
}

static void	init_enemy_pos(t_ctx *ctx)
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
			if (grid[y][x] == 'X')
			{
				ctx->enemy->pos.x = x;
				ctx->enemy->pos.y = y;
				return ;
			}
		}
	}
}
