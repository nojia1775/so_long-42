CC = cc

CFLAGS = -Wall -Wextra -Werror

OBJS_DIR = obj

SRCS = src/main.c \
       src/free_error.c \
       src/extract_map.c \
       src/parsing.c \
       src/utils.c \
       src/goodway.c \
       src/errors.c \
       src/init_verif.c \
       src/display_map.c \
       src/files.c \
       src/chose_asset.c \
       src/first_last.c

OBJS = $(patsubst src/%.c, $(OBJS_DIR)/%.o, $(SRCS))

NAME = so_long

$(NAME): $(OBJS)
	@make -C LIBFT/
	@make -C FT_PRINTF/
	@make -C minilibx-linux/
	$(CC) $(CFLAGS) $^ -o $@ minilibx-linux/libmlx_Linux.a LIBFT/libft.a FT_PRINTF/libftprintf.a -lXext -lX11 -lm -lz -g3

$(OBJS_DIR)/%.o: src/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

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
