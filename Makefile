CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = src/main.c \
       src/parsing.c \
       src/free_error.c

OBJS = $(SRCS:.c=.o)

NAME = so_long

$(NAME): $(OBJS)
	@make -C LIBFT/
	@make -C FT_PRINTF/
	@make -C minilibx-linux/
	$(CC) $(CFLAGS) $^ -o $@ minilibx-linux/libmlx_Linux.a LIBFT/libft.a FT_PRINTF/libftprintf.a -lXext -lX11 -lm -lz -g3

all: $(NAME)

clean:
	@make clean -C minilibx-linux/
	@make clean -C FT_PRINTF/
	@make clean -C LIBFT/
	rm -f $(OBJS)

fclean: clean
	@make fclean -C FT_PRINTF/
	@make fclean -C LIBFT/
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
