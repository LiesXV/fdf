# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 13:10:41 by ibenhaim          #+#    #+#              #
#    Updated: 2023/01/13 12:49:21 by ibenhaim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf
FLAGS		=	-Wall -Werror -Wextra #-fsanitize=address -g3

HEADER		=	fdf.h
SRCS		=	main.c \
				parsing.c \
				fdf_utils.c \
				map.c \
				events.c

INCLUDES	=	includes/
DIR_SRCS	= 	srcs/
DIR_LIB		=	libn/
DIR_OBJS	=	objs/
MLX			=	mlx/
LIBFT		=	$(DIR_LIB)libft.a

SRC 		= 	$(addprefix ${DIR_SRCS}, ${SRCS})

OBJS		= 	${SRC:.c=.o}

LFTNAME		= 	libft.a

%.o:%.c ${INCLUDES}${HEADER} ${MLX}mlx.h ${DIR_LIB}libft.h
				${CC} ${FLAGS} -I mlx/ -c $< -o $@

${NAME}: 		$(LIBFT) mlx ${OBJS}
				${CC} ${FLAGS} ${OBJS} ${DIR_LIB}${LFTNAME} -lm -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME}

all : ${NAME}

$(LIBFT) :		FORCE
				${MAKE} -C ${DIR_LIB}

mlx :
				${MAKE} -C ${MLX}

clean:
				rm -f ${OBJS} 
				${MAKE} -C ${DIR_LIB} clean
				${MAKE} -C ${MLX} clean

fclean:	clean
				rm -f ${NAME}
				${MAKE} -C ${DIR_LIB} fclean

re: fclean all

FORCE:

.PHONY:	all clean fclean re libft mlx FORCE