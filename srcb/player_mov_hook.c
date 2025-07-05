/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mov_hook.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:46:42 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/05 15:15:30y zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_player(t_ctx *ctx, int nx, int ny, t_dir dir);

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

t_asset *get_img_from_dir(t_ctx *ctx, t_dir dir)
{
	if (dir == IDLE)
		return (ctx->map->tiles->idle);
	if (dir == RIGHT)
		return (ctx->map->tiles->right);
	if (dir == LEFT)
		return (ctx->map->tiles->left);
	if (dir == DOWN)
		return (ctx->map->tiles->down);
	if (dir == UP)
		return (ctx->map->tiles->up);
}
void update_pos(t_tiles *tiles, int nx, int ny)
{
	int i;

	i = -1;
	while (++i < 5)
	{
		tiles->idle[i].img->instances[0].x = nx;
		tiles->idle[i].img->instances[0].y = ny;

		tiles->left[i].img->instances[0].x = nx;
		tiles->left[i].img->instances[0].y = ny;

		tiles->right[i].img->instances[0].x = nx;
		tiles->right[i].img->instances[0].y = ny;

		tiles->up[i].img->instances[0].x = nx;
		tiles->up[i].img->instances[0].y = ny;

		tiles->down[i].img->instances[0].x = nx;
		tiles->down[i].img->instances[0].y = ny;
	}
}
void	move_player(t_ctx *ctx, int nx, int ny, t_dir dir)
{
	static int	move_count;
	t_asset	*img = get_img_from_dir(ctx, ctx->player->dir);
	const int	offsets[2][2] = {{10, 10}, {0, 36}};
	const int	frame_index = ctx->player->ani_info->frame;

	ft_printf("");
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
	if (check_collision(ctx, '1', offsets))
	{
		ctx->player->pos->x = img->img->instances[0].x;
		ctx->player->pos->y = img->img->instances[0].y;
		return ;
	}
	
	ft_printf("Move count: %d\n", ++move_count);
	update_pos(ctx->map->tiles, nx, ny);
	return ;
}
