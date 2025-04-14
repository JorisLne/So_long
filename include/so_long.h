/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine <jlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:01:54 by jlaine            #+#    #+#             */
/*   Updated: 2024/08/16 17:28:26 by jlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// Libs
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# include "../mlx/mlx.h"
# include "../libft/libft.h"

// Macros
# define SIZE 32

# define WALL '1'
# define EXIT 'E'
# define FLOOR '0'
# define PLAYER 'P'
# define ITEM 'C'

# define A 97
# define W 119
# define S 115
# define D 100
# define UP 65362
# define ESC 65307
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363

// Structs
typedef struct s_sprites
{
	void	*exit;
	void	*wall;
	void	*floor;
	void	*player;
	void	*item;
}	t_sprites;

typedef struct s_mlx
{
	void	*ptr;
	void	*image;
	void	*window;	
}	t_mlx;

typedef struct s_map
{
	int		x;
	int		y;
	int		e;
	int		exit;
	int		lines;
	int		moves;
	int		players;
	int		columns;
	int		total_items;
	char	**map_array;
	int		player_x_pos;
	int		player_y_pos;
	int		collected_items;
}	t_map;

typedef struct s_root
{
	t_map		map;
	t_mlx		mlx;
	t_sprites	sprites;
}	t_root;

// utils
void	destroy(t_root *root);
void	free_array(char **array);
int		ft_error(t_root *root, char *str);
int		close_game(t_root *root);

// init
void	map_init(t_map *map);
void	init_window(t_root *root);
void	load_sprites(t_root *root);

// checks
int		is_path_valid(t_root *root, t_map *map);
int		extension_check(t_root *root, char *str);
void	is_walls_valid(t_root *root, t_map *map);
int		is_map_valid(t_root *root, char *str, t_map *map);
int		prep_map_values(t_root *root, char *str, t_map *map);

// game
int		game(t_root *root);
void	draw_map(t_root *root);
int		key_pressed(int key, t_root *root);
int		next_tile(t_root *root, int x, int y);
void	update_player_pos(t_root *root, int x, int y);
void	put_image_to_window(t_root *root, int column, int line);

#endif
