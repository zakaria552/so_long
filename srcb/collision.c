/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:04:26 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/01 14:39:22 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_vals(t_vec2 *tile, int *x, int *y);

bool	check_collision(t_ctx *ctx, char c, const int off[2][2])
{
	char	**grid;
	t_vec2	*pos;
	int		s;
	int		x;
	int		y;

	pos = ctx->player->pos;
	s = ctx->map->size;
	grid = ctx->map->grid;
	x = -1;
	y = -1;
	while (grid[++y])
	{
		x = -1;
		while (grid[y][++x])
		{
			if (grid[y][x] != c)
				continue ;
			if ((pos->x + 48 - off[0][0]) > x * s && (pos->x + off[0][1]) < (x
					* s + s) && (pos->y + 48 - off[1][0]) > (y * s) && (pos->y
					+ off[1][1]) < (y * s + s))
				return (true);
		}
	}
	return (false);
}

t_vec2	get_collided_tile(t_map *map, t_vec2 *pos, char c)
{
	t_vec2	tile;
	int		s;
	int		x;
	int		y;

	s = map->size;
	init_vals(&tile, &x, &y);
	while (map->grid[++y])
	{
		x = -1;
		while (map->grid[y][++x])
		{
			if (map->grid[y][x] != c)
				continue ;
			if (pos->x < (x * s + s) && (pos->x + 48) > (x * s) && pos->y < (y
					* s + s) && (pos->y + 48) > (y * s))
			{
				tile.x = x;
				tile.y = y;
				break ;
			}
		}
	}
	return (tile);
}

static void	init_vals(t_vec2 *tile, int *x, int *y)
{
	tile->x = -1;
	tile->y = -1;
	*x = -1;
	*y = -1;
}
