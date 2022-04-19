NAME := fractol

SRC := main.c draw.c init.c utils.c zoom.c		\
	some_libft.c tricorn.c color.c mandelbrot.c	\
	key.c mouse.c julia.c

OBJS := $(SRC:.c=.o)

FLAG := -lm -lbsd -lXext -lX11 \
	-fsanitize=address

CFLAG := -Wall -Wextra -Werror

all: $(NAME)

bonus: all

$(NAME): $(OBJS)
	make --no-print-directory -C ./minilibx-linux
	clang $(OBJS) -o $(NAME) $(CFLAG) minilibx-linux/libmlx_Linux.a $(FLAG)

%.o: %.c
	clang $(CFLAG) -c $< -o $@

mandelbrot:
	./fractol mandelbrot

tricorn:
	./fractol tricorn

julia1:
	./fractol julia -0.835 -0.2321
julia2:
	./fractol julia 0.285 0
julia3:
	./fractol julia 0.285 0.01
julia4:
	./fractol julia 0.45 0.1428 
julia5:
	./fractol julia -0.70176 -0.3842

norminette:
	norminette *.c && norminette *.h

setDebian:
	sudo apt-get update && sudo apt-get upgrade  && sudo apt-get install gcc make xorg libxext-dev libbsd-dev

.PHONY: clean fclean minilibx_clean re all

clean:
	rm -f $(OBJS)

fclean: clean minilibx_clean
	rm -f $(NAME)

minilibx_clean:
	make clean -C ./minilibx-linux

re: fclean all
