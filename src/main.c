/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 09:44:54 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/08/03 22:14:46 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	convert_int_bit_to_rgb(t_game *cub3d, int r, int g, int b)
{
	r = (cub3d->floor >> 16) & 0xFF;
	g = (cub3d->floor >> 8) & 0xFF;
	b = cub3d->floor & 0xFF;
	printf("floor  : %d,%d,%d\n", r, g, b);
	r = (cub3d->ceiling >> 16) & 0xFF;
	g = (cub3d->ceiling >> 8) & 0xFF;
	b = cub3d->ceiling & 0xFF;
	printf("ceiling: %d,%d,%d\n", r, g, b);
}

void	init_game(t_game *cub3d)
{
	ft_bzero(cub3d, sizeof(t_game));
	cub3d->north = NULL;
	cub3d->south = NULL;
	cub3d->east = NULL;
	cub3d->west = NULL;
	cub3d->line = NULL;
	cub3d->colors = NULL;
	cub3d->ceiling = -1;
	cub3d->floor = -1;
	cub3d->start_map = NO;
}

void	launch_game(char *file)
{
	t_game	cub3d;

	init_game(&cub3d);
	parse_file(&cub3d, file);
	quit_game(&cub3d);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		exit_error(NULL, "Invalid number of arguments");
	check_filename(NULL, av[1], CUB);
	launch_game(av[1]);
}
