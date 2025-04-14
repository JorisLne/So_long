/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine <jlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:13:16 by jlaine            #+#    #+#             */
/*   Updated: 2024/08/19 11:25:10 by jlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	line_counter(int fd)
{
	int		i;
	char	*buffer;

	i = 0;
	while (1)
	{
		buffer = get_next_line(fd);
		if (!buffer)
			return (i);
		i++;
		free(buffer);
	}
}

static char	**read_map(int fd, int lines)
{
	int		i;
	char	*tmp;
	char	**map;

	i = 0;
	map = ft_calloc(lines + 1, sizeof(char *));
	if (!map)
		return (0);
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			return (map);
		map[i] = ft_strtrim(tmp, "\n");
		free(tmp);
		i++;
	}
}

static void	count_values(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->map_array[y])
	{
		x = 0;
		while (map->map_array[y][x])
		{
			if (map->map_array[y][x] == 'C')
				map->total_items++;
			if (map->map_array[y][x] == 'E')
				map->exit++;
			if (map->map_array[y][x] == 'P')
			{
				map->players++;
				map->player_x_pos = x;
				map->player_y_pos = y;
			}
			x++;
		}
		y++;
	}
}

int	prep_map_values(t_root *root, char *str, t_map *map)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (0);
	map->lines = line_counter(fd);
	close(fd);
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (0);
	map->map_array = read_map(fd, map->lines);
	if (map->lines == 0)
		ft_error(root, "Empty file.");
	map->columns = ft_strlen(map->map_array[0]);
	close(fd);
	count_values(map);
	return (0);
}
