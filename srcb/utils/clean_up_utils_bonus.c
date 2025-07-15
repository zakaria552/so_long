/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:59:58 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/15 23:09:48 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_player(t_ctx *ctx, t_player *player)
{
	if (!player)
		return ;
	if (player->pos)
		free(player->pos);
	if (player->vision)
	{
		if (player->vision->img)
			mlx_delete_image(ctx->mlx, player->vision->img);
		free(player->vision);
	}
	if (player->ani_info)
		free(player->ani_info);
	free(player);
}

bool	free_map(t_map *map, mlx_t *mlx)
{
	if (!map)
		return (true);
	if (map->grid)
		free_matrix_mem(map->grid);
	if (map->exit)
		free(map->exit);
	if (mlx && map->tiles)
		free_tiles(mlx, map->tiles);
	free(map);
	return (true);
}

void	*free_matrix_mem(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	return (NULL);
}

void	free_assets(mlx_t *mlx, t_asset *asset, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (asset[i].img)
			mlx_delete_image(mlx, asset[i].img);
		if (asset[i].txt)
			mlx_delete_texture(asset[i].txt);
	}
	free(asset);
}

void	free_tiles(mlx_t *mlx, t_tiles *tiles)
{
	if (!tiles)
		return ;
	if (tiles->doors)
		free_assets(mlx, tiles->doors, 2);
	if (tiles->floors)
		free_assets(mlx, tiles->floors, 4);
	if (tiles->walls)
		free_assets(mlx, tiles->walls, 2);
	if (tiles->idle)
		free_assets(mlx, tiles->idle, 5);
	if (tiles->left)
		free_assets(mlx, tiles->left, 5);
	if (tiles->right)
		free_assets(mlx, tiles->right, 5);
	if (tiles->up)
		free_assets(mlx, tiles->up, 5);
	if (tiles->down)
		free_assets(mlx, tiles->down, 5);
	if (tiles->orbs)
		free_assets(mlx, tiles->orbs, 1);
	free(tiles);
}
