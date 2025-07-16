/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 21:22:40 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/16 19:05:05 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	draw_player(t_ctx *ctx);
static void	draw_exit(t_ctx *ctx);
static void	draw_map_borders(t_ctx *ctx, t_asset *walls, int size);
static void	draw_map_grid(t_ctx *ctx, t_map *map);

void	draw_map(t_ctx *ctx)
{
	t_tiles	*tiles;
	int		tile_size;

	tiles = ctx->map->tiles;
	tile_size = ctx->map->size;
	draw_map_borders(ctx, tiles->walls, tile_size);
	draw_map_grid(ctx, ctx->map);
	draw_exit(ctx);
	draw_enemy(ctx);
	draw_player(ctx);
	draw_ui(ctx);
}

static void	draw_map_borders(t_ctx *ctx, t_asset *walls, int size)
{
	int	x;
	int	y;

	x = 0;
	y = -1;
	while (++y < ctx->map->bounds[1] - 1)
	{
		img_to_window(ctx, walls[0].img, x * size, y * size);
		img_to_window(ctx, walls[0].img, (ctx->map->bounds[0] - 1) * size, y
			* size);
	}
	y = 0;
	x = 0;
	while (++x < ctx->map->bounds[0] - 1)
	{
		img_to_window(ctx, walls[1].img, x * size, y * size);
		img_to_window(ctx, walls[1].img, x * size, (ctx->map->bounds[1] - 1)
			* size);
	}
	img_to_window(ctx, walls[1].img, 0 * size, (ctx->map->bounds[1] - 1)
		* size);
	img_to_window(ctx, walls[1].img, (ctx->map->bounds[0] - 1) * size,
		(ctx->map->bounds[1] - 1) * size);
}

static void	draw_map_grid(t_ctx *ctx, t_map *map)
{
	const char		**grid = (const char **)map->grid;
	const t_tiles	*tiles = map->tiles;
	int				x;
	int				y;

	y = 0;
	while (++y < map->bounds[1] - 1)
	{
		x = 0;
		while (++x < ctx->map->bounds[0] - 1)
		{
			if (grid[y][x] == '1' && grid[y + 1][x] != '1')
				img_to_window(ctx, tiles->walls[1].img, x * map->size, y
					* map->size);
			else if (grid[y][x] == '1' && grid[y + 1][x] == '1')
				img_to_window(ctx, tiles->walls[0].img, x * map->size, y
					* map->size);
			else
				img_to_window(ctx, tiles->floors[random_num(0, 3)].img, x
					* map->size, y * map->size);
			if (grid[y][x] == 'C')
				img_to_window(ctx, tiles->orbs->img, x * map->size, y
					* map->size);
		}
	}
}

static void	draw_player(t_ctx *ctx)
{
	t_tiles	*tiles;
	t_vec2	*pos;
	int		i;

	i = -1;
	tiles = ctx->map->tiles;
	pos = ctx->player->pos;
	pos->x *= ctx->map->size;
	pos->y *= ctx->map->size;
	ctx->player->vision->img = new_img(ctx, ctx->map->width, ctx->map->height);
	img_to_window(ctx, ctx->player->vision->img, 0, 0);
	while (++i < 5)
	{
		img_to_window(ctx, tiles->idle[i].img, pos->x, pos->y);
		img_to_window(ctx, tiles->right[i].img, pos->x, pos->y);
		img_to_window(ctx, tiles->left[i].img, pos->x, pos->y);
		img_to_window(ctx, tiles->up[i].img, pos->x, pos->y);
		img_to_window(ctx, tiles->down[i].img, pos->x, pos->y);
	}
}

static void	draw_exit(t_ctx *ctx)
{
	t_tiles	*tiles;
	t_vec2	*exit;

	tiles = ctx->map->tiles;
	exit = ctx->map->exit;
	img_to_window(ctx, tiles->doors[1].img, exit->x * ctx->map->size, exit->y
		* ctx->map->size);
	img_to_window(ctx, tiles->doors[0].img, exit->x * ctx->map->size, exit->y
		* ctx->map->size);
	tiles->doors[1].img->instances[0].enabled = false;
}
