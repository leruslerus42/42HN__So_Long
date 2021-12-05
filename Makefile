# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrajaobe <rrajaobe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/05 22:00:06 by rrajaobe          #+#    #+#              #
#    Updated: 2021/12/05 22:05:16 by rrajaobe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = so_long

FLAGS = -Wall -Wextra -Werror

MLX = libmlx.a -framework OpenGL -framework AppKit

LIBFTPATH =	./libft/

LIBFT =	libft.a

OBJ := $(*.o)

SRC =		main.c \

MAP =		./src/ft_map_printer.c \
			./src/ft_map_reader.c \
			./src/ft_map_update.c \

ACTION =	./src/ft_initialization.c \
			./src/ft_movements.c \
			./src/ft_enemy.c \
			
UTILS =		./src/ft_get_next_line.c \
			./src/ft_error_management.c \

all: $(NAME)

$(NAME): fclean
	make -C ${LIBFTPATH}
	mv ${LIBFTPATH}${LIBFT} ${LIBFT}
	$(CC) $(FLAGS) ${LIBFT} ${MLX} ${SRC} ${MAP} ${ACTION} ${UTILS} -o ${NAME} -D BONUS=0

bonus: 
	make -C ${LIBFTPATH}
	mv ${LIBFTPATH}${LIBFT} ${LIBFT}
	$(CC) $(FLAGS) ${LIBFT} ${MLX} ${SRC} ${MAP} ${ACTION} ${UTILS} -o ${NAME} -D BONUS=1

clean:
	rm -f ./libft/*.o
	rm -f *.o
	
fclean: clean
	rm -f ${LIBFT} ${OBJ} $(NAME)

re: fclean $(NAME)