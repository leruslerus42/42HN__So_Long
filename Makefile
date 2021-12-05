CC = gcc

NAME = so_long.a

FLAGS = -Wall -Wextra -Werror

MLX = libmlx.a -framework OpenGL -framework AppKit

OBJ := $(*.o)

GAME =	./src/ft_map_printer.c \
		./src/ft_map_reader.c \
		./src/ft_movements.c \

UTILS =	./src/ft_get_next_line.c \
		./src/ft_error_management.c \
		
		
OTHER =	./src/ft_initialization.c \
		./src/ft_map_update.c \

SRC =	./src/main.c \
		
BONUS =	./src/bonus/ft_enemy.c \
		./src/bonus/ft_initialization_bonus.c \
		./src/bonus/ft_map_update_bonus.c \

LIBFTPATH =	./libft/

LIBFT =	libft.a

all: $(NAME)

$(NAME): fclean
	make -C ${LIBFTPATH}
	mv ${LIBFTPATH}${LIBFT} ${LIBFT}
	$(CC) $(FLAGS) ${SRC} ${GAME} ${UTILS} ${OTHER} ${BONUS} ${LIBFT} ${MLX} -o ${NAME} -D BONUS=0

	
clean:
	rm -f ./libft/*.o
	rm -f *.o

bonus: fclean
	make -C ${LIBFTPATH}
	mv ${LIBFTPATH}${LIBFT} ${LIBFT}
	$(CC) $(FLAGS) ${SRC} ${GAME} ${UTILS} ${OTHER} ${BONUS} ${LIBFT} ${MLX} -o ${NAME} -D BONUS=1

	
fclean: clean
	rm -f ${LIBFT} ${OBJ} $(NAME)

re: fclean $(NAME)