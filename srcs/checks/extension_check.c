/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine <jlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:33:59 by jlaine            #+#    #+#             */
/*   Updated: 2024/08/16 18:01:52 by jlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	extension_check(t_root *root, char *str)
{
	int		i;
	char	*extension;
	int		extension_start;
	int		filename_len;

	i = 0;
	extension = ".ber";
	filename_len = ft_strlen(str);
	extension_start = ft_strlen(str) - 4;
	if (*str == *extension)
		ft_error(root, "Map name is invalid");
	while (extension_start < filename_len)
	{
		if (extension[i] != str[extension_start])
			ft_error(root, "Map extension is invalid");
		extension_start++;
		i++;
	}
	return (0);
}
