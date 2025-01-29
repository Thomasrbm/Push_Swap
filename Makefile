NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
INCLUDES = -I. -I../ft_printf -I../libft

SRC = \
	push_swap_/commands/basics.c \
	push_swap_/commands/basics_2.c \
	push_swap_/commands/commands_1.c \
	push_swap_/commands/commands_2.c \
	push_swap_/parse.c \
	push_swap_/my_sort/my_sort.c \
	push_swap_/my_sort/sort_utils.c \
	push_swap_/my_sort/calculate_cost.c \
	push_swap_/my_sort/exec_rotation.c \
	push_swap_/my_sort/small_sort.c \
	push_swap_/main.c

OBJ_DIR = objects

OBJS = $(SRC:%.c=$(OBJ_DIR)/%.o)

FT_PRINTF_PATH = printf
FT_PRINTF_LIB = $(FT_PRINTF_PATH)/libftprintf.a
LIBFT_PATH = libft
LIBFT_LIB = $(LIBFT_PATH)/libft.a

GREEN = \033[0;32m
RESET = \033[0m

all: $(FT_PRINTF_LIB) $(LIBFT_LIB) $(NAME)

$(NAME): $(OBJS)
	@echo "$(GREEN)creating push_swap$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) \
	$(FT_PRINTF_LIB) $(LIBFT_LIB)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(FT_PRINTF_LIB):
	@echo "Compiling ft_printf library..."
	@make -C $(FT_PRINTF_PATH) -s

$(LIBFT_LIB):
	@echo "Compiling libft library..."
	@make -C $(LIBFT_PATH) -s

clean:
	@echo "Removing objects..."
	@rm -rf $(OBJ_DIR)
	@echo "Cleaning ft_printf..."
	@make -C $(FT_PRINTF_PATH) clean -s
	@echo "Cleaning libft..."
	@make -C $(LIBFT_PATH) clean -s

fclean: clean
	@echo "Removing executable..."
	@rm -f $(NAME) $(BONUS_NAME)
	@echo "Cleaning ft_printf..."
	@make -C $(FT_PRINTF_PATH) fclean -s
	@echo "Cleaning libft..."
	@make -C $(LIBFT_PATH) fclean -s

re: fclean all

.PHONY: all clean fclean re bonus

# ====================== BONUS PART =========================

BONUS_NAME = checker

BONUS_SRCS = \
	$(MANDATORY_NO_MAIN) \
	push_swap_/bonus/checker.c \
	gnl_bonus/get_next_line_bonus.c

MANDATORY_NO_MAIN = \
	push_swap_/commands/basics.c \
	push_swap_/commands/basics_2.c \
	push_swap_/commands/commands_1.c \
	push_swap_/commands/commands_2.c \
	push_swap_/parse.c \
	push_swap_/my_sort/my_sort.c \
	push_swap_/my_sort/sort_utils.c \
	push_swap_/my_sort/calculate_cost.c \
	push_swap_/my_sort/exec_rotation.c \
	push_swap_/my_sort/small_sort.c \
	push_swap_/bonus/init_utils.c


BONUS_OBJS = $(BONUS_SRCS:%.c=$(OBJ_DIR)/%.o)

bonus: $(BONUS_OBJS) $(FT_PRINTF_LIB) $(LIBFT_LIB)
	@echo "$(GREEN)Compiling checker bonus$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -o $(BONUS_NAME) \
	$(BONUS_OBJS) $(FT_PRINTF_LIB) $(LIBFT_LIB)

