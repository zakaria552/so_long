/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:35:47 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/01 17:40:53by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	endgame(t_ctx *ctx);

void	hooks(t_ctx *ctx)
{
	collect(ctx);
	endgame(ctx);
}

void	key_hooks(mlx_key_data_t keydata, t_ctx *ctx)
{
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(ctx->mlx);
}

static void	endgame(t_ctx *ctx)
{
	const offsets[2][2] = {{40, 40}, {40, 40}};
	if (ctx->state->exited)
		mlx_close_window(ctx->mlx);
	if (!ctx->state->ready_to_exit)
		return ;
	if (!ctx->map->tiles->doors[1].img->instances[0].enabled)
	{
		ctx->map->tiles->doors[1].img->instances[0].enabled = true;
		ctx->map->tiles->doors[0].img->instances[0].enabled = false;
	}
	if (check_collision(ctx, 'E', offsets, ctx->player->pos))
		ctx->state->exited = true;
}
