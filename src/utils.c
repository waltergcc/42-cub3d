/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 09:48:12 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/08/04 10:57:46 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

int	have_numbers(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (NO);
	return (YES);
}

int	exit_error(t_game *cub3d, char *msg)
{
	clean_game(cub3d);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	exit (EXIT_FAILURE);
}

void	check_filename(t_game *cub3d, char *file, int mode)
{
	size_t	i;

	i = ft_strlen(file);
	if (i <= 4)
	{
		if (mode == CUB)
			exit_error(NULL, ERR_CUB);
		else if (mode == XPM)
			exit_error(cub3d, ERR_XPM);
	}
	else if (mode == CUB && !ft_strnstr((file + i - 4), ".cub", 4))
		exit_error(NULL, ERR_CUB_EXT);
	else if (mode == XPM && !ft_strnstr((file + i - 4), ".xpm", 4))
		exit_error(cub3d, ERR_XPM_EXT);
}
