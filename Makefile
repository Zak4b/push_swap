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
		utils.c \
		push.c \
		swap.c \
		rotate.c \
		reverse_rotate.c \
		sort.c \
		group_sort.c \
		groups.c

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

test_input: $(NAME)
	@ARG="-8 -12"; ./push_swap $$ARG

test2: $(NAME)
	@ARG="-8 -12"; ./push_swap $$ARG | ./.tools/checker_linux $$ARG
	@ARG="4 21"; ./push_swap $$ARG | ./.tools/checker_linux $$ARG
test3: $(NAME)
	@ARG="1 2 3"; ./push_swap $$ARG | ./.tools/checker_linux $$ARG
	@ARG="3 2 1"; ./push_swap $$ARG | ./.tools/checker_linux $$ARG
	@ARG="1 3 2"; ./push_swap $$ARG | ./.tools/checker_linux $$ARG
test4: $(NAME)
	@ARG="4 2 1 3"; ./push_swap $$ARG | ./.tools/checker_linux $$ARG
	@ARG="1 2 4 3"; ./push_swap $$ARG | ./.tools/checker_linux $$ARG
test5: $(NAME)
	@ARG="5 4 2 1 3"; ./push_swap $$ARG | ./.tools/checker_linux $$ARG
	@ARG="1 2 5 4 3"; ./push_swap $$ARG | ./.tools/checker_linux $$ARG
test100: $(NAME)
	@ARG="$(shell seq 100 | shuf | tr '\n' ' ')"; ./push_swap $$ARG | ./.tools/checker_linux $$ARG
test500: $(NAME)
	@ARG="$(shell seq 500  | shuf | tr '\n' ' ')"; ./push_swap $$ARG | ./.tools/checker_linux $$ARG
test: test2 test3 test4 test5 test100
	@for i in $$(seq 10); do make -s test100; done
	@for i in $$(seq 10); do make -s test500; done

.PHONY: all clean fclean re
