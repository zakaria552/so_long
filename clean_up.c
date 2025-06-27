#include "so_long.h"

static void free_player(t_player *player);

void clean_up(t_ctx *ctx)
{
	if (!ctx)
		return;
	free_map(ctx->map, ctx->mlx);
	free_player(ctx->player);
	if (ctx->mlx)
		mlx_terminate(ctx->mlx);
	if(ctx->state)
		free(ctx->state);
	free(ctx);
}

void free_player(t_player *player)
{
	if (player)
	{
		if (player->pos)
			free(player->pos);
		free(player);
	}
}
void free_map(t_map *map, mlx_t *mlx)
{
	if (!map)
		return ;
	if (map->grid)
		free_matrix_mem(map->grid);
	if (mlx)
		free_tiles(mlx, map->tiles);
	if (map->exit)
		free(map->exit);
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

void	free_tiles(mlx_t *mlx, t_tiles *tiles)
{
	if (!tiles)
		return;
	
	free(tiles);
}
