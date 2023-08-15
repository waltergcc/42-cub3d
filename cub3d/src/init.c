/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:15:44 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/08/14 17:16:39 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	init_player(t_player *player)
{
	player->dir.x = ZERO;
	player->dir.y = -ONE;
	player->plane.x = PLANE;
	player->plane.y = ZERO;
}

void	init_textures(t_game *cub3d, int size)
{
	cub3d->north_img.img = mlx_xpm_file_to_image(cub3d->mlx, cub3d->north, \
		&size, &size);
	cub3d->south_img.img = mlx_xpm_file_to_image(cub3d->mlx, cub3d->south, \
		&size, &size);
	cub3d->east_img.img = mlx_xpm_file_to_image(cub3d->mlx, cub3d->east, \
		&size, &size);
	cub3d->west_img.img = mlx_xpm_file_to_image(cub3d->mlx, cub3d->west, \
		&size, &size);
	if (!cub3d->north_img.img || !cub3d->south_img.img || \
		!cub3d->east_img.img || !cub3d->west_img.img)
		invalid_xpm_error(cub3d, ERR_TEXTURE);
	cub3d->north_img.addr = mlx_get_data_addr(cub3d->north_img.img, \
		&cub3d->north_img.bpp, &cub3d->north_img.line_len, \
		&cub3d->north_img.endian);
	cub3d->south_img.addr = mlx_get_data_addr(cub3d->south_img.img, \
		&cub3d->south_img.bpp, &cub3d->south_img.line_len, \
		&cub3d->south_img.endian);
	cub3d->east_img.addr = mlx_get_data_addr(cub3d->east_img.img, \
		&cub3d->east_img.bpp, &cub3d->east_img.line_len, \
		&cub3d->east_img.endian);
	cub3d->west_img.addr = mlx_get_data_addr(cub3d->west_img.img, \
		&cub3d->west_img.bpp, &cub3d->west_img.line_len, \
		&cub3d->west_img.endian);
}

void	init_game(t_game *cub3d)
{
	cub3d->ceiling = -1;
	cub3d->floor = -1;
	init_player(&cub3d->player);
}

void	get_screen_size(t_game *cub3d, void	*mlx, void	*win, int split)
{
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1, 1, "tmp");
	mlx_get_screen_size(mlx, &cub3d->game_w, &cub3d->game_h);
	mlx_destroy_window(mlx, win);
	mlx_destroy_display(mlx);
	free(mlx);
	if (split == 2 || split == 3 || split == 4)
	{
		cub3d->game_w /= split;
		cub3d->game_h /= split;
	}
}
