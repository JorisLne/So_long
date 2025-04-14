/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine <jlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:04:08 by jlaine            #+#    #+#             */
/*   Updated: 2024/08/19 11:28:41 by jlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_rectangle_valid(t_root *root, t_map *map)
{
	int	i;
	int	a;
	int	len;

	if (!map->map_array || !map->map_array[0])
		ft_error(root, "Invalid map data");
	i = 0;
	len = ft_strlen(map->map_array[0]);
	while (map->map_array[i])
	{
		a = ft_strlen(map->map_array[i]);
		if (a != len)
			ft_error(root, "Map lines don't have the same size");
		i++;
	}
	if (map->lines == map->columns)
		ft_error(root, "Map need's to be a rectangle.");
	return (0);
}

static int	is_values_valid(t_root *root, t_map *map)
{
	if (map->total_items == 0)
		ft_error(root, "No items in this map.");
	if (map->exit < 1)
		ft_error(root, "The map doesn't have an exit.");
	if (map->players < 1)
		ft_error(root, "The map doesn't have a player.");
	if (map->exit > 1)
		ft_error(root, "The map has more than one exit.");
	if (map->players > 1)
		ft_error(root, "The map has more than one player.");
	return (0);
}

static int	is_chars_valid(t_root *root, t_map *map)
{
	map->y = 0;
	while (map->map_array[map->y])
	{
		map->x = 0;
		while (map->map_array[map->y][map->x])
		{
			if (map->map_array[map->y][map->x] != '0'
					&& map->map_array[map->y][map->x] != '1'
					&& map->map_array[map->y][map->x] != 'P'
					&& map->map_array[map->y][map->x] != 'C'
					&& map->map_array[map->y][map->x] != 'E')
				ft_error(root, "The map contains wrong characters.");
			map->x++;
		}
		map->y++;
	}
	return (0);
}

int	is_map_valid(t_root *root, char *str, t_map *map)
{
	prep_map_values(root, str, map);
	is_rectangle_valid(root, map);
	is_values_valid(root, map);
	is_walls_valid(root, map);
	is_chars_valid(root, map);
	is_path_valid(root, map);
	return (0);
}
