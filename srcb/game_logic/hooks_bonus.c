/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:23:53 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/15 23:09:48 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	endgame(t_ctx *ctx);
static void	update_steps(t_ctx *ctx);
static void	update_ui(t_ctx *ctx);

void	hooks(t_ctx *ctx)
{
	collect(ctx);
	endgame(ctx);
	update_ui(ctx);
}

void	key_hooks(mlx_key_data_t keydata, t_ctx *ctx)
{
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(ctx->mlx);
}

static void	endgame(t_ctx *ctx)
{
	const int	offsets[2][2] = {{40, 40}, {40, 40}};
	const int	offsets2[2][2] = {{15, 15}, {10, 10}};

	if (ctx->state->exited)
		mlx_close_window(ctx->mlx);
	if (player_collision(ctx->player->pos, &ctx->enemy->pos, offsets2))
	{
		ft_printf("You've been spotted\n");
		mlx_close_window(ctx->mlx);
	}
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
	char	*num_of_steps;

	num_of_steps = ft_itoa(ctx->player->steps);
	if (!num_of_steps)
		clean_exit(ctx, NULL, errno);
	free(ctx->ui.steps.str);
	mlx_delete_image(ctx->mlx, ctx->ui.steps.asset.img);
	ctx->ui.steps.str = ft_strjoin("steps: ", num_of_steps);
	free(num_of_steps);
	if (!ctx->ui.steps.str)
		clean_exit(ctx, NULL, errno);
	ctx->ui.steps.asset.img = mlx_put_string(ctx->mlx, ctx->ui.steps.str,
			ctx->ui.steps.pos.x, ctx->ui.steps.pos.y);
	if (!ctx->ui.steps.asset.img)
		clean_exit(ctx, NULL, errno);
}
