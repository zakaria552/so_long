#include "so_long.h"
static void move_player(t_ctx *ctx, int nx, int ny);

void handle_player_movement(mlx_key_data_t keydata, t_ctx *ctx)
{
	t_vec2 *pos;
	
	if (ctx->state->exited)
		return;
	//ft_printf("Player moving\n");
	pos = ctx->player->pos;
	if (keydata.key == MLX_KEY_W && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_player(ctx, pos->x, pos->y - 8);
	if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_player(ctx, pos->x, pos->y + 8);
	if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_player(ctx, pos->x - 8, pos->y);
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_player(ctx, pos->x + 8, pos->y);
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(ctx->mlx);
		
}
void move_player(t_ctx *ctx, int nx, int ny)
{
	mlx_image_t *img;

	img = ctx->map->tiles->p_idle->img;	
	ctx->player->pos->x = nx;
	ctx->player->pos->y = ny;
	if (check_collision(ctx, '1'))
	{
		ctx->player->pos->x = img->instances[0].x;
		ctx->player->pos->y = img->instances[0].y;
		return ;
	}
	img->instances[0].x = nx;
	img->instances[0].y = ny;
	return ;
}