/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 21:59:15 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/08/10 16:45:23 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	rotate_vector(t_vector *v, double angle)
{
	double	x;
	double	y;

	x = v->x;
	y = v->y;
	v->x = x * cos(angle) - y * sin(angle);
	v->y = x * sin(angle) + y * cos(angle);
}

void	set_direction(t_game *cub3d)
{
	if (cub3d->spawn == 'S')
	{
		cub3d->player.dir.y = ONE;
		cub3d->player.plane.x = -PLANE;
	}
	else if (cub3d->spawn == 'E')
	{
		cub3d->player.dir.x = ONE;
		cub3d->player.dir.y = ZERO;
		cub3d->player.plane.x = ZERO;
		cub3d->player.plane.y = PLANE;
	}
	else if (cub3d->spawn == 'W')
	{
		cub3d->player.dir.x = -ONE;
		cub3d->player.dir.y = ZERO;
		cub3d->player.plane.x = ZERO;
		cub3d->player.plane.y = -PLANE;
	}
}

void	set_player_position(t_game *cub3d, int i, int j)
{
	while (cub3d->map[++i])
	{
		j = -1;
		while (cub3d->map[i][++j])
		{
			if (cub3d->map[i][j] == cub3d->spawn)
			{
				cub3d->player.pos.x = j + 0.5;
				cub3d->player.pos.y = i + 0.5;
				cub3d->map[i][j] = '0';
				set_direction(cub3d);
				return ;
			}
		}
	}
}
