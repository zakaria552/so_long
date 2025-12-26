/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_mov_hook_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:18:41 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/15 23:09:48 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_pos(t_asset *sprites[5], int nx, int ny);
static void	move_enemy(t_ctx *ctx, int nx, int ny, t_dir dir);

void	move_enemy_hook(t_ctx *ctx)
{
	const t_vec2	*pos = &ctx->enemy->pos;
	const int		speed = ctx->enemy->speed;
	const t_dir		dir = ctx->enemy->dir;

	if (dir == UP)
		move_enemy(ctx, pos->x, pos->y - speed, UP);
	else if (dir == DOWN)
		move_enemy(ctx, pos->x, pos->y + speed, DOWN);
	else if (dir == LEFT)
		move_enemy(ctx, pos->x - speed, pos->y, LEFT);
	else if (dir == RIGHT)
		move_enemy(ctx, pos->x + speed, pos->y, RIGHT);
}

static void	move_enemy(t_ctx *ctx, int nx, int ny, t_dir dir)
{
	t_asset	*img;

	img = ctx->enemy->sprites[dir];
	ctx->enemy->pos.x = nx;
	ctx->enemy->pos.y = ny;
	img->img->instances[0].x = nx;
	img->img->instances[0].y = ny;
	update_pos(ctx->enemy->sprites, nx, ny);
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
