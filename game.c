/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:57:06 by pharmund          #+#    #+#             */
/*   Updated: 2022/02/14 12:59:54 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_values(t_params *par)
{
	size_t	x;
	size_t	y;

	par->collect = 0;
	par->score = 0;
	par->won = 0;
	y = 0;
	while (y < par->height)
	{
		x = 0;
		while (x < par->width)
		{
			if (par->map[y][x] == 'P')
			{
				par->p_y = y;
				par->p_x = x;
			}
			if (par->map[y][x] == 'C')
				par->collect++;
			x++;
		}
		y++;
	}
}

int	gameover(t_params *par)
{
	size_t	i;

	i = 0;
	if (par->won == 1)
		ft_putstr_fd(">>> YOU WON <<<\n", 1);
	while (i < par->height)
	{
		free(par->map[i]);
		i++;
	}
	free(par->map);
	free(par->mlx);
	free(par->wind);
	sleep(1);
	exit(0);
}

int	press_key(int keycode, t_params *par)
{
	if (par->won == 1 || keycode == ESC)
		gameover(par);
	if (keycode == A)
		move_player(par, -1, 0);
	if (keycode == S)
		move_player(par, 0, 1);
	if (keycode == D)
		move_player(par, 1, 0);
	if (keycode == W)
		move_player(par, 0, -1);
	return (0);
}

void	count_moves(t_params *par)
{
	print_img(par, WALLS, 0, 0);
	ft_putnbr_fd(par->moves, 1);
	write(1, "\n", 1);
	mlx_string_put(par->mlx, par->wind, 30, 30, COLOR, ft_itoa(par->moves));
	par->moves++;
}

void	move_player(t_params *par, int x, int y)
{
	if (par->map[par->p_y + y][par->p_x + x] == '1')
		return ;
	if (par->map[par->p_y + y][par->p_x + x] == 'C')
	{
		par->map[par->p_y + y][par->p_x + x] = '0';
		print_img(par, GROUND, (par->p_x + x) * 64, (par->p_y + y) * 64);
		par->score++;
	}
	if (par->map[par->p_y + y][par->p_x + x] == 'E')
	{
		if (par->collect == par->score)
			par->won = 1;
		else
			return ;
	}
	count_moves(par);
	print_img(par, GROUND, par->p_x * 64, par->p_y * 64);
	par->p_x = par->p_x + x;
	par->p_y = par->p_y + y;
}
