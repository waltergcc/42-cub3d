/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:01:35 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/08/08 04:12:54 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	have_numbers(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (NO);
	return (YES);
}

int	have_all_params(t_game *cub3d)
{
	if (cub3d->north && cub3d->south && cub3d->east && cub3d->west
		&& cub3d->floor != -1 && cub3d->ceiling != -1 && cub3d->start_map == 1)
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

char	*get_value(char *line, int i, int mode)
{
	int	end;

	while (line && ft_isspace(line[i]))
		i++;
	end = i;
	if (mode == TEXTURE)
	{
		while (line[end] && !ft_isspace(line[end]) && line[end] != '\n')
			end++;
	}
	else if (mode == COLOR)
	{
		while (line[end] && line[end] != '\n')
			end++;
	}
	line[end] = '\0';
	return (line + i);
}

void	check_filename(t_game *cub3d, char *file, int mode)
{
	size_t	i;

	i = ft_strlen(file);
	if (i <= 4)
	{
		if (mode == CUB)
			exit_error(NULL, ERR_CUB);
		else if (mode == XPM)
			exit_error(cub3d, ERR_XPM);
	}
	else if (mode == CUB && !ft_strnstr((file + i - 4), ".cub", 4))
		exit_error(NULL, ERR_CUB_EXT);
	else if (mode == XPM && !ft_strnstr((file + i - 4), ".xpm", 4))
		exit_error(cub3d, ERR_XPM_EXT);
}
