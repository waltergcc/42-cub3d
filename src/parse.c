/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 10:34:54 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/08/02 13:10:02 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		have_all_params(t_game *cub3d)
{
	if (cub3d->north && cub3d->south && cub3d->east && cub3d->west)
		return (1);
	return (0);
}

void	parse_line(t_game *cub3d, char *line, int i)
{
	(void)cub3d;
	
	while (ft_isspace(line[i]))
		i++;
	if (ft_strncmp(line + i, "NO", 2) == 0)
		printf("NO\n");
	else if (ft_strncmp(line + i, "SO", 2) == 0)
		printf("SO\n");
	else if (ft_strncmp(line + i, "WE", 2) == 0)
		printf("WE\n");
	else if (ft_strncmp(line + i, "EA", 2) == 0)
		printf("EA\n");
	else if (ft_strncmp(line + i, "F", 1) == 0)
		printf("F\n");
	else if (ft_strncmp(line + i, "C", 1) == 0)
		printf("C\n");
}

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
		parse_line(cub3d, line, 0);
		free(line);
		line = get_next_line(fd);
	}
	if (!have_all_params(cub3d))
		exit_error(cub3d, "Missing mandatory parameters on the file.");
	close (fd);
}
