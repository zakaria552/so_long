/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:49:34 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/15 18:59:50 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	load_enemy_textures(ctx);
	
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

static void	init_textures(t_tiles *tiles)
{
	tiles->doors = NULL;
	tiles->floors = NULL;
	tiles->orbs = NULL;
	tiles->walls = NULL;
	tiles->p_idle = NULL;
}
