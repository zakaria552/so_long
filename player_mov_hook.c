#include "so_long.h"
static void move_player(t_ctx *ctx, int nx, int ny);

void move_hook(t_ctx *ctx)
{
	const t_vec2 *pos = ctx->player->pos;

	if (mlx_is_key_down(ctx->mlx, MLX_KEY_W))
		move_player(ctx, pos->x, pos->y - 8);
	if (mlx_is_key_down(ctx->mlx, MLX_KEY_S))
		move_player(ctx, pos->x, pos->y + 8);
	if (mlx_is_key_down(ctx->mlx, MLX_KEY_A))
		move_player(ctx, pos->x - 8, pos->y);
	if (mlx_is_key_down(ctx->mlx, MLX_KEY_D))
		move_player(ctx, pos->x + 8, pos->y);
}

void move_player(t_ctx *ctx, int nx, int ny)
{
	mlx_image_t *img;
	const offsets[2][2] = {{10, 10}, {0, 36}};

	img = ctx->map->tiles->p_idle->img;	
	ctx->player->pos->x = nx;
	ctx->player->pos->y = ny;
	if (check_collision(ctx, '1', offsets))
	{
		ctx->player->pos->x = img->instances[0].x;
		ctx->player->pos->y = img->instances[0].y;
		return ;
	}
	img->instances[0].x = nx;
	img->instances[0].y = ny;
	return ;
}