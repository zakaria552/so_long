/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mov_hook.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:46:42 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/01 20:49:36 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_player(t_ctx *ctx, int nx, int ny);

void	move_hook(t_ctx *ctx)
{
	const t_vec2	*pos = ctx->player->pos;
	const int		speed = ctx->player->speed;

	if (mlx_is_key_down(ctx->mlx, MLX_KEY_W) || mlx_is_key_down(ctx->mlx,
			MLX_KEY_UP))
		move_player(ctx, pos->x, pos->y - speed);
	if (mlx_is_key_down(ctx->mlx, MLX_KEY_S) || mlx_is_key_down(ctx->mlx,
			MLX_KEY_DOWN))
		move_player(ctx, pos->x, pos->y + speed);
	if (mlx_is_key_down(ctx->mlx, MLX_KEY_A) || mlx_is_key_down(ctx->mlx,
			MLX_KEY_LEFT))
		move_player(ctx, pos->x - speed, pos->y);
	if (mlx_is_key_down(ctx->mlx, MLX_KEY_D) || mlx_is_key_down(ctx->mlx,
			MLX_KEY_RIGHT))
		move_player(ctx, pos->x + speed, pos->y);
}

void	move_player(t_ctx *ctx, int nx, int ny)
{
	static int	move_count;
	mlx_image_t	*img;
	const int	offsets[2][2] = {{10, 10}, {0, 36}};

	img = ctx->map->tiles->p_idle->img;
	ctx->player->pos->x = nx;
	ctx->player->pos->y = ny;
	if (check_collision(ctx, '1', offsets))
	{
		ctx->player->pos->x = img->instances[0].x;
		ctx->player->pos->y = img->instances[0].y;
		return ;
	}
	ft_printf("Move count: %d\n", ++move_count);
	img->instances[0].x = nx;
	img->instances[0].y = ny;
	return ;
}
