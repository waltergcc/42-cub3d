/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 10:34:54 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/08/03 18:26:07 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	have_all_params(t_game *cub3d)
{
	if (cub3d->north && cub3d->south && cub3d->east && cub3d->west)
		return (YES);
	return (NO);
}

void	check_texture_file(t_game *cub3d, char *file, int fd)
{
	check_filename(cub3d, file, XPM);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_error(cub3d, "Invalid texture file.");
	close(fd);
}

char	*get_value(char *line, int i)
{
	int	end;

	while (line && ft_isspace(line[i]))
		i++;
	end = i;
	while (line[end] && !ft_isspace(line[end]) && line[end] != '\n')
		end++;
	line[end] = '\0';
	return (line + i);
}

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
		exit_error(cub3d, "Has repeated textures calls in this input file");
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}
// void	set_colors(t_game *cub3d, int r, int g, int b, int face)
// {
	// if (face == FLOOR && cub3d->floor_count == 0)
	// {
	// 	cub3d->floor = color;
	// 	cub3d->floor_count++;
	// }
	// else if (face == CEILING && cub3d->ceiling_count == 0)
	// {
	// 	cub3d->ceiling = color;
	// 	cub3d->ceiling_count++;
	// }
	// else
	// 	exit_error(cub3d, "Has repeated colors calls in this input file");
// }

int	have_numbers(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (NO);
	return (YES);
}

void	check_color(t_game *cub3d, char *color, int face)
{
	int	r;
	int	g;
	int	b;
	(void)face;

	if (ft_count_words(color, ',') != 3)
		exit_error(cub3d, "Invalid color format");
	cub3d->colors = ft_split(color, ',');
	if (!have_numbers(cub3d->colors[0]) || !have_numbers(cub3d->colors[1])
		|| !have_numbers(cub3d->colors[2]))
		exit_error(cub3d, "Colors must have only digits");
	r = ft_atoi(cub3d->colors[0]);
	g = ft_atoi(cub3d->colors[1]);
	b = ft_atoi(cub3d->colors[2]);
	free_split(cub3d->colors);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		exit_error(cub3d, "Colors must be between 0 and 255");
	// set_colors(cub3d, r, g, b, face);
}


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

void	parse_line(t_game *cub3d, char *line, int i)
{
	while (ft_isspace(line[i]))
		i++;
	if (ft_strncmp(line + i, "NO", 2) == 0)
		check_texture(cub3d, get_value(line, i + 2), NORTH);
	else if (ft_strncmp(line + i, "SO", 2) == 0)
		check_texture(cub3d, get_value(line, i + 2), SOUTH);
	else if (ft_strncmp(line + i, "EA", 2) == 0)
		check_texture(cub3d, get_value(line, i + 2), EAST);
	else if (ft_strncmp(line + i, "WE", 2) == 0)
		check_texture(cub3d, get_value(line, i + 2), WEST);
	else if (ft_strncmp(line + i, "F", 1) == 0)
		printf("F\n");
	else if (ft_strncmp(line + i, "C", 1) == 0)
		printf("C\n");
}

void	final_check(t_game *cub3d)
{
	if (!have_all_params(cub3d))
		exit_error(cub3d, "The input file doesn't have all parameters");
	if (have_duplicates(cub3d))
		exit_error(cub3d, "Has repeated textures in this input file");
}

void	parse_file(t_game *cub3d, char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_error(cub3d, "Couldn't open the input file");
	cub3d->line = get_next_line(fd);
	while (cub3d->line)
	{
		parse_line(cub3d, cub3d->line, 0);
		free(cub3d->line);
		cub3d->line = get_next_line(fd);
	}
	final_check(cub3d);
	close (fd);
}
