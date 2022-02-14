/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 23:18:18 by pharmund          #+#    #+#             */
/*   Updated: 2022/02/14 12:59:24 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_walls_line(char **extra, t_params *par)
{
	size_t	i;

	i = 1;
	while (extra[i] && i != par -> height - 1)
	{
		if (extra[i][0] != '1' || extra[i][par -> width - 1] != '1')
			error("walls are not '1'");
		i++;
	}
}

void	check_line_2(char c, int **doub)
{
	if (c != '1' && c != '0' && c != 'C'
		&& c != 'E' && c != 'P')
		error("wrong characters");
	if (c == 'E')
		(*doub)[0]++;
	if (c == 'P')
		(*doub)[1]++;
	if (c == 'C')
		(*doub)[2]++;
}

void	check_line(char **s, t_params *par)
{
	size_t	i;
	int		*doub;
	size_t	j;

	doub = ft_calloc (3, sizeof(int));
	if (!doub)
		error("error calloc");
	i = 1;
	while (s[i] && i != par -> height - 1)
	{
		j = 0;
		while (s[i][j] != '\0')
		{
			check_line_2(s[i][j], &doub);
			j++;
		}
		i++;
	}
	if (doub[0] < 1 || doub[1] != 1 || doub[2] < 1)
		error("error with characters");
	free(doub);
}

void	check_walls(t_params *par)
{
	char	**extra;
	int		i;

	i = 1;
	extra = par -> map;
	par -> width = ft_strlen(extra[0]);
	while (extra[i])
	{
		if (par -> width != ft_strlen(extra[i]))
			error("not rectangular map");
		i++;
	}
	i = 0;
	while (extra[0][i] != '\0' && extra[par -> height - 1][i] != '\0')
	{
		if (extra[0][i] != '1' || extra[par -> height - 1][i] != '1')
			error("first or/and last line isn't walls");
		i++;
	}
	check_line(extra, par);
	check_walls_line(extra, par);
}
