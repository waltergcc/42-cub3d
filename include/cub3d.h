/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 09:42:28 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/08/03 21:05:11 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/libft/libft.h"

# define NO			0
# define YES 		1

# define CUB 		1
# define XPM		2

# define NORTH		1
# define SOUTH		2
# define EAST		3
# define WEST		4
# define FLOOR		5
# define CEILING	6

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
char	*get_value(char *line, int i);

#endif