/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 23:26:10 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/08/04 17:52:55 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_arounded_by_walls(t_game *cub3d, int direction, int i, int j)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (direction == 0 || direction == 4 || direction == 5)
		x = -1;
	if (direction == 1 || direction == 5 || direction == 7)
		x = 1;
	if (direction == 2 || direction == 6 || direction == 7)
		y = 1;
	if (direction == 3 || direction == 4 || direction == 6)
		y = -1;
	while (j >= 0 && i >= 0 && cub3d->map[i]
		&& cub3d->map[i][j] && cub3d->map[i][j] != '1')
	{
		if (cub3d->map[i][j] == ' ')
			return (NO);
		i += y;
		j += x;
	}
	return (j >= 0 && i >= 0 && cub3d->map[i]
		&& cub3d->map[i][j] && cub3d->map[i][j] == '1');
}

void	check_map(t_game *cub3d, int i, int j)
{
	if (!cub3d->spawn)
		exit_error(cub3d, ERR_MAP_NSPAWN);
	while (cub3d->map[++i])
	{
		j = -1;
		while (cub3d->map[i][++j])
		{
			if (cub3d->map[i][j] != '0'
				&& !ft_isset(cub3d->map[i][j], SPAWN_CHARS))
				continue ;
			if (!is_arounded_by_walls(cub3d, 0, i, j)
				|| !is_arounded_by_walls(cub3d, 1, i, j)
				|| !is_arounded_by_walls(cub3d, 2, i, j)
				|| !is_arounded_by_walls(cub3d, 3, i, j)
				|| !is_arounded_by_walls(cub3d, 4, i, j)
				|| !is_arounded_by_walls(cub3d, 5, i, j)
				|| !is_arounded_by_walls(cub3d, 6, i, j)
				|| !is_arounded_by_walls(cub3d, 7, i, j))
				exit_error(cub3d, ERR_MAP_WALLS);
		}
	}
}

int	is_empty_line(t_game *cub3d, char *line)
{
	int	i;

	i = -1;
	while (line[++i])
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (NO);
	cub3d->empty_line_before = YES;
	return (YES);
}

void	parse_map_line(t_game *cub3d, char *line)
{
	int	i;

	i = -1;
	if (!is_empty_line(cub3d, line) && cub3d->empty_line_before == YES)
		exit_error(cub3d, ERR_MAP_EMPTY);
	while (line[++i] && line[i] != '\n')
	{
		if (!ft_isset(line[i], VALID_CHARS))
			exit_error(cub3d, ERR_MAP_CHARS);
		if (ft_isset(line[i], SPAWN_CHARS))
		{
			if (cub3d->spawn == 0)
				cub3d->spawn = line[i];
			else
				exit_error(cub3d, ERR_MAP_MSPAWN);
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
	check_map(cub3d, -1, -1);
}
