/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:12:35 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/10 15:29:23y zfarah           ###   ########.fr       */
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


void    draw_ui(t_ctx *ctx)
{
    ctx->ui.steps.pos.x = 10;
    ctx->ui.steps.pos.y = 4;
	ctx->ui.steps.str = ft_strdup("steps: 0");
	ctx->ui.steps.asset.txt = NULL;
	if (!ctx->ui.steps.str)
		clean_exit(ctx, NULL, errno);
	ctx->ui.steps.asset.img = mlx_put_string(ctx->mlx, ctx->ui.steps.str, 10, 4);
	if (!ctx->ui.steps.asset.img)
		clean_exit(ctx, NULL, errno);
	ctx->ui.collected.pos.x = 10 + 5;
	// ctx->ui.collected.pos.y = 4;
	//ctx->ui.collected.str = ft_strdup("Collected: 0");
    // ctx->ui.collected.asset.txt = NULL;
	// if (!ctx->ui.collected.str)
	// 	clean_exit(ctx, NULL, errno);
	//ctx->ui.collected.asset.img = mlx_put_string(ctx->mlx, ctx->ui.collected.str, 100, 4);
	// if (!ctx->ui.collected.asset.img)
	// 	clean_exit(ctx, NULL, errno);
}
