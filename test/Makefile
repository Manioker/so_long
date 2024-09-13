# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andi <andi@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/10 10:01:19 by anvacca           #+#    #+#              #
#    Updated: 2024/09/13 17:50:59 by andi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Executable
EXE			=	so_long

# Files
SRC			=	main.c \

SOURCES		=	${SRC}
OBJECTS		=	${SOURCES:%.c=obj/%.o}

# Libraries
MINILIBX	=	mlx_linux

# Variables
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -fsanitize=address -g
RM			=	rm -rf

# Makefile
all:		${EXE}

${EXE}:		${OBJECTS}
			@${MAKE} -C ${MINILIBX}
			@${CC} ${CFLAGS} ${OBJECTS} -L${MINILIBX} -lmlx -lX11 -lXext -lm -o ${EXE} 

obj/%.o:	%.c
			@mkdir -p obj/$(dir $<)
			@${CC} ${CFLAGS} -c $< -o $@

clean:
			@${MAKE} -C ${MINILIBX} clean > /dev/null
			@${RM} obj

fclean:		clean
			@${RM} ${EXE}

re:			fclean all

.PHONY:		all clean fclean re
