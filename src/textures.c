/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:49:34 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/12 14:50:06 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_player_textures(t_ctx *ctx, t_tiles *tiles);
static void	init_textures(t_tiles *tiles);

void	load_textures(t_ctx *ctx)
{
	t_tiles	*tiles;

	tiles = malloc(sizeof(t_tiles));
	if (!tiles)
		clean_exit(ctx, NULL, errno);
	ctx->map->tiles = tiles;
	init_textures(tiles);
	load_wall_textures(ctx, tiles);
	load_floor_textures(ctx, tiles);
	load_doors_textures(ctx, tiles);
	load_player_textures(ctx, tiles);
	load_orbs_textures(ctx, tiles);
}

void	init_assets(t_asset *asset, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		asset[i].img = NULL;
		asset[i].txt = NULL;
	}
}

static void	load_player_textures(t_ctx *ctx, t_tiles *tiles)
{
	const char	*src[] = {"./textures/player/idle.png", NULL};
	int			i;

	tiles->p_idle = malloc(sizeof(t_asset) * 1);
	if (!tiles->p_idle)
		clean_exit(ctx, "Failed to load assets", errno);
	i = -1;
	init_assets(tiles->p_idle, 1);
	while (src[++i])
	{
		tiles->p_idle[i].txt = mlx_load_png(src[i]);
		if (!tiles->p_idle[i].txt)
			clean_exit(ctx, "Failed to load assets", errno);
		tiles->p_idle[i].img = mlx_texture_to_image(ctx->mlx,
				tiles->p_idle[i].txt);
		if (!tiles->p_idle[i].img)
			clean_exit(ctx, "Failed to load assets", errno);
		mlx_resize_image(tiles->p_idle[i].img, 48, 48);
	}
}

static void	init_textures(t_tiles *tiles)
{
	tiles->doors = NULL;
	tiles->floors = NULL;
	tiles->orbs = NULL;
	tiles->walls = NULL;
	tiles->p_idle = NULL;
}
