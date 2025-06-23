#include "so_long.h"

bool load_textures(t_ctx *ctx)
{
	t_tiles *tiles;

	tiles = malloc(sizeof(t_tiles));
	if (!tiles)
	{
		err_msg("", ENOMEM);
		return false;
	}
	tiles->txt_empty = mlx_load_png("./textures/empty.png");
	if (!tiles->txt_empty)
	{
		free(tiles);
		err_msg("Failed to load texture", errno);
		return false;		
	}
	tiles->empty = mlx_texture_to_image(ctx->mlx, tiles->txt_empty);
	if (!tiles->empty)
	{
		free(tiles->empty);
		free(tiles);
		err_msg("Failed to turn texture to image", errno);
		return false;		
	}
	tiles->txt_wall = mlx_load_png("./textures/wall.png");
	if (!tiles->txt_wall)
	{
		err_msg("Failed to load texture", errno);
		return false;		
	}
	tiles->wall = mlx_texture_to_image(ctx->mlx, tiles->txt_wall);
	if (!tiles->wall)
	{
		err_msg("Failed to turn texture to image", errno);
		return false;		
	}
	tiles->txt_coin = mlx_load_png("./textures/coin.png");
	if (!tiles->txt_coin)
	{
		err_msg("Failed to load texture", errno);
		return false;		
	}
	tiles->coin = mlx_texture_to_image(ctx->mlx, tiles->txt_coin);
	if (!tiles->coin)
	{
		err_msg("Failed to turn texture to image", errno);
		return false;		
	}
	tiles->txt_player = mlx_load_png("./textures/player.png");
	if (!tiles->txt_player)
	{
		err_msg("Failed to load texture", errno);
		return false;		
	}
	tiles->player = mlx_texture_to_image(ctx->mlx, tiles->txt_player);
	if (!tiles->coin)
	{
		err_msg("Failed to turn texture to image", errno);
		return false;		
	}
	tiles->txt_exit = mlx_load_png("./textures/exit.png");
	if (!tiles->txt_exit)
	{
		err_msg("Failed to load texture", errno);
		return false;		
	}
	tiles->exit = mlx_texture_to_image(ctx->mlx, tiles->txt_exit);
	if (!tiles->exit)
	{
		err_msg("Failed to turn texture to image", errno);
		return false;		
	}
	tiles->txt_exit_door = mlx_load_png("./textures/exit_door.png");
	if (!tiles->txt_exit_door)
	{
		err_msg("Failed to load texture", errno);
		return false;		
	}
	tiles->exit_door = mlx_texture_to_image(ctx->mlx, tiles->txt_exit_door);
	if (!tiles->exit_door)
	{
		err_msg("Failed to turn texture to image", errno);
		return false;		
	}
	ctx->map->tiles = tiles;
	mlx_resize_image(tiles->wall, 64, 64);
	mlx_resize_image(tiles->empty, 64, 64);
	mlx_resize_image(tiles->coin, 64, 64);
	mlx_resize_image(tiles->player, 48, 48);
	mlx_resize_image(tiles->exit, 64, 64);
	mlx_resize_image(tiles->exit_door, 64, 64);
	ft_printf("Loaded textures\n");
	return true;
}
