#ifndef SO_LONG_H
#define SO_LONG_H

// #include <mlx.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "so_types.h"
#include "MLX42.h"
// parser
t_map *parse_map(char *name);

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
bool load_textures(t_ctx *ctx);

// draw
void	draw_map(t_ctx *ctx);

// player
bool	initialize_player(t_ctx *ctx);
void	set_pos(t_vec2 *pos, int x, int y);
void handle_player_movement(mlx_key_data_t keydata, t_ctx *ctx);

// collision
bool check_collision(t_ctx *ctx, char c);
t_vec2 get_collided_tile(t_map *map, t_vec2 *pos, char c);

// collect
void collect(t_ctx *ctx);

// clean
void clean_up(t_ctx *ctx);
void free_map(t_map *map, mlx_t *mlx);


bool valid_path(t_map *map, t_vec2 start, t_vec2 end);

#endif
