/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 11:28:49 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/08/03 12:19:48 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	clean_tiles(char **tiles)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!tiles)
// 		return ;
// 	while (tiles[i])
// 		free (tiles[i++]);
// 	free (tiles);
// }

// void	clean_map(t_map *map)
// {
// 	if (!map)
// 		return ;
// 	clean_tiles(map->tiles);
// 	free (map);
// }

void	clean_game(t_game *cub3d)
{
	if (!cub3d)
		return ;
	if (cub3d->north)
		free (cub3d->north);
	if (cub3d->south)
		free (cub3d->south);
	if (cub3d->east)
		free (cub3d->east);
	if (cub3d->west)
		free (cub3d->west);
	// if (so_long->mlx)
	// if (so_long->map)
	// 	clean_map(so_long->map);
}

// int	quit_game(t_game *so_long)
// {
// 	clean_game(so_long);
// 	exit(EXIT_SUCCESS);
// }
