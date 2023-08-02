/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 11:28:49 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/08/02 08:46:37 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clean_tiles(char **tiles)
{
	size_t	i;

	i = 0;
	if (!tiles)
		return ;
	while (tiles[i])
		free (tiles[i++]);
	free (tiles);
}

void	clean_map(t_map *map)
{
	if (!map)
		return ;
	clean_tiles(map->tiles);
	free (map);
}

void	clean_game(t_game *so_long)
{
	if (!so_long)
		return ;
	if (so_long->map)
		clean_map(so_long->map);
}

int	quit_game(t_game *so_long)
{
	clean_game(so_long);
	exit(EXIT_SUCCESS);
}
