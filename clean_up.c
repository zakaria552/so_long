#include "so_long.h"

static void free_player(t_ctx *ctx, t_player *player);

void clean_up(t_ctx *ctx)
{
	if (!ctx)
		return;
	free_map(ctx->map, ctx->mlx);
	free_player(ctx, ctx->player);
	if (ctx->mlx)
		mlx_terminate(ctx->mlx);
	if(ctx->state)
		free(ctx->state);
	free(ctx);
}

void free_player(t_ctx *ctx, t_player *player)
{
	if (!player)
		return;
	if (player->pos)
		free(player->pos);
	if (player->vision)
	{
		if (player->vision->img)
			mlx_delete_image(ctx->mlx, player->vision->img);
		free(player->vision);
	}
	free(player);
}
void free_map(t_map *map, mlx_t *mlx)
{
	if (!map)
		return ;
	if (map->grid)
		free_matrix_mem(map->grid);
	if (map->exit)
		free(map->exit);
	if (mlx && map->tiles)
		free_tiles(mlx, map->tiles);
	free(map);
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

void free_assets(mlx_t *mlx, t_asset *asset, int size)
{
	int i;

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
		return;
	if (tiles->doors)
		free_assets(mlx, tiles->doors, 2);
	if (tiles->floors)
		free_assets(mlx, tiles->floors, 4);
	if (tiles->walls)
		free_assets(mlx, tiles->walls, 2);
	if (tiles->p_idle)
		free_assets(mlx, tiles->p_idle, 1);
	if (tiles->orbs)
		free_assets(mlx, tiles->orbs, 1);
	free(tiles);
}
