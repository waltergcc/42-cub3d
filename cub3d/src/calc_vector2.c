/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:58:34 by anvieira          #+#    #+#             */
/*   Updated: 2023/08/10 11:16:50 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

//return (fabs(mag_vector(vector) / vector->x)); dividir por mag vector da 0
static double	delta_x(t_vector *vector)
{
	return (1 / vector->x);
}

//tem de ser absoluto porque o delta eh sempre positivo. vr no fim
//return (fabs(mag_vector(vector) / vector->y)); dividir por mag vector da 0
static double	delta_y(t_vector *vector)
{
	return (1 / vector->y);
}

double	dist_to_wall_x(t_player *p)
{
	double	dist_to_side_x;

	if (p->ray_dir.x < 0)
	{
		dist_to_side_x = (p->pos.x - p->map_square.x) * delta_x(&p->ray_dir);
		p->map_square.x += -1;
	}
	else
	{
		dist_to_side_x = (p->map_square.x + 1 - p->pos.x) \
			* delta_x(&p->ray_dir);
		p->map_square.x += 1;
	}
	return (dist_to_side_x);
}

double	dist_to_wall_y(t_player *p)
{
	double	dist_to_side_y;

	if (p->ray_dir.y < 0)
	{
		dist_to_side_y = (p->pos.y - p->map_square.y) * delta_y(&p->ray_dir);
		p->map_square.y += -1;
	}
	else
	{
		dist_to_side_y = (p->map_square.y + 1 - p->pos.y) \
			* delta_y(&p->ray_dir);
		p->map_square.y += 1;
	}
	return (dist_to_side_y);
}
