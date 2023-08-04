/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 09:42:28 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/08/04 17:54:57 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/libft/libft.h"

# define NO				0
# define YES 			1

# define CUB 			1
# define XPM			2

# define TEXTURE		1
# define COLOR			2

# define NORTH			1
# define SOUTH			2
# define EAST			3
# define WEST			4
# define FLOOR			5
# define CEILING		6

# define SPAWN_CHARS	"NSEW"
# define VALID_CHARS	" 01NSEW"
# define SPLIT_RGB		" ,"

# define ERR_ARGS		"Invalid number of arguments"

# define ERR_CUB		"Invalid input file name"
# define ERR_CUB_EXT	"Input file must be .cub"
# define ERR_CUB_OPEN	"Couldn't open input file"

# define ERR_XPM		"Invalid texture file name"
# define ERR_XPM_EXT	"Asset file must be .xpm"
# define ERR_XPM_OPEN	"Couldn't open texture file"
# define ERR_XPM_RPT	"Has repeated textures in this input file"
# define ERR_XPM_CALL	"Has repeated textures calls in this input file"

# define ERR_COLOR_FMT	"Color format must be R,G,B"
# define ERR_COLOR_NUM	"Colors must have only positive numbers"
# define ERR_COLOR_RANG "Colors must be between 0 and 255"
# define ERR_COLOR_CALL	"Has repeated colors calls in this input file"

# define ERR_INVALID	"The input file has invalid parameters"
# define ERR_PARAMS		"The input file doesn't have all necessary parameters"

# define ERR_MAP_EMPTY	"Map is not configured correctly"
# define ERR_MAP_WALLS	"The map isn't well surrounded by walls"
# define ERR_MAP_CHARS	"Invalid character in map"
# define ERR_MAP_MSPAWN	"Multiple spawn points"
# define ERR_MAP_NSPAWN	"No spawn point"

typedef struct s_game
{
	char		*north;
	char		*south;
	char		*east;
	char		*west;
	char		*line;
	char		**colors;
	int			ceiling;
	int			floor;
	int			start_map;
	char		*temp_map;
	char		spawn;
	char		**map;
	int			empty_line_before;
}				t_game;

// utils.c
int		exit_error(t_game *cub3d, char *msg);
void	check_filename(t_game *cub3d, char *file, int mode);
void	free_split(char **split);
int		have_numbers(char *str);

// clean_exit.c
int		quit_game(t_game *cub3d);
void	clean_game(t_game *cub3d);

// parse.c
void	parse_file(t_game *cub3d, char *file);
void	parse_line(t_game *cub3d, char *line, int i);
void	check_color(t_game *cub3d, char *color, int face);
void	check_texture(t_game *cub3d, char *file, int face);

// parse_utils.c
int		have_duplicates(t_game *cub3d);
int		have_all_params(t_game *cub3d);
void	check_texture_file(t_game *cub3d, char *file, int fd);
char	*get_value(char *line, int i, int mode);

// parse_map.c
void	parse_map(t_game *cub3d, int fd);
int		is_arounded_by_walls(t_game *cub3d, int direction, int i, int j);
void	check_map(t_game *cub3d, int i, int j);
void	parse_map_line(t_game *cub3d, char *line);
int		is_empty_line(t_game *cub3d, char *line);

#endif