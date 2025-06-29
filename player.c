#include "so_long.h"

static void init_player_pos(t_ctx *ctx);
static void set_pixel(const mlx_image_t *img, uint32_t x, uint32_t y, uint32_t color);
static uint32_t obaque_by_d(int d, int r);

void initialize_player(t_ctx *ctx)
{
	ctx->player = malloc(sizeof(t_player));
	if (!ctx->player)
		clean_exit(ctx, NULL, errno);
	ctx->player->pos = malloc(sizeof(t_vec2));	
	if (!ctx->player->pos)
		clean_exit(ctx, NULL, errno);
	ctx->player->vision = malloc(sizeof(t_vision));
	if(!ctx->player->vision)
		clean_exit(ctx, NULL, errno);
	ctx->player->orbs = 0;
	ctx->player->speed = 8;
	ctx->player->vision->r = 150;
	init_player_pos(ctx);
}

void	update_vision(t_ctx *ctx)
{
	const t_vec2 *pos = ctx->player->pos;
	const mlx_image_t *img = ctx->player->vision->img;
	const int r = ctx->player->vision->r;
	int x;
	int y;
	int d;

	y = 0;
	x = 0;
	while (y++ < img->height)
	{
		x = -1;
		while (++x < img->width)
		{
			d = (x - (int)(pos->x + 24)) * (x - (int)(pos->x + 24)) +
			(y - (int)(pos->y + 24)) * (y - (int)(pos->y + 24));
			set_pixel(img, x, y, obaque_by_d(d, r * r));
		}
	}
}

static void init_player_pos(t_ctx *ctx)
{
	char **grid;
	int x;
	int y;

	grid = ctx->map->grid;
	y = -1;
	while (grid[++y])
	{
		x = -1;
		while (grid[y][++x])
		{
			if (grid[y][x] == 'P')
			{
				ctx->player->pos->x = x;
				ctx->player->pos->y = y;
				return ;
			}
		}
	}
}

static void set_pixel(const mlx_image_t *img, uint32_t x, uint32_t y, uint32_t color)
{
    const uint32_t index = (y * img->width + x) * 4;

    if (x >= img->width || y >= img->height)
        return;
    img->pixels[index + 0] = (color >> 24) & 0xFF;
    img->pixels[index + 1] = (color >> 16) & 0xFF;
    img->pixels[index + 2] = (color >> 8)  & 0xFF;
    img->pixels[index + 3] = (color >> 0)  & 0xFF;
}

static uint32_t obaque_by_d(int d, int r)
{
	uint32_t c;
	float a;

	c = 0x000000ff;
	a = (float) d / r;
	a *= 0xff;
	if (d < r)
		c = 0x00000000 | (int) a;
	return c;
}
