# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anvacca <anvacca@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/10 10:01:19 by anvacca           #+#    #+#              #
#    Updated: 2024/09/17 09:50:18 by anvacca          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Executable
EXE			=	so_long

# Files
SRC			=	./src/main.c \

SRC_UTILS	=	./src/utils/exit_function.c \
				./src/utils/ft_strcmp.c \
				./src/utils/ft_strlen.c \
				./src/utils/ft_strdup.c \

SRC_MAP		=	./src/map/init_map.c \
				./src/map/gnl/get_next_line.c \
				./src/map/gnl/get_next_line_utils.c \
				./src/map/free_map.c \

SRC_PARSING	=	./src/parsing/is_char.c \
				./src/parsing/does_exist.c \
				./src/parsing/is_rectangle.c \
				./src/parsing/is_closed.c \
				./src/parsing/floodfill_algo.c \

SRC_GAME	=	./src/game/key_binds.c \
				./src/game/player_move.c \

SRC_DISPLAY	=	./src/display/close_display.c \
				./src/display/display_game.c \
				./src/display/init_sprite.c \
				./src/display/init_display.c \


SOURCES		=	${SRC} ${SRC_UTILS} ${SRC_MAP} ${SRC_PARSING} ${SRC_GAME} ${SRC_DISPLAY}
OBJECTS		=	${SOURCES:%.c=obj/%.o}

# Libraries
MINILIBX	=	./includes/mlx_linux

# Variables
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -fsanitize=address -g
RM			=	rm -rf

# Makefile
all:		${EXE}

${EXE}:		${OBJECTS}
			@${MAKE} -C ${MINILIBX} > /dev/null 2>&1
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
