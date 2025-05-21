NAME = cub3D

CC = cc

CFLAGS = -Wall -Werror -Wextra  -g

SRCDIR = srcs/
OBJDIR = objs/

SRCS = $(shell find $(SRCDIR) -type f -name "*.c")

LIBFTDIR	= libft/
MLXDIR		= minilibx/

LIBFT = $(LIBFTDIR)/libft.a
MLX = $(MLXDIR)libmlx.a

MLX_FLAGS = -L$(MLXDIR) -lmlx -lXext -lX11

OBJS = $(SRCS:$(SRCDIR)%.c=$(OBJDIR)%.o)

GREEN = \033[1;32m
RESET = \033[0m

all: header $(NAME) $(LIBFT) $(MLX)

header:
	@echo "$(GREEN)"
	@echo "   ______      __   _____ ____ "
	@echo "  / ____/_  __/ /_ |__  // __ \\"
	@echo " / /   / / / / __ \ /_ </ / / /"
	@echo "/ /___/ /_/ / /_/ /__/ / /_/ / "
	@echo "\____/\__,_/_.___/____/_____/  "
	@echo "                               "
	@echo "$(RESET)"

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT):
	make -C $(LIBFTDIR)

$(MLX):
	make -C $(MLXDIR)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) -L$(MLXDIR) -lmlx -L$(LIBFTDIR) -lft -lXext -lX11 -lm -lbsd -o $(NAME)

clean:
	@rm -rf $(OBJDIR)
	@$(MAKE) clean -C $(LIBFTDIR)
	@$(MAKE) clean -C $(MLXDIR)

fclean: clean
	@rm -f $(NAME)
	make -C $(MLXDIR) clean
	make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re
