#include <so_long.h>
static void	init_enemy_pos(t_ctx *ctx);

void    initialize_enemy(t_ctx *ctx)
{
    ctx->enemy = malloc(sizeof(t_enemy));
    if (!ctx->enemy)
        clean_exit(ctx, NULL, errno);
    ctx->enemy->vision = malloc(sizeof(t_vision));
    if (!ctx->enemy->vision)
        clean_exit(ctx, NULL, errno);
    ctx->enemy->vision->r = 20;
    ctx->enemy->pos.x = 0;
    ctx->enemy->pos.y = 0;
    ctx->enemy->dir = IDLE;
	ctx->enemy->speed = 3;
    init_enemy_pos(ctx);
    ft_printf("Pos: %d, %d", ctx->enemy->pos.x, ctx->enemy->pos.y);
}

static void	init_enemy_pos(t_ctx *ctx)
{
	char	**grid;
	int		x;
	int		y;

	grid = ctx->map->grid;
	y = -1;
	while (grid[++y])
	{
		x = -1;
		while (grid[y][++x])
		{
			if (grid[y][x] == 'X')
			{
				ctx->enemy->pos.x = x;
				ctx->enemy->pos.y = y;
				return ;
			}
		}
	}
}
