/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:56:44 by pharmund          #+#    #+#             */
/*   Updated: 2022/02/12 17:00:54 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *str)
{
	ft_putstr_fd("Error \n", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

void	cleanerit(char **extra)
{
	int	i;

	i = 0;
	while (extra[i])
	{
		free(extra[i]);
		i++;
	}
	free(extra);
}

int	count_lines(char **str)
{
	int	j;
	int	count;

	j = 0;
	count = 0;
	while ((*str)[j] != '\0')
	{
		if ((*str)[j] == '\n')
			count++;
		j++;
	}
	return (count);
}

void	check_empty_line(t_params *par, char **str)
{
	int		i;
	int		count;
	char	**extra;

	i = 0;
	if (!(*str))
		error("no map");
	extra = ft_split(*str, '\n');
	while (extra[i])
		i++;
	count = count_lines(str);
	if (i == count + 1)
	{
		par -> map = extra;
		par -> height = i;
	}
	else
	{
		cleanerit(extra);
		error("empty lines");
	}
}
