/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_safe_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 18:08:13 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/01 18:58:35 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_to_window(t_ctx *ctx, mlx_image_t *img, int32_t x, int32_t y)
{
	if (mlx_image_to_window(ctx->mlx, img, x, y) < 0)
		clean_exit(ctx, NULL, errno);
}

mlx_image_t	*new_img(t_ctx *ctx, uint32_t w, uint32_t h)
{
	mlx_image_t	*img;

	img = mlx_new_image(ctx->mlx, w, h);
	if (!img)
		clean_exit(ctx, NULL, errno);
	return (img);
}
