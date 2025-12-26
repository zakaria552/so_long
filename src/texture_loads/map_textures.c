/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_textures_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 22:11:43 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/15 23:09:48 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_wall_textures(t_ctx *ctx, t_tiles *tiles)
{
	const char	*src[] = {"./textures/map/wall.png",
		"textures/map/wall_shadow.png", NULL};
	int			i;

	tiles->walls = malloc(sizeof(t_asset) * 2);
	if (!tiles->walls)
		clean_exit(ctx, "Failed to load assets", errno);
	i = -1;
	init_assets(tiles->walls, 2);
	while (src[++i])
	{
		tiles->walls[i].txt = mlx_load_png(src[i]);
		if (!tiles->walls[i].txt)
			clean_exit(ctx, "Failed to load assets", errno);
		tiles->walls[i].img = mlx_texture_to_image(ctx->mlx,
				tiles->walls[i].txt);
		if (!tiles->walls[i].img)
			clean_exit(ctx, "Failed to load assets", errno);
		mlx_resize_image(tiles->walls[i].img, ctx->map->size, ctx->map->size);
	}
}

void	load_floor_textures(t_ctx *ctx, t_tiles *tiles)
{
	const char	*src[] = {"./textures/map/tile1.png", "textures/map/tile2.png",
		"textures/map/tile3.png", "textures/map/tile4.png", NULL};
	int			i;

	tiles->floors = malloc(sizeof(t_asset) * 4);
	if (!tiles->floors)
		clean_exit(ctx, "Failed to load assets", errno);
	i = -1;
	init_assets(tiles->floors, 4);
	while (src[++i])
	{
		tiles->floors[i].txt = mlx_load_png(src[i]);
		if (!tiles->floors[i].txt)
			clean_exit(ctx, "Failed to load assets", errno);
		tiles->floors[i].img = mlx_texture_to_image(ctx->mlx,
				tiles->floors[i].txt);
		if (!tiles->floors[i].img)
			clean_exit(ctx, "Failed to load assets", errno);
		mlx_resize_image(tiles->floors[i].img, ctx->map->size, ctx->map->size);
	}
}

void	load_doors_textures(t_ctx *ctx, t_tiles *tiles)
{
	const char	*src[] = {"./textures/map/closed.png", "textures/map/open.png",
		NULL};
	int			i;

	tiles->doors = malloc(sizeof(t_asset) * 2);
	if (!tiles->doors)
		clean_exit(ctx, "Failed to load assets", errno);
	i = -1;
	init_assets(tiles->doors, 2);
	while (src[++i])
	{
		tiles->doors[i].txt = mlx_load_png(src[i]);
		if (!tiles->doors[i].txt)
			clean_exit(ctx, "Failed to load assets", errno);
		tiles->doors[i].img = mlx_texture_to_image(ctx->mlx,
				tiles->doors[i].txt);
		if (!tiles->doors[i].img)
			clean_exit(ctx, "Failed to load assets", errno);
		mlx_resize_image(tiles->doors[i].img, ctx->map->size, ctx->map->size);
	}
}

void	load_orbs_textures(t_ctx *ctx, t_tiles *tiles)
{
	const char	*src[] = {"./textures/coin.png", NULL};
	int			i;

	tiles->orbs = malloc(sizeof(t_asset));
	if (!tiles->orbs)
		clean_exit(ctx, "Failed to load assets", errno);
	i = -1;
	init_assets(tiles->orbs, 1);
	while (src[++i])
	{
		tiles->orbs[i].txt = mlx_load_png(src[i]);
		if (!tiles->orbs[i].txt)
			clean_exit(ctx, "Failed to load assets", errno);
		tiles->orbs[i].img = mlx_texture_to_image(ctx->mlx, tiles->orbs[i].txt);
		if (!tiles->orbs[i].img)
			clean_exit(ctx, "Failed to load assets", errno);
		mlx_resize_image(tiles->orbs[i].img, ctx->map->size, ctx->map->size);
	}
}
