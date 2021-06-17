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

SRCS = ./srcs/parsing/handle_2d_map.c \
		./srcs/checks/check_map_definition.c \
		./srcs/checks/check_map_walls.c \
		./srcs/checks/check_minimap.c \
		./srcs/checks/check_player.c \
		./srcs/render/keyboard_inputs.c \
		./srcs/render/player.c \
		./srcs/render/draw.c \
		./srcs/render/graphics.c \
		./srcs/checks/check_minimap_lines.c \
		./srcs/utils/utils0.c \
		./srcs/utils/utils1.c \
		./srcs/utils/utils2.c \
		./srcs/utils/utils3.c \
		./srcs/free/free.c \
		./srcs/struct/exits/exits0.c \
		./srcs/struct/collectibles/collectibles0.c \
		./srcs/struct/player/player0.c \
		./srcs/struct/map/map.c \
		./srcs/struct/data/data.c \
		./srcs/struct/mem/mem0.c \
		./srcs/error_handling/error0.c \
		./main.c \
		./srcs/render/graphics.c \
		./srcs/print/print.c \



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
