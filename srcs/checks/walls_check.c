/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine <jlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:28:57 by jlaine            #+#    #+#             */
/*   Updated: 2024/08/08 18:37:30 by jlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_top_wall(t_root *root, t_map *map)
{
	map->x = 0;
	while (map->map_array[0][map->x])
	{
		if (map->map_array[0][map->x] != '1')
			ft_error(root, "Top wall is invalid.");
		map->x++;
	}
}

static void	check_bottom_wall(t_root *root, t_map *map)
{
	map->x = 0;
	while (map->map_array[map->lines - 1][map->x])
	{
		if (map->map_array[map->lines - 1][map->x] != '1')
			ft_error(root, "Bottom wall is invalid.");
		map->x++;
	}
}

static void	check_side_walls(t_root *root, t_map *map)
{
	map->y = 0;
	while (map->y < map->lines)
	{
		if (map->map_array[map->y][0] != '1'
			|| map->map_array[map->y][map->columns - 1] != '1')
			ft_error(root, "Side walls are invalid.");
		map->y++;
	}
}

void	is_walls_valid(t_root *root, t_map *map)
{
	check_top_wall(root, map);
	check_bottom_wall(root, map);
	check_side_walls(root, map);
}
