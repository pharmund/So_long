/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:57:19 by pharmund          #+#    #+#             */
/*   Updated: 2022/02/10 21:16:47 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_img(t_params *par, char *placement, int x, int y)
{
	int		img_width;
	int		img_height;
	void	*img;

	img = mlx_xpm_file_to_image(par->mlx, placement, &img_width, &img_height);
	mlx_put_image_to_window(par->mlx, par->wind, img, x, y);
}

int	render_const_frame(t_params *par)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < par -> height)
	{
		x = 0;
		while (x < par -> width)
		{
			if (par->map[y][x] == 'E')
				print_img(par, EXIT, x * 64, y * 64);
			else if (par -> map[y][x] == '1')
				print_img(par, WALLS, x * 64, y * 64);
			else
				print_img(par, GROUND, x * 64, y * 64);
			x++;
		}
		y++;
	}
	return (0);
}

int	render_next_frame(t_params *par)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < par->height)
	{
		x = 0;
		while (x < par->width)
		{
			if (par->map[y][x] == 'C')
			{
				print_img(par, GROUND, x * 64, y * 64);
				print_img(par, COLLECTABLE, x * 64, y * 64);
			}
			x++;
		}
		y++;
	}
	print_img(par, PLAYER, par->p_x * 64, par->p_y * 64);
	return (0);
}

void	hooks(t_params *par)
{
	mlx_hook(par->wind, KEYPRESS, 1L << 0, press_key, par);
	mlx_hook(par->wind, KEYEXIT, 1L << 0, gameover, par);
	render_const_frame(par);
	mlx_loop_hook(par->mlx, render_next_frame, par);
}
