#ifndef SO_LONG_H
#define SO_LONG_H

// #include <mlx.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include "libft.h"
#include "so_types.h"
#include "MLX42.h"
#include "math.h"

// parser
t_map *parse_map(char *name);

// ctx init
t_ctx *ctx_init(char *map_name);
void init_game_state(t_ctx *ctx);

// map validator
bool validate_map(char *fname, char *map);

// errors
void exit_with_err(int code);
void err_msg(char *msg, int errnum);
void clean_exit(t_ctx *ctx, char *msg, int err_code);

// io_utils
char *read_from_file(char *name);
char *read_from_file2(char *name);

// textures
void load_textures(t_ctx *ctx);

// draw
void	draw_map(t_ctx *ctx);

// player
void	initialize_player(t_ctx *ctx);
void handle_player_movement(mlx_key_data_t keydata, t_ctx *ctx);
void	update_vision(t_ctx *ctx);

// collision
bool check_collision(t_ctx *ctx, char c);
t_vec2 get_collided_tile(t_map *map, t_vec2 *pos, char c);

// collect
void collect(t_ctx *ctx);

// clean
void clean_up(t_ctx *ctx);
void free_map(t_map *map, mlx_t *mlx);
void	*free_matrix_mem(char **matrix);
void	free_tiles(mlx_t *mlx, t_tiles *tiles);

// valid path
t_list *dfs_target(t_map *map, int bounds[2], t_vec2 start, t_vec2 target);
bool valid_path_exists(t_map *map, t_player *player);

// valid path utils
void print_visit(int **visited, int w, int h);
bool is_valid_adj(t_list **q, t_vec2 *adj, int bounds[2], int **visited);
int **initialize_visited(int w, int h);
void show_path(t_list *p);
void **free_visited(int **visited, int w, int h);


#endif
