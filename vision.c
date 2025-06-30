#include "so_long.h"

static void set_pixel(const mlx_image_t *img, uint32_t x, uint32_t y, uint32_t color);
static uint32_t obaque_by_d(int d, int r);
static void set_optimized_pixel_range(int xr[2], int yr[2], t_ctx *ctx, int r);

void	update_vision(t_ctx *ctx)
{
	const t_vec2 *pos = ctx->player->pos;
	const mlx_image_t *img = ctx->player->vision->img;
	const int r = ctx->player->vision->r;
	const int rr = r*r;
	int xr[2];
	int yr[2];
	int xtmp;
	int d;

	set_optimized_pixel_range(xr, yr, ctx, r);
	xtmp = xr[0];
	while (yr[0]++ < yr[1])
	{
		xr[0] = xtmp;
		while (xr[0]++ < xr[1])
		{
			d = (xr[0] - (int)(pos->x + 24)) * (xr[0] - (int)(pos->x + 24)) +
			(yr[0] - (int)(pos->y + 24)) * (yr[0] - (int)(pos->y + 24));
			set_pixel(img, xr[0], yr[0], obaque_by_d(d, rr));
		}
	}
}

void	init_vision(t_ctx *ctx)
{
	const mlx_image_t *img = ctx->player->vision->img;
	int x;
	int y;
	
	y = 0;
	x = 0;
	while (y++ < img->height)
	{
		x = 0;
		while (x++ < img->width)
			set_pixel(img, x, y, 0x000000ff);
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

static void set_optimized_pixel_range(int xr[2], int yr[2], t_ctx *ctx, int r)
{
	const mlx_image_t *img = ctx->player->vision->img;
	const t_vec2 *pos = ctx->player->pos;

	yr[0] = 0;
	xr[0] = 0;
	yr[1] = img->height;
	xr[1] = img->width;
	return;
	//if (pos->y - r > 0)
		//yr[0] = pos->y - r;
	//if (pos->y + r < yr[1])
		//yr[1] = pos->y + r;
	//if (pos->x - r > 0)	
		//xr[0] = pos->x - r;
	//if (pos->x + r < xr[1])
		//xr[1] = pos->x + r;
}
