/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine <jlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:17:15 by jlaine            #+#    #+#             */
/*   Updated: 2024/08/21 13:04:44 by jlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

static int	file_exist(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

int	main(int ac, char **av)
{
	t_root	root;

	ft_bzero(&root, sizeof(root));
	map_init(&(root.map));
	if (ac != 2)
	{
		ft_printf("Error\nProgram needs <so_long> and <map.ber> to start\n");
		return (1);
	}
	if (!file_exist(av[1]))
	{
		ft_printf("Error\nFile doesn't exist or cannot be open");
		return (1);
	}
	extension_check(&root, av[1]);
	is_map_valid(&root, av[1], &(root.map));
	init_window(&root);
	load_sprites(&root);
	game(&root);
	return (0);
}
