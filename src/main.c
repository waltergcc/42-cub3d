/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 09:44:54 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/08/03 12:24:50 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game(t_game *cub3d)
{
	ft_bzero(cub3d, sizeof(t_game));
	cub3d->north = NULL;
	cub3d->south = NULL;
	cub3d->east = NULL;
	cub3d->west = NULL;
	cub3d->north_count = 0;
	cub3d->south_count = 0;
	cub3d->east_count = 0;
	cub3d->west_count = 0;
}

void	launch_game(char *file)
{
	t_game	cub3d;

	init_game(&cub3d);
	parse_file(&cub3d, file);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		exit_error(NULL, "Invalid number of arguments");
	check_filename(NULL, av[1], CUB);
	launch_game(av[1]);
}
