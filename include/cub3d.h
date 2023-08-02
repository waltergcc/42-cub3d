/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 09:42:28 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/08/02 08:52:20 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/libft/libft.h"

# define TILES		"01CEP"

typedef unsigned int	t_uint;

typedef enum e_tile
{
	SPACE	= '0',
	WALL	= '1',
	COIN	= 'C',
	EXIT	= 'E',
	PLAYER	= 'P',
}			t_tile;

typedef struct s_point
{
	t_uint	x;
	t_uint	y;
}			t_point;

typedef struct s_map
{
	char	**tiles;
	t_uint	cols;
	t_uint	rows;
	t_uint	coins;
	t_uint	exits;
	t_uint	players;
}			t_map;

typedef struct s_game
{
	t_map		*map;
	t_point		curr;
	t_point		next;
	t_uint		coins;
	t_uint		moves;
}				t_game;

t_tile	get_tile(t_game *so_long, t_point p);
int		flood_fill(t_map *map, t_point curr, char **path);
int		exit_error(t_game *so_long, char *msg);
void	check_filename(char *file);
int		is_same_point(t_point a, t_point b);

void	clean_tiles(char **tiles);
void	clean_game(t_game *so_long);
int		quit_game(t_game *so_long);

void	check_map(t_game *so_long);
void	read_map(t_game *so_long, char *file);

#endif