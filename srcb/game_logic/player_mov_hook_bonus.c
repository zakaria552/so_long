/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mov_hook_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:33:44 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/15 23:27:30 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	move_player(t_ctx *ctx, int nx, int ny, t_dir dir);
static void	update_pos(t_asset *sprites[5], int nx, int ny);
static void	update_steps(t_ctx *ctx, const int off[2][2]);

void	move_hook(t_ctx *ctx)
{
	const t_vec2	*pos = ctx->player->pos;
	const int		speed = ctx->player->speed;

	if (mlx_is_key_down(ctx->mlx, MLX_KEY_W) || mlx_is_key_down(ctx->mlx,
			MLX_KEY_UP))
		move_player(ctx, pos->x, pos->y - speed, UP);
	else if (mlx_is_key_down(ctx->mlx, MLX_KEY_S) || mlx_is_key_down(ctx->mlx,
			MLX_KEY_DOWN))
		move_player(ctx, pos->x, pos->y + speed, DOWN);
	else if (mlx_is_key_down(ctx->mlx, MLX_KEY_A) || mlx_is_key_down(ctx->mlx,
			MLX_KEY_LEFT))
		move_player(ctx, pos->x - speed, pos->y, LEFT);
	else if (mlx_is_key_down(ctx->mlx, MLX_KEY_D) || mlx_is_key_down(ctx->mlx,
			MLX_KEY_RIGHT))
		move_player(ctx, pos->x + speed, pos->y, RIGHT);
	else
	{
		ctx->player->prev_dir = ctx->player->dir;
		ctx->player->dir = IDLE;
		if (ctx->player->prev_dir != IDLE)
		{
			ctx->player->ani_info->frame = 0;
			ctx->player->ani_info->frame_index = 0;
		}
	}
}

static void	update_pos(t_asset *sprites[5], int nx, int ny)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 5)
	{
		j = -1;
		while (++j < 5)
		{
			sprites[i][j].img->instances[0].x = nx;
			sprites[i][j].img->instances[0].y = ny;
		}
	}
}

static void	update_steps(t_ctx *ctx, const int off[2][2])
{
	t_vec2	new_pos;
	new_pos.x = ctx->player->pos->x / ctx->map->size;
	new_pos.y = (ctx->player->pos->y - off[1][1]) / ctx->map->size;
	if (new_pos.x == ctx->player->grid_pos.x
		&& new_pos.y == ctx->player->grid_pos.y)
		return ;
	ctx->player->grid_pos.x = new_pos.x;
	ctx->player->grid_pos.y = new_pos.y;
	ctx->player->steps += 1;
}

static void	move_player(t_ctx *ctx, int nx, int ny, t_dir dir)
{
	t_asset		*img;
	const int	offsets[2][2] = {{5, 5}, {0, 36}};

	img = ctx->player->sprites[dir];
	if (dir != ctx->player->dir)
	{
		ctx->player->ani_info->frame = 0;
		ctx->player->ani_info->frame_index = 0;
	}
	img = img + ctx->player->ani_info->frame;
	ctx->player->prev_dir = ctx->player->dir;
	ctx->player->dir = dir;
	ctx->player->pos->x = nx;
	ctx->player->pos->y = ny;
	if (check_collision(ctx, '1', offsets, ctx->player->pos))
	{
		ctx->player->pos->x = img->img->instances[0].x;
		ctx->player->pos->y = img->img->instances[0].y;
		return ;
	}
	update_steps(ctx, offsets);
	update_pos(ctx->player->sprites, nx, ny);
	return ;
}
