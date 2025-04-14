/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine <jlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:43:15 by jlaine            #+#    #+#             */
/*   Updated: 2024/08/19 11:55:24 by jlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_init(t_map *map)
{
	map->e = 0;
	map->exit = 0;
	map->moves = 0;
	map->players = 0;
	map->total_items = 0;
	map->collected_items = 0;
}

void	init_window(t_root *root)
{
	root->mlx.ptr = mlx_init();
	if (!root->mlx.ptr)
		ft_error(root, "MLX initialization failed");
	root->mlx.window = mlx_new_window(root->mlx.ptr,
			root->map.columns * SIZE, root->map.lines * SIZE, "so_long");
	if (!root->mlx.window)
		ft_error(root, "Window creation failed");
}

void	load_sprites(t_root *root)
{
	int	x;
	int	y;

	root->sprites.floor = mlx_xpm_file_to_image(root->mlx.ptr, \
		"./assets/floor.xpm", &x, &y);
	root->sprites.player = mlx_xpm_file_to_image(root->mlx.ptr, \
		"./assets/player.xpm", &x, &y);
	root->sprites.wall = mlx_xpm_file_to_image(root->mlx.ptr, \
		"./assets/wall.xpm", &x, &y);
	root->sprites.item = mlx_xpm_file_to_image(root->mlx.ptr, \
		"./assets/item.xpm", &x, &y);
	root->sprites.exit = mlx_xpm_file_to_image(root->mlx.ptr, \
		"./assets/exit.xpm", &x, &y);
	if (!root->sprites.floor || !root->sprites.player || !root->sprites.wall
		|| !root->sprites.item || !root->sprites.exit)
		ft_error(root, "Failed to load sprites");
}
