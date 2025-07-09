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

static void	move_enemy(t_ctx *ctx, int nx, int ny, t_dir dir);

void	move_enemy_hook(t_ctx *ctx)
{
	const t_vec2	*pos = &ctx->enemy->pos;
	const int		speed = 1;
	const t_dir	dir = ctx->enemy->dir;

	//ft_printf("enemy move dir: %d", dir);
	if (dir == UP)
		move_enemy(ctx, pos->x, pos->y - speed, UP);
	else if (dir == DOWN)
		move_enemy(ctx, pos->x, pos->y + speed, DOWN);
	else if (dir == LEFT)
		move_enemy(ctx, pos->x - speed, pos->y, LEFT);
	else if (dir == RIGHT)
		move_enemy(ctx, pos->x + speed, pos->y, RIGHT);
	else
	{
		return;
		ctx->player->prev_dir = ctx->player->dir;
		ctx->player->dir = IDLE;
		if (ctx->player->prev_dir != IDLE)
		{
			ctx->player->ani_info->frame = 0;
			ctx->player->ani_info->frame_index = 0;
		}
	}
}

// t_asset *get_img_from_dir(t_ctx *ctx, t_dir dir)
// {
// 	if (dir == IDLE)
// 		return (ctx->map->tiles->idle);
// 	if (dir == RIGHT)
// 		return (ctx->map->tiles->right);
// 	if (dir == LEFT)
// 		return (ctx->map->tiles->left);
// 	if (dir == DOWN)
// 		return (ctx->map->tiles->down);
// 	if (dir == UP)
// 		return (ctx->map->tiles->up);
// }
// void update_pos2(t_tiles *tiles, int nx, int ny)
// {
// 	int i;

// 	i = -1;
// 	while (++i < 1)
// 	{
// 		tiles->idle[i].img->instances[0].x = nx;
// 		tiles->idle[i].img->instances[0].y = ny;
// 		continue;
// 		tiles->left[i].img->instances[0].x = nx;
// 		tiles->left[i].img->instances[0].y = ny;

// 		tiles->right[i].img->instances[0].x = nx;
// 		tiles->right[i].img->instances[0].y = ny;

// 		tiles->up[i].img->instances[0].x = nx;
// 		tiles->up[i].img->instances[0].y = ny;

// 		tiles->down[i].img->instances[0].x = nx;
// 		tiles->down[i].img->instances[0].y = ny;
// 	}
// }

void	move_enemy(t_ctx *ctx, int nx, int ny, t_dir dir)
{
	static int	move_count;
	t_asset	*img = ctx->enemy->idle;
	const int	offsets[2][2] = {{10, 10}, {0, 36}};
	//const int	frame_index = ctx->player->ani_info->frame;

	//if (dir != ctx->player->dir)
	//{
		//ctx->player->ani_info->frame = 0;
		//ctx->player->ani_info->frame_index = 0;
	//}
	//img = img + ctx->player->ani_info->frame;
	//ctx->player->prev_dir = ctx->player->dir;
	//ctx->player->dir = dir;
	ctx->enemy->pos.x = nx;
	ctx->enemy->pos.y = ny;
	//ft_printf("new post: (%d, %d)", ctx->enemy->pos.x, ctx->enemy->pos.y);
	if (check_collision(ctx, '1', offsets, &ctx->enemy->pos))
	{
		//ft_printf("Collision with wall\n");
		ctx->enemy->pos.x = img->img->instances[0].x;
		ctx->enemy->pos.y = img->img->instances[0].y;
		return ;
	}
	
	img->img->instances[0].x = nx;
	img->img->instances[0].y = ny;

	//ft_printf("Move count: %d\n", ++move_count);
	// if (move_count == 64*100)
	// 	exit(1);
	//update_pos(ctx->map->tiles, nx, ny);
	return ;
}
