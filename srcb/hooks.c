/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:23:53 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/10 17:45:57 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	endgame(t_ctx *ctx);
static void	update_steps(t_ctx *ctx);
static void	update_ui(t_ctx *ctx);

void	hooks(t_ctx *ctx)
{
	collect(ctx);
	endgame(ctx);
	update_steps(ctx);
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

static void	update_ui(t_ctx *ctx)
{
	update_steps(ctx);
}

static void	update_steps(t_ctx *ctx)
{
	free(ctx->ui.steps.str);
	mlx_delete_image(ctx->mlx, ctx->ui.steps.asset.img);
	ctx->ui.steps.str = ft_strjoin("steps: ", ft_itoa(ctx->player->steps));
	if (!ctx->ui.steps.str)
		clean_exit(ctx, NULL, errno);
	ctx->ui.steps.asset.img = mlx_put_string(ctx->mlx, ctx->ui.steps.str,
			ctx->ui.steps.pos.x, ctx->ui.steps.pos.y);
	if (!ctx->ui.steps.asset.img)
		clean_exit(ctx, NULL, errno);
}
