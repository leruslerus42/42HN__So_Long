CC = gcc

NAME = so_long.a

FLAGS = -Wall -Wextra -Werror

MLX = -lmlx -Lmlx -framework OpenGL -framework AppKit

SRC =	so_long.c \
		get_next_line.c \
		help_functions.c \
		map_reader.c	\
		movements.c 	\


#[minilibx] add these 4 lines to the Makefile (of minilibx)  if you don't wanna see all the warnings every time you compile:
#%.o : %.c 
#    @cc -O2 -w -DSTRINGPUTX11   -c -o $@ $<
#%.o : %.m
#    @cc -O2 -w -DSTRINGPUTX11   -c -o $@ $<

#Sorry my mistake. Slack inserts spaces instead of tabs. You need to put a tab infront of both @ signs instead of 4 spaces
#Btw. to just silence the warnings (but still seeing the full compile process) you can just add a w to the CFLAGS



all: $(NAME)

$(NAME): *.c
	Make -C ./libft
	cp ./libft/libft.a $(NAME)
	$(CC) $(FLAGS) -c $(SRC) 
	ar rc $(NAME) *.o
	$(CC) $(FLAGS) ./mlx/libmlx.a $(MLX) so_long.c -o so_long
	

clean:
	rm -f ./libft/*.o
	rm -f *.o

fclean: clean
	rm -f ./libft/libft.a
	rm -f $(NAME)

re: fclean $(NAME)