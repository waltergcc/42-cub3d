/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_raycasting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 04:39:10 by anvieira          #+#    #+#             */
/*   Updated: 2023/08/14 17:06:35 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	render_collumn_pixel(t_game *cub3d)
{
	int		x;
	int		y;
	double	step_y;
	double	pos;

	step_y = fabs((double)TEXTURE_SIZE / cub3d->player.tall_of_wall);
	pos = (cub3d->player.tall_of_wall_y1 - (cub3d->game_h / 2) \
		+ (cub3d->player.tall_of_wall / 2)) * step_y;
	y = cub3d->player.tall_of_wall_y1;
	x = cub3d->pixel;
	while (y < cub3d->player.tall_of_wall_y2 && y < cub3d->game_h)
	{
		cub3d->player.text_y = (int)pos & (TEXTURE_SIZE - 1);
		pos += step_y;
		my_mlx_pixel_put(cub3d, x, y, obtain_color(cub3d));
		y++;
	}
}

void	calculate_current_ray(t_game *cub3d)
{
	double		ray;
	t_vector	ray_pixel;

	ray = 2 * ((double)cub3d->pixel / (cub3d->game_w - 1)) - 1;
	ray_pixel = mult_vector(&cub3d->player.plane, ray);
	cub3d->player.ray_dir = add_vector(&cub3d->player.dir, &ray_pixel);
}

int	rayscasting(t_game *cub3d)
{
	if (cub3d->frame.img)
		mlx_destroy_image(cub3d->mlx, cub3d->frame.img);
	cub3d->frame.img = mlx_new_image(cub3d->mlx, cub3d->game_w, cub3d->game_h);
	cub3d->frame.addr = mlx_get_data_addr(cub3d->frame.img, \
		&cub3d->frame.bpp, &cub3d->frame.line_len, \
		&cub3d->frame.endian);
	create_background(cub3d);
	while (cub3d->pixel < cub3d->game_w)
	{
		map_position_square(&cub3d->player);
		calculate_current_ray(cub3d);
		calculate_delta(cub3d);
		dda(cub3d);
		calculate_distance(cub3d);
		calculate_height_wall(cub3d);
		render_collumn_pixel(cub3d);
		cub3d->pixel++;
	}
	mlx_clear_window(cub3d->mlx, cub3d->window);
	mlx_put_image_to_window(cub3d->mlx, cub3d->window, cub3d->frame.img, 0, 0);
	cub3d->pixel = 0;
	return (0);
}

int	render_game(t_game *cub3d)
{
	cub3d->mlx = mlx_init();
	cub3d->window = mlx_new_window(cub3d->mlx, \
		cub3d->game_w, cub3d->game_h, WIN_TITLE);
	init_textures(cub3d, TEXTURE_SIZE);
	rayscasting(cub3d);
	mlx_key_hook(cub3d->window, read_keys, cub3d);
	mlx_hook(cub3d->window, 17, 1L << 0, end_game, cub3d);
	mlx_loop(cub3d->mlx);
	return (0);
}
