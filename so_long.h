/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 23:11:17 by pharmund          #+#    #+#             */
/*   Updated: 2022/02/12 17:00:19 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "mlx/mlx.h"
# include <stdlib.h>

# define BUFFER_SIZE 1 

# define A 0
# define S 1
# define D 2
# define W 13
# define ESC 53

# define KEYPRESS 2
# define KEYEXIT 17

# define WALLS "./images/wall.xpm"
# define GROUND "./images/ground.xpm"
# define COLLECTABLE "./images/collectable.xpm"
# define PLAYER "./images/player.xpm"
# define EXIT "./images/exit.xpm"

# define COLOR 0xFFFF00

typedef struct s_params{
	char	**map;
	size_t	width;
	size_t	height;
	void	*mlx;
	void	*wind;
	size_t	p_x;
	size_t	p_y;
	int		collect;
	int		score;
	int		moves;
	int		won;

}		t_params;

char	*ft_strjoin(char *s1, char *s2);
void	read_map(char *map_file, char **str);
void	check_map(t_params *par, char *map_file);
void	check_empty_line(t_params *par, char **str);
void	cleanerit(char **extra);
void	check_name(char *map_file);
void	check_walls(t_params *par);
void	check_walls_line(char **extra, t_params *par);
void	check_line(char **s, t_params *par);
void	error(char *str);
void	print_img(t_params *par, char *placement, int x, int y);
int		render_const_frame(t_params *par);
void	set_values(t_params *par);
void	move_player(t_params *par, int x, int y);
int		press_key(int keycode, t_params *par);
void	hooks(t_params *par);
int		render_next_frame(t_params *par);
int		gameover(t_params *par);
void	count_moves(t_params *par);
void	check_line_2(char c, int **doub);
int		count_lines(char **str);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
char	*ft_strtrim(char const *s1, char const *set);
void	*ft_calloc(size_t count, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif
