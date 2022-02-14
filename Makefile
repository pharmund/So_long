# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 22:40:06 by pharmund          #+#    #+#              #
#    Updated: 2022/02/09 22:16:21 by pharmund         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

HEADER = so_long.h

SRC = so_long.c check_map.c check_map2.c check_map3.c utils.c utils2.c utils3.c utils4.c game.c rendering.c

MLX = ./mlx/libmlx.a

OBJ = ${SRC:.c=.o}

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

MFLAGS = -framework OpenGL -framework AppKit

RM		= rm -f

all:		${NAME}

${NAME}:	${MLX} ${OBJ} ${HEADER}
			${CC} ${cFLAGS} ${MFLAGS} ${OBJ} ${LIBFT} ${MLX} -o ${NAME}

${MLX}:		
			make -C ./mlx

%.o : %.c
			${CC} ${CFLAGS} -c $< -o $@

clean:	
			${RM} ${OBJ}
			make -C ./mlx clean

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re