/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine <jlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:55:19 by jlaine            #+#    #+#             */
/*   Updated: 2024/08/14 17:36:52 by jlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_player_pos(t_root *root, int x, int y)
{
	if (root->map.map_array[y][x] == ITEM)
	{
		root->map.map_array[y][x] = '0';
		root->map.collected_items++;
	}
	if (root->map.map_array[root->map.y][root->map.x] == EXIT)
	{
		mlx_put_image_to_window(root->mlx.ptr, \
			root->mlx.window, root->sprites.player, x * SIZE, y * SIZE);
		mlx_put_image_to_window(root->mlx.ptr, \
			root->mlx.window, root->sprites.exit, \
				root->map.x * SIZE, root->map.y * SIZE);
		root->map.moves++;
		return ;
	}
	mlx_put_image_to_window(root->mlx.ptr, \
		root->mlx.window, root->sprites.player, x * SIZE, y * SIZE);
	mlx_put_image_to_window(root->mlx.ptr, \
		root->mlx.window, root->sprites.floor, \
			root->map.x * SIZE, root->map.y * SIZE);
	root->map.moves++;
}

int	next_tile(t_root *root, int x, int y)
{
	char	tile;

	tile = root->map.map_array[y][x];
	if (tile == WALL)
		return (0);
	else if (tile == EXIT)
	{
		if (root->map.collected_items == root->map.total_items)
		{
			update_player_pos(root, x, y);
			ft_printf("Moves: %d\n", root->map.moves);
			ft_printf("YOU WON\n");
			destroy(root);
			return (0);
		}
	}
	update_player_pos(root, x, y);
	ft_printf("Moves: %d\n", root->map.moves);
	root->map.x = x;
	root->map.y = y;
	return (0);
}

int	key_pressed(int key, t_root *root)
{
	if (key == UP || key == W)
		next_tile(root, root->map.x, root->map.y - 1);
	else if (key == DOWN || key == S)
		next_tile(root, root->map.x, root->map.y + 1);
	else if (key == LEFT || key == A)
		next_tile(root, root->map.x - 1, root->map.y);
	else if (key == RIGHT || key == D)
		next_tile(root, root->map.x + 1, root->map.y);
	else if (key == ESC)
		close_game(root);
	return (0);
}
