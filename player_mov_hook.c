#include "so_long.h"
static void move_player(t_ctx *ctx, int nx, int ny);

void handle_player_movement(mlx_key_data_t keydata, t_ctx *ctx)
{
	t_vec2 *pos;
	mlx_image_t *img;
	
	img = ctx->map->tiles->player;	
	pos = ctx->player->pos;
	if (keydata.key == MLX_KEY_W && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_player(ctx, pos->x, pos->y - 8);
	if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_player(ctx, pos->x, pos->y + 8);
	if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_player(ctx, pos->x - 8, pos->y);
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_player(ctx, pos->x + 8, pos->y);
}
void move_player(t_ctx *ctx, int nx, int ny)
{
	ctx->player->pos->x = nx;
	ctx->player->pos->y = ny;
	if (check_collision(ctx, '1'))
	{
		ctx->player->pos->x = ctx->map->tiles->player->instances[0].x;
		ctx->player->pos->y = ctx->map->tiles->player->instances[0].y;
		return ;
	}
	ctx->map->tiles->player->instances[0].x = nx;
	ctx->map->tiles->player->instances[0].y = ny;
	return ;
}