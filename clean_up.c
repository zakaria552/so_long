#include "so_long.h"

static void	*free_matrix_mem(char **matrix);
void free_map(t_map *map, mlx_t *mlx);
static void free_player(t_player *player);

void clean_up(t_ctx *ctx)
{
	if (!ctx)
		return;
	free_map(ctx->map, ctx->mlx);
	free_player(ctx->player);
	if (ctx->mlx)
		mlx_terminate(ctx->mlx);
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
	if (mlx && map->tiles)
	{
		if (map->tiles->coin)
			mlx_delete_image(mlx, map->tiles->coin);
		if (map->tiles->empty)
			mlx_delete_image(mlx, map->tiles->empty);
		if (map->tiles->player)
			mlx_delete_image(mlx, map->tiles->player);
		if (map->tiles->wall)
			mlx_delete_image(mlx, map->tiles->wall);
		if (map->tiles->txt_coin)
			mlx_delete_texture(map->tiles->txt_coin);
		if (map->tiles->txt_empty)
			mlx_delete_texture(map->tiles->txt_empty);
		if (map->tiles->txt_player)
			mlx_delete_texture(map->tiles->txt_player);
		if (map->tiles->txt_wall)
			mlx_delete_texture(map->tiles->txt_wall);
		free(map->tiles);
	}
	free(map);
}

static void	*free_matrix_mem(char **matrix)
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