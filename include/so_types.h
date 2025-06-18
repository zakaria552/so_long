#ifndef SO_TYPES_H
#define SO_TYPES_H

#include "MLX42.h"
typedef struct s_vec2
{
	int x;
	int y;
} t_vec2;

typedef struct s_player
{
	t_vec2 *pos;
	int orbs;
} t_player;


typedef struct s_orb
{
	t_vec2 *pos;
	bool free;
} t_orb;

typedef struct s_textures 
{
	mlx_texture_t *empty_tile;
} t_textures;

typedef struct s_tiles
{
	mlx_image_t *empty;	
	mlx_image_t *wall;
	mlx_image_t *coin;
	mlx_image_t *player;
	mlx_texture_t *txt_player;
	mlx_texture_t *txt_coin;
	mlx_texture_t *txt_wall;
	mlx_texture_t *txt_empty;

} t_tiles;

typedef struct s_map
{
	char **grid;
	char **init_grid;
	int size;
	t_tiles *tiles;
	t_vec2 *start;
	t_vec2 *exit;
	t_orb *orbs;
} t_map;

typedef struct s_ctx
{
	mlx_t *mlx;
	t_player *player;
	t_player *enemies;
	t_map *map;

} t_ctx;

#endif