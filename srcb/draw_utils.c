/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:12:35 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/09 21:16:51 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_enemy(t_ctx *ctx)
{
	const int	tile_size = ctx->map->size;
	t_vec2		*pos;
	int			i;

	i = -1;
	pos = &ctx->enemy->pos;
	pos->x *= ctx->map->size;
	pos->y *= ctx->map->size;
	ctx->player->vision->img = new_img(ctx, ctx->map->width, ctx->map->height);
	img_to_window(ctx, ctx->player->vision->img, 0, 0);
	while (++i < 5)
	{
		img_to_window(ctx, ctx->enemy->idle[i].img, pos->x, pos->y);
		img_to_window(ctx, ctx->enemy->right[i].img, pos->x, pos->y);
		img_to_window(ctx, ctx->enemy->left[i].img, pos->x, pos->y);
		img_to_window(ctx, ctx->enemy->up[i].img, pos->x, pos->y);
		img_to_window(ctx, ctx->enemy->down[i].img, pos->x, pos->y);
	}
}
