/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:01:35 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/08/04 16:31:11 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	have_duplicates(t_game *cub3d)
{
	if (ft_strcmp(cub3d->north, cub3d->south) == 0
		|| ft_strcmp(cub3d->north, cub3d->east) == 0
		|| ft_strcmp(cub3d->north, cub3d->west) == 0
		|| ft_strcmp(cub3d->south, cub3d->east) == 0
		|| ft_strcmp(cub3d->south, cub3d->west) == 0
		|| ft_strcmp(cub3d->east, cub3d->west) == 0)
		return (YES);
	return (NO);
}

int	have_all_params(t_game *cub3d)
{
	if (cub3d->north && cub3d->south && cub3d->east && cub3d->west
		&& cub3d->floor != -1 && cub3d->ceiling != -1)
		return (YES);
	return (NO);
}

void	check_texture_file(t_game *cub3d, char *file, int fd)
{
	check_filename(cub3d, file, XPM);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_error(cub3d, ERR_XPM_OPEN);
	close(fd);
}

char	*get_value(char *line, int i)
{
	int	end;

	while (line && ft_isspace(line[i]))
		i++;
	end = i;
	while (line[end] /* && !ft_isspace(line[end]) */ && line[end] != '\n')
		end++;
	line[end] = '\0';
	return (line + i);
}
