/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patrol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:54:23 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/12 23:29:35 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	rm_visted_tile(t_ctx *ctx);
static void	set_dir(t_enemy *enemy);
static void	change_dir(t_ctx *ctx, t_list *path, t_enemy *enemy);
static bool	reached_tile(t_vec2 *pos, int x, int y, const int off[2][2]);

void	patrol(t_ctx *ctx)
{
	ft_printf("dir: %d", ctx->enemy->dir);
	stay_alert(ctx);
	// return;
	if(!ctx->enemy->path)
		return;
	// 	set_path_to_patrol(ctx);
	change_dir(ctx, ctx->enemy->path, ctx->enemy);
	move_enemy_hook(ctx);
}

static void	set_dir(t_enemy *enemy)
{
	t_list	*path;
	t_vec2	*next_tile;

	path = enemy->path;
	while (path)
	{
		next_tile = path->content;
		path = path->next;
	}
	if ((next_tile->x + 1) == (enemy->pos.x / 64))
		enemy->dir = LEFT;
	else if ((next_tile->x - 1) == (enemy->pos.x / 64))
		enemy->dir = RIGHT;
	else if ((next_tile->y + 1) == (enemy->pos.y / 64))
		enemy->dir = UP;
	else if ((next_tile->y - 1) == (enemy->pos.y / 64))
		enemy->dir = DOWN;
	else 
		enemy->dir = IDLE;
}

static void	rm_visted_tile(t_ctx *ctx)
{
	t_list	*tmp;

	tmp = ctx->enemy->path;
	while (tmp->next)
		tmp = tmp->next;
	ft_lstdellast(&(ctx->enemy->path), free);
}

static bool	reached_tile(t_vec2 *pos, int x, int y, const int off[2][2])
{
	int	s;

	s = 64;
	if ((pos->x + 48 - off[0][0]) > x * s && (pos->x + off[0][1]) < (x * s + s)
		&& (pos->y + 48 - off[1][0]) > (y * s) && (pos->y + off[1][1]) < (y * s
			+ s))
		return (true);
	return (false);
}

static void	change_dir(t_ctx *ctx, t_list *path, t_enemy *enemy)
{
	t_vec2		*tile;
	const int	off[5][2][2] = {{{0, 0}, {0, 60}}, {{0, 0}, {60, 0}}, {{0, 60},
	{0, 0}}, {{60, 0}, {0, 0}}, {{20, 50}, {40, 10}}};

	while (path->next)
		path = path->next;
	tile = (t_vec2 *)path->content;
	if (!reached_tile(&enemy->pos, tile->x, tile->y, off[enemy->dir]))
		return ;
	rm_visted_tile(ctx);
	set_dir(enemy);
}
