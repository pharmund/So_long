/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 11:38:50 by pharmund          #+#    #+#             */
/*   Updated: 2022/02/12 15:30:05 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	read_map(char *map_file, char **str)
{
	char	*buff;
	int		fd;
	int		red;
	int		count;

	buff = malloc(sizeof(char) * BUFFER_SIZE);
	fd = open(map_file, O_RDONLY);
	*str = NULL;
	count = 0;
	if (fd == -1)
		error("error to open");
	red = read(fd, buff, BUFFER_SIZE);
	if (red == -1)
		error("Can't read map");
	while (red > 0)
	{
		*str = ft_strjoin(*str, buff);
		red = read(fd, buff, BUFFER_SIZE);
	}
	*str = ft_strtrim(*str, "\n");
	free (buff);
}

void	check_name(char *map_file)
{
	int	size;

	size = ft_strlen(map_file);
	if (ft_strncmp(&map_file[size - 4], ".ber\0", 5))
		error("incorrect name");
}

void	check_map(t_params *par, char *map_file)
{
	char	*str;

	check_name(map_file);
	read_map(map_file, &str);
	(void) par;
	check_empty_line(par, &str);
	free(str);
	check_walls(par);
	set_values(par);
}
