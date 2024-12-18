NAME = push_swap

GREEN = \033[32m
RED = \033[31m
RESET = \033[0m

LIBFT = libft/libft.a

FLAGS = -Wall -Wextra -Werror -g

SOURCES = \
        main.c \
		list.c \
		list2.c \
		push.c \
		swap.c \
		rotate.c \
		reverse_rotate.c

SOURCES = \
        main.c \
		list.c \
		list2.c \
		push.c \
		swap.c \
		rotate.c \
		reverse_rotate.c

BONUS_SOURCES = $(filter-out main.c, $(SOURCES)) checker.c

OBJDIR = obj
OBJS = $(addprefix $(OBJDIR)/, $(SOURCES:.c=.o))
BONUS_OBJS = $(addprefix $(OBJDIR)/, $(BONUS_SOURCES:.c=.o))

$(NAME): $(LIBFT) $(OBJS)
	@echo "$(GREEN)Compiling $(NAME)...$(RESET)"
	@cc $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT)
	@echo "$(GREEN)Compilation finished successfully!$(RESET)"

all: $(NAME) bonus

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	@echo "$(GREEN)Compiling $<...$(RESET)"
	@cc $(FLAGS) -Ilibft -c $< -o $@

$(LIBFT):
	@echo "$(GREEN)Building Libft...$(RESET)"
	@make -s -C libft all

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "$(RED)Cleaning all...$(RESET)"
	@rm -f $(NAME)
	@make -s -C libft fclean

re: fclean $(NAME)

bonus: $(LIBFT) $(BONUS_OBJS)
	@cc $(FLAGS) -o checker $(BONUS_OBJS) $(LIBFT)

.PHONY: all clean fclean re
