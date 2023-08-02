/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 09:48:12 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/08/02 16:39:45 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_tile	get_tile(t_game *so_long, t_point p)
{
	return (so_long->map->tiles[p.y][p.x]);
}

int	is_same_point(t_point a, t_point b)
{
	return (a.x == b.x && a.y == b.y);
}

int	flood_fill(t_map *map, t_point curr, char **path)
{
	static t_uint	coins = 0;
	static int		exit = 0;

	if (path[curr.y][curr.x] == WALL)
		return (0);
	else if (path[curr.y][curr.x] == COIN)
		coins++;
	else if (path[curr.y][curr.x] == EXIT)
		exit = 1;
	path[curr.y][curr.x] = WALL;
	flood_fill(map, (t_point){curr.x + 1, curr.y}, path);
	flood_fill(map, (t_point){curr.x - 1, curr.y}, path);
	flood_fill(map, (t_point){curr.x, curr.y + 1}, path);
	flood_fill(map, (t_point){curr.x, curr.y - 1}, path);
	return (coins == map->coins && exit == 1);
}

int	exit_error(t_game *so_long, char *msg)
{
	clean_game(so_long);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	exit (EXIT_FAILURE);
}

void	check_filename(char *file, int mode)
{
	size_t	i;

	i = ft_strlen(file);
	if (i <= 4)
		exit_error(NULL, "Invalid file name.");
	else if (mode == CUB && !ft_strnstr((file + i - 4), ".cub", 4))
		exit_error(NULL, "Invalid file extension.");
	else if (mode == XPM && !ft_strnstr((file + i - 4), ".xpm", 4))
		exit_error(NULL, "Asset file must be .xpm.");
}
