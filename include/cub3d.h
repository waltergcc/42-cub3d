/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 09:42:28 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/08/03 18:26:27 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/libft/libft.h"

# define TILES	"01CEP"

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
}				t_game;

// utils.c
int		exit_error(t_game *cub3d, char *msg);
void	check_filename(t_game *cub3d, char *file, int mode);

// clean_exit.c
int		quit_game(t_game *cub3d);
void	clean_game(t_game *cub3d);

// parse.c
void	parse_file(t_game *cub3d, char *file);

void	free_split(char **split);

#endif