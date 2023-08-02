/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 10:34:54 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/08/02 12:57:45 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		have_all_params(t_game *cub3d)
{
	if (cub3d->north && cub3d->south && cub3d->east && cub3d->west)
		return (1);
	return (0);
}

// void	parse_line(t_game *cub3d, char *line, int i)
// {
// 	while (ft_isspace(line[i]))
// 		i++;
// 	{
// 		if ()
// 	}
// }

void	parse_file(t_game *cub3d, char *file)
{
	int		fd;
	char	*line;
	
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_error(cub3d, "Couldn't open requested file.");
	line = get_next_line(fd);
	while (!have_all_params(cub3d) && line)
	{
		free(line);
		line = get_next_line(fd);
	}
	if (!have_all_params(cub3d))
		exit_error(cub3d, "Missing mandatory parameters on the file.");
	close (fd);
}
