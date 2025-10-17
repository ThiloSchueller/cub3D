NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE_DIR) -fsanitize=address -g #-static-libsan
SOURCE_DIR = src
OBJECT_DIR = obj
INCLUDE_DIR = inc
LIBFT = libft/libft.a
MLX_DIR = ./mlx
MLX = $(MLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm
VPATH = $(SOURCE_DIR):$(INCLUDE_DIR)
SOURCES = 	main.c \
			parser.c \
			parser_colours.c \
			parser_helper.c \
			parser_map.c \
			parser_textures.c \
			parser_checker_map.c \
			parser_conditions_map.c \
			render.c \
			hook.c \
			keys_arrows.c \
			keys_wasd.c \
			exit.c \
			minimap.c \
			images.c \
			directions.c \
			calc1.c \
			calc2.c \
			helpers.c \
			small_render.c

HEADERS = cub3D.h
OBJ = $(addprefix $(OBJECT_DIR)/, $(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(MLX_DIR) $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX)
$(LIBFT):
	$(MAKE) -C libft 

$(MLX_DIR):
	@if [ ! -d "$(MLX_DIR)" ];  then    \
		echo "$(Yellow)Downloading MLX42...$(Color_Off)"; \
		git clone https://github.com/codam-coding-college/MLX42.git $(MLX_DIR) && \
		cmake -B $(MLX_DIR)/build -S $(MLX_DIR) && \
		make -C $(MLX_DIR)/build; \
		if [ $$? -ne 0 ]; then \
			echo "$(Red)Error building MLX42$(Color_Off)"; \
			exit 1; \
		fi; \
		echo "$(BGreen)MLX42 installed$(Color_Off)"; \
	else \
		echo "$(BGreen)MLX42 already exists$(Color_Off)"; \
	fi

$(OBJECT_DIR):
	mkdir -p $(OBJECT_DIR)

$(OBJ): $(OBJECT_DIR)/%.o: %.c $(HEADERS) | $(OBJECT_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -rf $(OBJECT_DIR)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)
#rm -rf mlx

re: fclean all

.PHONY: all clean fclean re