/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:34:14 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/09 17:16:04 zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_TYPES_H
# define SO_TYPES_H

# include "MLX42.h"
#include "libft.h"

typedef struct s_vec2
{
	int				x;
	int				y;
}					t_vec2;

typedef struct s_vision
{
	mlx_image_t		*img;
	int				r;
}					t_vision;

typedef enum e_dir
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	IDLE,
} t_dir;

typedef struct s_animation_info
{
	int frame_index;
	double	lt;
	int frame;
}	t_animation_info;

typedef struct s_asset
{
	mlx_texture_t	*txt;
	mlx_image_t		*img;
}					t_asset;

typedef struct s_enemy
{
	t_vec2		pos;
	bool		moving;
	t_dir		dir;
	t_vision	*vision;
	int			speed;
	t_asset		*idle;
	t_asset		*left;
	t_asset		*right;
	t_asset		*up;
	t_asset		*down;
	t_list		*path;
	t_animation_info ani_info;
	t_asset 	*sprites[5];
} t_enemy;

typedef struct s_player
{
	t_vec2			*pos;
	int				orbs;
	int				speed;
	t_dir			prev_dir;
	t_dir			dir;
	bool			idle;
	t_vision		*vision;
	t_animation_info *ani_info;
	t_asset 	*sprites[5];
}					t_player;

typedef struct s_orb
{
	t_vec2			*pos;
	bool			free;
}					t_orb;

typedef struct s_textures
{
	mlx_texture_t	*empty_tile;
}					t_textures;


typedef struct s_tiles
{
	t_asset			*walls;
	t_asset			*floors;
	t_asset			*doors;
	t_asset			*p_idle;
	t_asset			*orbs;
	t_asset			*idle;
	t_asset			*right;
	t_asset			*left;
	t_asset			*up;
	t_asset			*down;
}					t_tiles;

typedef struct s_map
{
	char			**grid;
	char			**init_grid;
	int				width;
	int				height;
	int				bounds[2];
	int				size;
	t_tiles			*tiles;
	t_vec2			*start;
	t_vec2			*exit;
	t_orb			*orbs;
}					t_map;

typedef struct s_game_state
{
	int				total_orbs;
	int				collected;
	bool			ready_to_exit;
	bool			exited;
}					t_game_state;

typedef struct s_ctx
{
	mlx_t			*mlx;
	t_player		*player;
	t_enemy			*enemy;
	t_map			*map;
	t_game_state	*state;
}					t_ctx;

#endif