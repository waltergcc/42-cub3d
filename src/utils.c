/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 09:48:12 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/08/03 17:10:28 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exit_error(t_game *cub3d, char *msg)
{
	clean_game(cub3d);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	exit (EXIT_FAILURE);
}

void	check_filename(t_game *cub3d, char *file, int mode)
{
	size_t	i;

	i = ft_strlen(file);
	if (i <= 4)
	{
		if (mode == CUB)
			exit_error(NULL, "Invalid input file name");
		else if (mode == XPM)
			exit_error(cub3d, "Invalid texture file name");
	}
	else if (mode == CUB && !ft_strnstr((file + i - 4), ".cub", 4))
		exit_error(NULL, "Invalid file extension");
	else if (mode == XPM && !ft_strnstr((file + i - 4), ".xpm", 4))
		exit_error(cub3d, "Asset file must be .xpm");
}
