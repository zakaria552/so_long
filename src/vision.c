/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vision.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:55:51 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/12 15:15:40 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void		set_pixel(t_ctx *ctx, uint32_t x, uint32_t y);
static uint32_t	obaque_by_d(int d, int r);
static void		set_optimized_pixel_range(int xr[2], int yr[2], t_ctx *ctx);

void	update_vision(t_ctx *ctx)
{
	int	xr[2];
	int	yr[2];
	int	xtmp;

	set_optimized_pixel_range(xr, yr, ctx);
	xtmp = xr[0];
	while (yr[0]++ < yr[1])
	{
		xr[0] = xtmp;
		while (xr[0]++ < xr[1])
		{
			set_pixel(ctx, xr[0], yr[0]);
		}
	}
}

void	init_vision(t_ctx *ctx)
{
	const mlx_image_t			*img = ctx->player->vision->img;
	uint32_t					x;
	uint32_t					y;

	y = 0;
	x = 0;
	while (y++ < img->height)
	{
		x = 0;
		while (x++ < img->width)
			set_pixel(ctx, x, y);
	}
}

static void	set_pixel(t_ctx *ctx, uint32_t x, uint32_t y)
{
	const t_vec2		*pos = ctx->player->pos;
	const mlx_image_t	*img = ctx->player->vision->img;
	uint32_t			color;
	int					d;
	const uint32_t		index = (y * img->width + x) * 4;

	d = (x - (int)(pos->x + 24)) * (x - (int)(pos->x + 24)) + (y - (int)(pos->y
				+ 24)) * (y - (int)(pos->y + 24));
	color = obaque_by_d(d, ctx->player->vision->r * ctx->player->vision->r);
	if (x >= img->width || y >= img->height)
		return ;
	img->pixels[index + 0] = (color >> 24) & 0xFF;
	img->pixels[index + 1] = (color >> 16) & 0xFF;
	img->pixels[index + 2] = (color >> 8) & 0xFF;
	img->pixels[index + 3] = (color >> 0) & 0xFF;
}

static uint32_t	obaque_by_d(int d, int r)
{
	uint32_t	c;
	float		a;

	c = 0x000000ff;
	a = (float)d / r;
	a *= 0xff;
	if (d < r)
		c = 0x00000000 | (int)a;
	return (c);
}

static void	set_optimized_pixel_range(int xr[2], int yr[2], t_ctx *ctx)
{
	const mlx_image_t	*img = ctx->player->vision->img;

	yr[0] = 0;
	xr[0] = 0;
	yr[1] = img->height;
	xr[1] = img->width;
}
