/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine <jlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:55:09 by jlaine            #+#    #+#             */
/*   Updated: 2024/08/19 12:19:59 by jlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image_to_window(t_root *root, int column, int line)
{
	char	tile;
	void	*img;

	tile = root->map.map_array[root->map.y][root->map.x];
	if (tile == WALL)
		img = root->sprites.wall;
	else if (tile == FLOOR)
		img = root->sprites.floor;
	else if (tile == PLAYER)
		img = root->sprites.player;
	else if (tile == ITEM)
		img = root->sprites.item;
	else if (tile == EXIT)
		img = root->sprites.exit;
	else
		return ;
	if (!mlx_put_image_to_window(root->mlx.ptr,
			root->mlx.window, img, column, line))
		ft_error(root, "Failed to put image to window");
}

void	draw_map(t_root *root)
{
	int		line;
	int		column;

	line = 0;
	root->map.y = 0;
	while (root->map.map_array[root->map.y])
	{
		column = 0;
		root->map.x = 0;
		while (root->map.map_array[root->map.y][root->map.x])
		{
			put_image_to_window(root, column, line);
			root->map.x++;
			column += SIZE;
		}
		root->map.y++;
		line += SIZE;
	}
	root->map.x = root->map.player_x_pos;
	root->map.y = root->map.player_y_pos;
}

int	game(t_root *root)
{
	draw_map(root);
	if (!mlx_hook(root->mlx.window, 2, (1L << 0), key_pressed, root))
		ft_error(root, "Failed to set keypress hook");
	if (!mlx_hook(root->mlx.window, 17, (1L << 2), close_game, root))
		ft_error(root, "Failed to set window close hook");
	mlx_loop(root->mlx.ptr);
	return (0);
}
