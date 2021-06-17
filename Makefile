# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/07 22:58:48 by mahautlat         #+#    #+#              #
#    Updated: 2021/04/23 11:18:31 by mahautlatin      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Penser a compiler la libft lors de la compilation du reste !
#test:
#    gcc main.c -Lminilibx-linux/ -lmlx_Linux -lX11 -lXext -lm

#attention aux regles pour compiler la lib minilibx
#-Llmlx_Linux  -lmlx -lXext –lX11

SRCS = ./parsing/handle_2d_map.c \
		./checks/check_map_definition.c \
		./checks/check_map_walls.c \
		./checks/check_minimap.c \
		./checks/check_player.c \
		./checks/check_minimap_lines.c \
		./struct/struct.c \
		./utils_mlx/colors.c \
		./utils/utils0.c \
		./utils/utils1.c \
		./utils/utils2.c \
		./utils/utils3.c \
		./main.c \
		./render/graphics.c \
		./render/keyboard_inputs.c \
		./render/player.c \
		./render/draw.c \
		./free/free.c \
		./error_handling/error0.c \

OBJS = ${SRCS:.c=.o}

NAME = libsolong.a
CC = gcc -g -fsanitize=address
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
PROG = so_long

all: 		${NAME}

$(NAME):	$(OBJS)
			ar -rc $(NAME) $(OBJS)
libft:

clean:
			${RM} ${OBJS}

fclean: 	clean
			${RM} ${NAME}

re: 		fclean all

test: 		clean ${NAME}
			${CC} $(CFLAGS) -o $(PROG) $(OBJS)  -L. ${NAME} -Lmlx -lmlx -framework OpenGL -framework AppKit | cat -e

.PHONY:		all clean fclean re
