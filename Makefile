# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/07 22:58:48 by mahautlat         #+#    #+#              #
#    Updated: 2021/06/23 15:02:03 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	./main.c \
		./srcs/checks/check_map_walls.c \
		./srcs/checks/check_minimap.c \
		./srcs/checks/check_elements.c \
		./srcs/render/keyboard_inputs.c \
		./srcs/render/graphics.c \
		./srcs/render/draw.c \
		./srcs/checks/check_minimap_lines.c \
		./srcs/utils/utils0.c \
		./srcs/utils/utils1.c \
		./srcs/utils/utils2.c \
		./srcs/utils/utils3.c \
		./srcs/struct/exits/exits0.c \
		./srcs/struct/exits/exits1.c \
		./srcs/struct/collectibles/collectibles0.c \
		./srcs/struct/collectibles/collectibles1.c \
		./srcs/struct/collectibles/collectibles2.c \
		./srcs/struct/player/player0.c \
		./srcs/struct/data/data.c \
		./srcs/struct/mem/mem0.c \
		./srcs/error_handling/error0.c \
		./srcs/error_handling/error1.c \
		./srcs/free/free.c \

OBJS 		= ${SRCS:.c=.o}

UNAME		:= $(shell uname)

PATH_MLX	= mlx
L_SOLONG	= libsolong.a
CC 			= gcc -g
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
NAME		= so_long
LIB			= libso_long.a

FLAGS= -Imlx -Lmlx -lmlx -lm -lbsd -lXext -lX11 -Wl,-rpath=./bass/,-rpath=./mlx/,-rpath=./delay/
LINUX = true

all: 		${NAME}

.c.o:
			${CC} ${CFLAGS} -Imlx -Ibass -c $< -o ${<:.c=.o}

${LIB}:		$(OBJS)
			ar -rc $(NAME) $(OBJS)

$(NAME): 	${LIB} $(OBJS_DEFAULT)
			make -C $(PATH_MLX)
			${CC} $(CFLAGS) -o $(NAME) $(OBJS) $(FLAGS)

clean:
			${RM} ${OBJS}

fclean: 	clean
			${RM} ${NAME}

re: 		fclean all

.PHONY:		all clean fclean re