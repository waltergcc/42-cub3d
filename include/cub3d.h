/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 09:42:28 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/08/03 12:16:57 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/libft/libft.h"

# define TILES	"01CEP"
# define CUB 	1
# define XPM	2
# define NORTH	1
# define SOUTH	2
# define EAST	3
# define WEST	4	

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
	char		*north;
	char		*south;
	char		*east;
	char		*west;
	int			north_count;
	int			south_count;
	int			east_count;
	int			west_count;
	t_map		*map;
	t_point		curr;
	t_point		next;
	t_uint		coins;
	t_uint		moves;
}				t_game;

// utils.c
// t_tile	get_tile(t_game *so_long, t_point p);
// int		flood_fill(t_map *map, t_point curr, char **path);
// int		is_same_point(t_point a, t_point b);
int		exit_error(t_game *cub3d, char *msg);
void	check_filename(t_game *cub3d, char *file, int mode);

// clean_exit.c
// void	clean_tiles(char **tiles);
// int		quit_game(t_game *so_long);
void	clean_game(t_game *cub3d);

void	parse_file(t_game *cub3d, char *file);

#endif