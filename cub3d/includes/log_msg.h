/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_msg.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 03:53:52 by antero            #+#    #+#             */
/*   Updated: 2023/08/15 10:05:14 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOG_MSG_H
# define LOG_MSG_H

/* COLORS */
# define DEF			"\033[0;39m"
# define GRAY			"\033[0;90m"
# define RED			"\033[0;91m"
# define GREEN			"\033[0;92m"
# define YELLOW			"\033[0;93m"
# define BLUE			"\033[0;94m"
# define MAGENTA		"\033[0;95m"
# define CYAN			"\033[0;96m"
# define WHITE			"\033[0;97m"

/* SELECTORS */
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

/* CHAR SETS */
# define SPAWN_CHARS	"NSEW"
# define VALID_CHARS	" 01NSEW"
# define SPLIT_RGB		" ,"

/* ERROR MESSAGES */
# define ERR_ARGS		"Invalid number of arguments"

# define ERR_CUB		"Invalid input file name"
# define ERR_CUB_EXT	"Input file must be .cub"
# define ERR_CUB_OPEN	"Couldn't open input file"

# define ERR_XPM		"Invalid texture file name"
# define ERR_XPM_EXT	"Asset file must be .xpm"
# define ERR_XPM_OPEN	"Couldn't open texture file"
# define ERR_XPM_RPT	"Has repeated textures in this input file"
# define ERR_XPM_CALL	"Has repeated textures calls in this input file"
# define ERR_TEXTURE	"Invalid texture file"

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

/* WINDOW SIZE*/
# define WIN_W			320
# define WIN_H			200
# define WIN_TITLE		"Cub3D"
# define TEXTURE_SIZE	64

/* STANDART PLAYER CAM*/
# define ONE			1
# define ZERO			0
# define PLANE			0.66

/* CONTROLS SPEED */
# define MOV			0.2
# define ROT			0.1

/* KEYS */
# define KEY_ESC		65307
# define LEFT			65361
# define RIGHT			65363
# define W				119
# define A				97
# define S				115
# define D				100

#endif