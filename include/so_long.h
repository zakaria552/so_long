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

// io_utils
char *read_from_file(char *name);

// textures
bool load_textures(t_ctx *ctx);

// draw
void	draw_map(t_ctx *ctx);

// player
bool	initialize_player(t_ctx *ctx);
void	set_pod(t_vec2 *pos, int x, int y);
#endif
