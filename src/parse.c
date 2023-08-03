/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 10:34:54 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/08/03 17:21:42 by wcorrea-         ###   ########.fr       */
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
	if (face == NORTH && cub3d->north_count == 0)
	{
		cub3d->north = ft_strdup(file);
		cub3d->north_count++;
	}
	else if (face == SOUTH && cub3d->south_count == 0)
	{
		cub3d->south = ft_strdup(file);
		cub3d->south_count++;
	}
	else if (face == EAST && cub3d->east_count == 0)
	{
		cub3d->east = ft_strdup(file);
		cub3d->east_count++;
	}
	else if (face == WEST && cub3d->west_count == 0)
	{
		cub3d->west = ft_strdup(file);
		cub3d->west_count++;
	}
	else
		exit_error(cub3d, "Has repeated textures calls in this input file");
}

int	have_duplicates(t_game *cub3d)
{
	if (cub3d->north_count > 1 || cub3d->south_count > 1
		|| cub3d->east_count > 1 || cub3d->west_count > 1)
		return (1);
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
