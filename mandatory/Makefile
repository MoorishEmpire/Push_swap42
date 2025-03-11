###############
## VARIABLES ##
###############

NAME = push_swap
CC = cc
CCFLAGS = -Wall -Werror -Wextra -fsanitize=address -g
CC_COMPILER_CALL = $(CC) $(CCFLAGS) 
RM = rm -f
HEADER = ./push_swap.h

###################
#### MANDATORY ####
###################

SRCS = ./push_swap.c ./print_error.c ./check_input.c ./ft_atol.c ./linked_list/linked_list_utils.c\
	  ./linked_list/check_list.c ./linked_list/init_list.c ./linked_list/operations.c\
	  ./linked_list/operations2.c ./linked_list/operations3.c ./linked_list/operations_utils.c\
	  ./best_move_algo/best_move.c ./best_move_algo/simple_sort.c ./best_move_algo/sort_algo.c\
	  ./best_move_algo/handle_sort.c ./best_move_algo/simple_sort_utils.c ./best_move_algo/sort_algo_utils.c
OBJS = $(SRCS:.c=.o)

#############
## TARGETS ##
#############

all : ../$(NAME)

../$(NAME) : $(OBJS) $(HEADER)
	$(emo)
	@make -C libft/
	@$(CC) $(CCFLAGS) $(OBJS) libft/libft.a  -o ../$(NAME)
	@echo "\033[0;32m✅ Compilation successful!\033[0m"

%.o : %.c $(HEADER)
	@$(CC) $(CCFLAGS) -c $< -o $@

clean : 
	@make clean -C libft/
	@$(RM) $(OBJS)
	@echo "\033[0;33m🧹 Cleaned object files.\033[0m"

fclean : clean 
	@make fclean -C libft/
	@$(RM) $(NAME)
	@echo "\033[0;33m🧹 Fully cleaned project.\033[0m"

re : fclean all 

.PHONY : all clean fclean re 

define emo
@echo "\033[0;91m"
@echo "\t██████╗ ██╗   ██╗███████╗██╗  ██╗        ███████╗██╗    ██╗ █████╗ ██████╗ "
@echo "\t██╔══██╗██║   ██║██╔════╝██║  ██║        ██╔════╝██║    ██║██╔══██╗██╔══██╗"
@echo "\t██████╔╝██║   ██║███████╗███████║        ███████╗██║ █╗ ██║███████║██████╔╝"
@echo "\t██╔═══╝ ██║   ██║╚════██║██╔══██║        ╚════██║██║███╗██║██╔══██║██╔═══╝ "
@echo "\t██║     ╚██████╔╝███████║██║  ██║███████╗███████║╚███╔███╔╝██║  ██║██║   "
@echo "\t╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝ "
@echo "\033[0m"
@echo "\033[0;32m"
@echo "\t   ____                     _                           _    "
@echo "\t  | __ ) _   _    __ _ ___ | |      _ __ ___   ___  ___| |_  "
@echo "\t  |  _ \| | | |  / _\`|/ _ \  |_____| '\''_  \\ / _ \/ __| __| "
@echo "\t  | |_) | |_| | | (_| |  __/ |_____| | | | | | (_) \__ \ |_  "
@echo "\t  |____/ \__, |  \__,_|\___|_|     |_| |_| |_|\___/|___/\__| "
@echo "\t         |___/                                               "
@echo "\033[0m"
@echo "\033[0;33m" 
@echo "\t  _ ____________    __  __ ___ ___  "
@echo "\t / |__ /__ /__  |  |  \/  | __|   \ "
@echo "\t | ||_ \|_ \ / /   | |\/| | _|| |) |"
@echo "\t |_|___/___//_/    |_|  |_|___|___/ "
@echo "\033[0m"
endef
