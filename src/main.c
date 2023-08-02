/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 09:44:54 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/08/02 08:46:30 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	launch_game(char *file)
{
	t_game	sl;

	ft_bzero(&sl, sizeof(t_game));
	read_map(&sl, file);
	check_map(&sl);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		exit_error(NULL, "Invalid number of arguments.");
	check_filename(av[1]);
	launch_game(av[1]);
}
