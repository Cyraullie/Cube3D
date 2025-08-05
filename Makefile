NAME = cub3D

CC = cc
CFLAGS = -Wall -Werror -Wextra -g -MMD -MP

SRCDIR = srcs/
OBJDIR = objs/
INCDIR = includes/

SRCS = $(shell find $(SRCDIR) -type f -name "*.c")
OBJS = $(SRCS:$(SRCDIR)%.c=$(OBJDIR)%.o)
DEPS = $(OBJS:.o=.d)

LIBFTDIR = libft/
MLXDIR = minilibx/

LIBFT = $(LIBFTDIR)/libft.a
MLX = $(MLXDIR)libmlx.a

MLX_FLAGS = -L$(MLXDIR) -lmlx -lXext -lX11

GREEN = \033[1;32m
RESET = \033[0m

all: header $(NAME)

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
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFTDIR) -lft -L$(MLXDIR) -lmlx -lXext -lX11 -lm -lbsd -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(MLX):
	$(MAKE) -C $(MLXDIR)

clean:
	@rm -rf $(OBJDIR)
	@$(MAKE) clean -C $(LIBFTDIR)
	@$(MAKE) clean -C $(MLXDIR)

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFTDIR)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re