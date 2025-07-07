#include "so_long.h"

void    set_path_to_patrol(t_ctx *ctx)
{
    t_vec2 target;
    t_vec2 start;
    
    start.x = ctx->enemy->pos.x / ctx->map->size;
    start.y = ctx->enemy->pos.y / ctx->map->size;
    while(true)
    {
        target.x = random_num(1, ctx->map->bounds[0] - 2);
        target.y = random_num(1, ctx->map->bounds[1] - 2);
        ft_printf("(%d, %d)-%c\n", target.x, target.y, ctx->map->grid[target.y][target.x]);
        if (ctx->map->grid[target.y][target.x] != '0')
            continue;
        ft_printf("start: (%d, %d), end: (%d, %d)", start.x, start.y, target.x, target.y);
        ctx->enemy->path = dfs_target(ctx->map, ctx->map->bounds, start, target);
        if (!ctx->enemy->path)
            continue;
        show_path(ctx->enemy->path);
        break;
    }
}