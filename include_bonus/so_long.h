/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:33:42 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/12 22:21:32 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// #include <mlx.h>
# include "MLX42.h"
# include "libft.h"
# include "math.h"
# include "so_types.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

// parser
t_map	*parse_map(char *name);

// ctx init
t_ctx	*ctx_init(char *map_name);

// map validator/utils
bool	validate_map(char *fname, char *map);
bool	valid_char_set(char **map);
bool	is_rectangular(char **map);
bool	has_extension(char *name, char *ext);
bool	is_enclosed(char **map);

// errors
void	err_msg(char *msg, int errnum);
void	clean_exit(t_ctx *ctx, char *msg, int err_code);

// io_utils
char	*read_from_file(char *name);

// textures
void	load_textures(t_ctx *ctx);
void	init_assets(t_asset *asset, int size);

// map textures
void	load_wall_textures(t_ctx *ctx, t_tiles *tiles);
void	load_floor_textures(t_ctx *ctx, t_tiles *tiles);
void	load_doors_textures(t_ctx *ctx, t_tiles *tiles);
void	load_orbs_textures(t_ctx *ctx, t_tiles *tiles);

// player textures
void	load_player_textures(t_ctx *ctx, t_tiles *tiles);
void	load_right(t_ctx *ctx, t_tiles *tiles);
void	load_idle(t_ctx *ctx, t_tiles *tiles);
void	load_right(t_ctx *ctx, t_tiles *tiles);
void	load_left(t_ctx *ctx, t_tiles *tiles);
void	load_up(t_ctx *ctx, t_tiles *tiles);
void	load_down(t_ctx *ctx, t_tiles *tiles);

// enemy textures
void	load_enemy_textures(t_ctx *ctx);
void	load_enemy_idle(t_ctx *ctx);
void	load_enemy_right(t_ctx *ctx);
void	load_enemy_left(t_ctx *ctx);
void	load_enemy_up(t_ctx *ctx);
void	load_enemy_down(t_ctx *ctx);

// draw
void	draw_map(t_ctx *ctx);
void	draw_enemy(t_ctx *ctx);
void    draw_ui(t_ctx *ctx);

// player
void	move_hook(t_ctx *ctx);
void	initialize_player(t_ctx *ctx);

// hooks
void	hooks(t_ctx *ctx);
void	key_hooks(mlx_key_data_t keydata, t_ctx *ctx);

// vision
void	update_vision(t_ctx *ctx);
void	init_vision(t_ctx *ctx);

// collision
bool	check_collision(t_ctx *ctx, char c, const int off[2][2], t_vec2 *pos);
t_vec2	get_collided_tile(t_map *map, t_vec2 *pos, char c);
bool	player_collision(t_vec2 *pos, t_vec2 *pos2, const int off[2][2]);

// collect
void	collect(t_ctx *ctx);

// clean/utils
void	clean_up(t_ctx *ctx);
bool	free_map(t_map *map, mlx_t *mlx);
void	*free_matrix_mem(char **matrix);
void	free_tiles(mlx_t *mlx, t_tiles *tiles);
void	free_player(t_ctx *ctx, t_player *player);
void	free_assets(mlx_t *mlx, t_asset *asset, int size);

// valid path
bool	valid_path_exists(t_ctx *ctx);

// valid path utils
bool	is_valid_adj(t_vec2 *adj, int bounds[2], int **visited);
int		**initialize_visited(int w, int h);
void	free_visited(int **visited, int h);

// path finder
t_list	*dfs_target(t_ctx *ctx, t_vec2 start, t_vec2 target);

// safe mlx funcs
void	img_to_window(t_ctx *ctx, mlx_image_t *img, int32_t x, int32_t y);
mlx_image_t *new_img(t_ctx *ctx, uint32_t w, uint32_t h);

// animate
void	animate_player(t_ctx *ctx);
void	animate_enemy(t_ctx *ctx);

// enemy
void    initialize_enemy(t_ctx *ctx);

// random
int random_num(int lower, int upper);

// patrol
void	patrol(t_ctx *ctx);

// patrol path
void    set_path_to_patrol(t_ctx *ctx);

// move enemy
void	move_enemy_hook(t_ctx *ctx);

#endif
