/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine <jlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:47:37 by jlaine            #+#    #+#             */
/*   Updated: 2024/08/19 12:23:10 by jlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**map_duplicate(t_map *map, char **map_dup)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->lines)
	{
		map_dup[y] = malloc(sizeof(char) * (map->columns + 1));
		if (!map_dup[y])
			return (0);
		y++;
	}
	map_dup[y] = NULL;
	y = 0;
	while (map_dup[y])
	{
		x = 0;
		while (x < map->columns)
		{
			map_dup[y][x] = map->map_array[y][x];
			x++;
		}
		y++;
	}
	return (map_dup);
}

static void	search_path(int x, int y, t_map *map, char **map_dup)
{
	if (map_dup[y][x] == WALL)
		return ;
	else if (map_dup[y][x] == ITEM)
		map->collected_items++;
	else if (map_dup[y][x] == EXIT)
		map->e++;
	map_dup[y][x] = '1';
	search_path(x + 1, y, map, map_dup);
	search_path(x, y + 1, map, map_dup);
	search_path(x - 1, y, map, map_dup);
	search_path(x, y - 1, map, map_dup);
}

int	is_path_valid(t_root *root, t_map *map)
{
	int		x;
	int		y;
	char	**map_dup;

	x = map->player_x_pos;
	y = map->player_y_pos;
	map_dup = ft_calloc((map->lines + 1), sizeof(char *));
	if (!map_dup)
		return (0);
	map_duplicate(map, map_dup);
	search_path(x, y, map, map_dup);
	free_array(map_dup);
	if (map->collected_items == map->total_items && map->e == map->exit)
	{
		map->collected_items = 0;
		return (0);
	}
	else
		ft_error(root, "No valid path in this map");
	return (0);
}
