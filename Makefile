NAME = push_swap
CHECKER_PATH = ./.tools/checker_linux

GREEN = \033[32m
RED = \033[31m
YELLOW = \033[0;33m
RESET = \033[0m

LIBFT = libft/libft.a

FLAGS = -Wall -Wextra -Werror -g

SOURCES = \
        main.c \
		stack.c \
		stack2.c \
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
	cc $(FLAGS) -o checker -D DISPLAY_INSTRUCTIONS=0 $(BONUS_OBJS) $(LIBFT)

test_input: $(NAME)
	@ARG="-8 -12"; ./$(NAME) $$ARG

test2: $(NAME)
	@ARG="-8 -12"; ./$(NAME) $$ARG | $(CHECKER_PATH) $$ARG
	@ARG="4 21"; ./$(NAME) $$ARG | $(CHECKER_PATH) $$ARG
test3: $(NAME)
	@ARG="1 2 3"; ./$(NAME) $$ARG | $(CHECKER_PATH) $$ARG
	@ARG="3 2 1"; ./$(NAME) $$ARG | $(CHECKER_PATH) $$ARG
	@ARG="1 3 2"; ./$(NAME) $$ARG | $(CHECKER_PATH) $$ARG
test4: $(NAME)
	@ARG="4 2 1 3"; ./$(NAME) $$ARG | $(CHECKER_PATH) $$ARG
	@ARG="1 2 4 3"; ./$(NAME) $$ARG | $(CHECKER_PATH) $$ARG
test5: $(NAME)
	@ARG="5 4 2 1 3"; ./$(NAME) $$ARG | $(CHECKER_PATH) $$ARG
	@ARG="1 2 5 4 3"; ./$(NAME) $$ARG | $(CHECKER_PATH) $$ARG
run_tests: $(NAME)
	@echo "$(YELLOW)Testing $(SIZE) values$(RESET)"
	@for i in $$(seq $(COUNT)); do \
		ARG="`seq $(SIZE) | shuf | tr '\n' ' '`"; \
		result=$$(./$(NAME) $$ARG | $(CHECKER_PATH) $$ARG); \
		if [ "$$result" = "OK" ]; then \
			echo -n "$(GREEN)$$result $(RESET)"; \
		else \
			echo -n "$(RED)$$result $(RESET)"; \
		fi; \
	done; echo

run_bench: $(NAME)
	@echo "$(YELLOW)Performance on $(SIZE) values$(RESET)"
	@total=0; max=0; min=999999; \
	for i in $$(seq $(COUNT)); do \
		ARG="`seq $(SIZE) | shuf | tr '\n' ' '`"; \
		lines=$$(./$(NAME) $$ARG | wc -l); \
		total=$$((total + lines)); \
		if [ $$lines -gt $$max ]; then max=$$lines; fi; \
		if [ $$lines -lt $$min ]; then min=$$lines; fi; \
	done; \
	average=$$((total / $(COUNT))); \
	echo "Minimum: $$min lines"; \
	echo "Average: $$average lines"; \
	echo "Maximum: $$max lines";

test: $(NAME) test2 test3 test4 test5
	@make -s run_tests SIZE=100 COUNT=10
	@make -s run_tests SIZE=500 COUNT=10
bench:
	@make -s run_bench SIZE=100 COUNT=100
	@make -s run_bench SIZE=500 COUNT=50

.PHONY: all clean fclean re
