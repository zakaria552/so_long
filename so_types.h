#ifndef SO_TYPES_H
#define SO_TYPES_H

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

typedef struct s_mlx_ctx
{
	void *mlx;
	void *window;

} t_mlx_ctx;


typedef struct s_map
{
	char **grid;
	char **init_grid;
	int size;
	t_vec2 *start;
	t_vec2 *exit;
	t_orb *orbs;
} t_map;

typedef struct s_ctx
{
	t_mlx_ctx *mlx;
	t_player *player;
	t_player *enemies;
	t_map *map;

} t_ctx;





#endif