/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 10:34:54 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/08/09 00:56:29 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	check_texture(t_game *cub3d, char *file, int face)
{
	check_texture_file(cub3d, file, 0);
	if (face == NORTH && !cub3d->north)
		cub3d->north = ft_strdup(file);
	else if (face == SOUTH && !cub3d->south)
		cub3d->south = ft_strdup(file);
	else if (face == EAST && !cub3d->east)
		cub3d->east = ft_strdup(file);
	else if (face == WEST && !cub3d->west)
		cub3d->west = ft_strdup(file);
	else
		exit_error(cub3d, ERR_XPM_CALL);
}

void	check_color(t_game *cub3d, char *color, int face)
{
	int	r;
	int	g;
	int	b;

	if (count_words(color, SPLIT_RGB) != 3)
		exit_error(cub3d, ERR_COLOR_FMT);
	cub3d->colors = ft_split2(color, SPLIT_RGB);
	if (!have_numbers(cub3d->colors[0]) || !have_numbers(cub3d->colors[1])
		|| !have_numbers(cub3d->colors[2]))
		exit_error(cub3d, ERR_COLOR_NUM);
	r = ft_atoi(cub3d->colors[0]);
	g = ft_atoi(cub3d->colors[1]);
	b = ft_atoi(cub3d->colors[2]);
	free_split(cub3d->colors);
	cub3d->colors = NULL;
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		exit_error(cub3d, ERR_COLOR_RANG);
	if (face == FLOOR && cub3d->floor == -1)
		cub3d->floor = (0 << 24 | r << 16 | g << 8 | b);
	else if (face == CEILING && cub3d->ceiling == -1)
		cub3d->ceiling = (0 << 24 | r << 16 | g << 8 | b);
	else
		exit_error(cub3d, ERR_COLOR_CALL);
}

void	parse_line(t_game *cub3d, char *line, int i)
{
	while (ft_isspace(line[i]))
		i++;
	if (ft_strncmp(line + i, "NO", 2) == 0)
		check_texture(cub3d, get_value(line, i + 2, TEXTURE), NORTH);
	else if (ft_strncmp(line + i, "SO", 2) == 0)
		check_texture(cub3d, get_value(line, i + 2, TEXTURE), SOUTH);
	else if (ft_strncmp(line + i, "EA", 2) == 0)
		check_texture(cub3d, get_value(line, i + 2, TEXTURE), EAST);
	else if (ft_strncmp(line + i, "WE", 2) == 0)
		check_texture(cub3d, get_value(line, i + 2, TEXTURE), WEST);
	else if (ft_strncmp(line + i, "F", 1) == 0)
		check_color(cub3d, get_value(line, i + 1, COLOR), FLOOR);
	else if (ft_strncmp(line + i, "C", 1) == 0)
		check_color(cub3d, get_value(line, i + 1, COLOR), CEILING);
	else if (line[i] == '0' || line[i] == '1')
		cub3d->start_map = YES;
	else if (line[i] != '\0')
		exit_error(cub3d, ERR_INVALID);
}

void	parse_file(t_game *cub3d, char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_error(cub3d, ERR_CUB_OPEN);
	cub3d->line = get_next_line(fd);
	while (cub3d->line)
	{
		parse_line(cub3d, cub3d->line, 0);
		if (cub3d->start_map)
			break ;
		free(cub3d->line);
		cub3d->line = get_next_line(fd);
	}
	if (!have_all_params(cub3d))
		exit_error(cub3d, ERR_PARAMS);
	parse_map(cub3d, fd);
	close (fd);
}
