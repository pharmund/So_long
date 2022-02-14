/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:12:17 by pharmund          #+#    #+#             */
/*   Updated: 2022/02/09 22:13:46 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_params	par;

	par.moves = 1;
	if (argc != 2)
		error("invalid args");
	check_map(&par, argv[1]);
	par.mlx = mlx_init();
	par.wind = mlx_new_window(par.mlx, par.width * 64,
			par.height * 64, "Ragnarok Online");
	hooks(&par);
	mlx_loop(par.mlx);
	return (0);
}
