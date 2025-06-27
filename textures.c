#include "so_long.h"

static void load_wall_textures(t_ctx *ctx, t_tiles *tiles);
static void load_floor_textures(t_ctx *ctx, t_tiles *tiles);
static void load_doors_textures(t_ctx *ctx, t_tiles *tiles);
static void load_player_textures(t_ctx *ctx, t_tiles *tiles);

bool load_textures(t_ctx *ctx)
{
	t_tiles *tiles;

	tiles = malloc(sizeof(t_tiles));
	if (!tiles)
	{
		err_msg("", ENOMEM);
		return false;
	}
	ctx->map->tiles = tiles;
	load_wall_textures(ctx, tiles);
	load_floor_textures(ctx, tiles);
	load_doors_textures(ctx, tiles);
	load_player_textures(ctx, tiles);
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
	mlx_resize_image(tiles->coin, 64, 64);
	ft_printf("Loaded textures\n");
	return true;
}

static void load_wall_textures(t_ctx *ctx, t_tiles *tiles)
{
	const char *src[] = {"./textures/map/wall.png", "textures/map/wall_shadow.png", NULL};
	int i;

	tiles->walls = malloc(sizeof(t_asset) * 2);
	if (!tiles->walls)
		clean_exit(ctx, "Failed to load assets", errno);
	i = -1;
	while (src[++i])
	{
		tiles->walls[i].txt = mlx_load_png(src[i]);
		if (!tiles->walls[i].txt)
			clean_exit(ctx, "Failed to load assets", errno);
		tiles->walls[i].img = mlx_texture_to_image(ctx->mlx, tiles->walls[i].txt);
		if (!tiles->walls[i].img)
			clean_exit(ctx, "Failed to load assets", errno);
		mlx_resize_image(tiles->walls[i].img, 64, 64);
	}
}

static void load_floor_textures(t_ctx *ctx, t_tiles *tiles)
{
	const char *src[] = {"./textures/map/tile1.png", "textures/map/tile2.png", 
		"textures/map/tile3.png", "textures/map/tile4.png", NULL};

	int i;

	tiles->floors = malloc(sizeof(t_asset) * 4);
	if (!tiles->floors)
		clean_exit(ctx, "Failed to load assets", errno);
	i = -1;
	while (src[++i])
	{
		tiles->floors[i].txt = mlx_load_png(src[i]);
		if (!tiles->floors[i].txt)
			clean_exit(ctx, "Failed to load assets", errno);
		tiles->floors[i].img = mlx_texture_to_image(ctx->mlx, tiles->floors[i].txt);
		if (!tiles->floors[i].img)
			clean_exit(ctx, "Failed to load assets", errno);
		mlx_resize_image(tiles->floors[i].img, 64, 64);
	}
}
static void load_doors_textures(t_ctx *ctx, t_tiles *tiles)
{
	const char *src[] = {"./textures/map/closed.png", "textures/map/open.png", NULL};

	int i;

	tiles->doors = malloc(sizeof(t_asset) * 2);
	if (!tiles->doors)
		clean_exit(ctx, "Failed to load assets", errno);
	i = -1;
	while (src[++i])
	{
		tiles->doors[i].txt = mlx_load_png(src[i]);
		if (!tiles->doors[i].txt)
			clean_exit(ctx, "Failed to load assets", errno);
		tiles->doors[i].img = mlx_texture_to_image(ctx->mlx, tiles->doors[i].txt);
		if (!tiles->doors[i].img)
			clean_exit(ctx, "Failed to load assets", errno);
		mlx_resize_image(tiles->doors[i].img, 64, 64);
	}
}
static void load_player_textures(t_ctx *ctx, t_tiles *tiles)
{
	const char *src[] = {"./textures/player/idle.png", NULL};

	int i;

	tiles->p_idle = malloc(sizeof(t_asset) * 1);
	if (!tiles->p_idle)
		clean_exit(ctx, "Failed to load assets", errno);
	ft_printf("Reached here");
	i = -1;
	while (src[++i])
	{
		tiles->p_idle[i].txt = mlx_load_png(src[i]);
		if (!tiles->p_idle[i].txt)
			clean_exit(ctx, "Failed to load assets", errno);
		tiles->p_idle[i].img = mlx_texture_to_image(ctx->mlx, tiles->p_idle[i].txt);
		if (!tiles->p_idle[i].img)
			clean_exit(ctx, "Failed to load assets", errno);
		mlx_resize_image(tiles->p_idle[i].img, 48, 48);
	}

}
