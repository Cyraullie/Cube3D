NAME = cub3D

CC = cc

CFLAGS = -Wall -Werror -Wextra  -g

SRCDIR = srcs/
OBJDIR = objs/

SRCS =  $(addprefix $(SRCDIR), main.c parsing.c)

LIBFT_PATH = libft

LIBFT = $(LIBFT_PATH)/libft.a

OBJS = $(SRCS:$(SRCDIR)%.c=$(OBJDIR)%.o)

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
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)


$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

clean:
	@rm -rf $(OBJDIR)
	@$(MAKE) clean -C $(LIBFT_PATH)

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re
