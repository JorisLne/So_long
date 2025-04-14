/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine <jlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:00:51 by jlaine            #+#    #+#             */
/*   Updated: 2024/08/19 12:08:28 by jlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	destroy(t_root *root)
{
	if (root->map.map_array)
		free_array(root->map.map_array);
	if (root->sprites.item)
		mlx_destroy_image(root->mlx.ptr, root->sprites.item);
	if (root->sprites.wall)
		mlx_destroy_image(root->mlx.ptr, root->sprites.wall);
	if (root->sprites.player)
		mlx_destroy_image(root->mlx.ptr, root->sprites.player);
	if (root->sprites.exit)
		mlx_destroy_image(root->mlx.ptr, root->sprites.exit);
	if (root->sprites.floor)
		mlx_destroy_image(root->mlx.ptr, root->sprites.floor);
	if (root->mlx.window)
		mlx_destroy_window(root->mlx.ptr, root->mlx.window);
	if (root->mlx.ptr)
		mlx_destroy_display(root->mlx.ptr);
	if (root->mlx.ptr)
		free(root->mlx.ptr);
	exit(0);
}

int	close_game(t_root *root)
{
	ft_printf("GAME OVER\n");
	destroy(root);
	return (0);
}
