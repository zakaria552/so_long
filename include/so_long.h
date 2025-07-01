/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:33:42 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/01 17:33:43 by zfarah           ###   ########.fr       */
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
char	*read_from_file2(char *name);

// textures
void	load_textures(t_ctx *ctx);
void	init_assets(t_asset *asset, int size);

// textures utils
void	load_wall_textures(t_ctx *ctx, t_tiles *tiles);
void	load_floor_textures(t_ctx *ctx, t_tiles *tiles);
void	load_doors_textures(t_ctx *ctx, t_tiles *tiles);
void	load_orbs_textures(t_ctx *ctx, t_tiles *tiles);

// draw
void	draw_map(t_ctx *ctx);

// player
void	move_hook(t_ctx *ctx);
void	initialize_player(t_ctx *ctx);

// vision
void	update_vision(t_ctx *ctx);
void	init_vision(t_ctx *ctx);

// collision
bool	check_collision(t_ctx *ctx, char c, const int off[2][2]);
t_vec2	get_collided_tile(t_map *map, t_vec2 *pos, char c);

// collect
void	collect(t_ctx *ctx);

// clean/utils
void	clean_up(t_ctx *ctx);
void	free_map(t_map *map, mlx_t *mlx);
void	*free_matrix_mem(char **matrix);
void	free_tiles(mlx_t *mlx, t_tiles *tiles);
void	free_player(t_ctx *ctx, t_player *player);
void	free_assets(mlx_t *mlx, t_asset *asset, int size);

// valid path
t_list	*dfs_target(t_map *map, int bounds[2], t_vec2 start, t_vec2 target);
bool	valid_path_exists(t_map *map, t_player *player);

// valid path utils
void	print_visit(int **visited, int w, int h);
bool	is_valid_adj(t_list **q, t_vec2 *adj, int bounds[2], int **visited);
int		**initialize_visited(int w, int h);
void	show_path(t_list *p);
void	free_visited(int **visited, int w, int h);

// path finder
t_list	*dfs_target(t_map *map, int bounds[2], t_vec2 start, t_vec2 target);

#endif
