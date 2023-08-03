/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 10:34:54 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/08/03 20:36:02 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_next_line2(int fd)
{
	char	*buffer;
	char	character;
	int		i;
	int		rd;

	i = 0;
	rd = 1;
	character = 0;
	if (BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(100000);
	while (rd > 0)
	{
		rd = read(fd, &character, BUFFER_SIZE - BUFFER_SIZE + 1);
		buffer[i++] = character;
		if (character == '\n')
			break ;
	}
	buffer[i] = '\0';
	if (rd == -1 || i == 0 || (!buffer[i - 1] && !rd))
		return (free(buffer), NULL);
	return (buffer);
}

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

	if (ft_count_words(color, ',') != 3)
		exit_error(cub3d, "Invalid color format");
	cub3d->colors = ft_split(color, ',');
	if (!have_numbers(cub3d->colors[0]) || !have_numbers(cub3d->colors[1])
		|| !have_numbers(cub3d->colors[2]))
		exit_error(cub3d, "Colors must have only positive numbers");
	r = ft_atoi(cub3d->colors[0]);
	g = ft_atoi(cub3d->colors[1]);
	b = ft_atoi(cub3d->colors[2]);
	free_split(cub3d->colors);
	cub3d->colors = NULL;
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		exit_error(cub3d, "Colors must be between 0 and 255");
	if (face == FLOOR && cub3d->floor == -1)
		cub3d->floor = (0 << 24 | r << 16 | g << 8 | b);
	else if (face == CEILING && cub3d->ceiling == -1)
		cub3d->ceiling = (0 << 24 | r << 16 | g << 8 | b);
	else
		exit_error(cub3d, "Has repeated colors calls in this input file");
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
		check_color(cub3d, get_value(line, i + 1), FLOOR);
	else if (ft_strncmp(line + i, "C", 1) == 0)
		check_color(cub3d, get_value(line, i + 1), CEILING);
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
	cub3d->line = get_next_line2(fd);
	while (cub3d->line)
	{
		parse_line(cub3d, cub3d->line, 0);
		free(cub3d->line);
		cub3d->line = get_next_line2(fd);
	}
	final_check(cub3d);
	close (fd);
}
