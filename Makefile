MAKEFLAGS += --no-print-directory

NAME = so_long

CC = gcc
FLAGS = -Wextra -Werror -Wall -g
# -I/. -Iminilibx

LIBFT = libft/libft.a

MINI_LIBX = mini_libx/libmlx_Linux.a

OBJDIR := obj

SRCS = so_long.c\
	map_errors1.c map_errors2.c map_read.c map_utils.c map_load.c map_parsing.c\
	textures.c close_game.c\
	keys_handling.c movements.c enemy.c\
	# test.c\

OBJS := $(SRCS:%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(MINI_LIBX) $(OBJS) $(LIBFT) 
	@echo "🔧 Compiling files... 🔨\n🛠️  Done. 🛠️"
	@$(CC) $(FLAGS) $(MINI_LIBX) $(OBJS) $(LIBFT) -Lmini_libx -lmlx -lX11 -lXext -lm -o $@

$(LIBFT):
	@make -C libft

$(MINI_LIBX):
	@make --silent -C mini_libx
	@echo "🔧 Compiling mini_libx.......\n"

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)
	@make clean -C ./libft
	@make clean --silent -C ./mini_libx

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C ./libft
	@echo "🧹 Cleaning everything... 🧹"

re: fclean all

.PHONY: all clean fclean re