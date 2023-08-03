/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 23:26:10 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/08/04 00:29:07 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_map_line(t_game *cub3d, char *line)
{
	int	i;

	i = -1;
	while (line[++i] && line[i] != '\n')
	{
		if (!ft_isset(line[i], MAP_CHARS))
			exit_error(cub3d, "Invalid character in map");
		if (ft_isset(line[i], SPAWN))
		{
			if (cub3d->spawn == 0)
				cub3d->spawn = line[i];
			else
				exit_error(cub3d, "Multiple spawn points");
		}
	}
}

void	parse_map(t_game *cub3d, int fd)
{
	while (cub3d->line)
	{
		parse_map_line(cub3d, cub3d->line);
		cub3d->temp_map = ft_strjoin(cub3d->temp_map, cub3d->line);
		free(cub3d->line);
		cub3d->line = get_next_line(fd);
	}
	cub3d->map = ft_split(cub3d->temp_map, '\n');
	if (cub3d->temp_map)
	{
		free(cub3d->temp_map);
		cub3d->temp_map = NULL;
	}
}
