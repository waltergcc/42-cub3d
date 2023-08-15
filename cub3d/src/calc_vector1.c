/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 00:41:50 by anvieira          #+#    #+#             */
/*   Updated: 2023/08/09 22:18:30 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// /* bate de baixo para cima, ou seja, bate em baixo */
// double     euclidean_dist_hz_down(t_player *p)
// {   
//     double n;
//     n = fabs(p->map_square_y + 1 - p->pos_y) * mag_vector(&p->ray_dir);
//     n = n / p->ray_dir.y; //cuidado se for zero
//     return (n);
// }
// /* bate ao contrario, bate no lado superior */
// double     euclidean_dist_hz_up(t_player *p)
// {   
//     double n;
//     n = fabs(p->map_square_y - p->pos_y) * mag_vector(&p->ray_dir);
//     n = n / p->ray_dir.y; //cuidado se for zero
//     return (n);
// }

// double     euclidean_dist_hz(t_player *p, int step_y)
// {
//     double n;
//     if (step_y == 1)
//         n = euclidean_dist_hz_down(p);
//     else
//         n = euclidean_dist_hz_up(p);
// }

// /* ******************************************************************* */
// double euclidean_dist_vt_right(t_player *p)
// {
//     double n;
//     n = fabs(p->map_square_x + 1 - p->pos_x) * mag_vector(&p->ray_dir);
//     n = n / p->ray_dir.x; //cuidado se for zero
//     return (n);
// }

// double euclidean_dist_vt_left(t_player *p)
// {
//     double n;
//     n = fabs(p->map_square_x - p->pos_x) * mag_vector(&p->ray_dir);
//     n = n / p->ray_dir.x; //cuidado se for zero
//     return (n);
// }

// double euclidean_dist_vt(t_player *p, int step_x)
// {
//     double n;
//     if (step_x == 1)
//         n = euclidean_dist_vt_right(p);
//     else
//         n = euclidean_dist_vt_left(p);
//     return (n);
// }

/* ************************************************************************** */

#include "../includes/cub.h"

t_vector	add_vector(t_vector *v1, t_vector *v2)
{
	t_vector	new;

	new.x = v1->x + v2->x;
	new.y = v1->y + v2->y;
	return (new);
}

t_vector	mult_vector(t_vector *v, double n)
{
	t_vector	new;

	new.x = v->x * n;
	new.y = v->y * n;
	return (new);
}

double	perpendicular_dist_x(t_player *p, int step_x)
{
	double	n;

	n = fabs(p->map_square.x - p->pos.x + ((1 - step_x) / 2));
	n /= p->ray_dir.x;
	return (n);
}

double	perpendicular_dist_y(t_player *p, int step_y)
{
	double	n;

	n = fabs(p->map_square.y - p->pos.y + ((1 - step_y) / 2));
	n /= p->ray_dir.y;
	return (n);
}
