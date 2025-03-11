###############
## VARIABLES ##
###############

NAME = checker
CC = cc
CCFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g
CC_COMPILER_CALL = $(CC) $(CCFLAGS) 
RM = rm -f
HEADER = ./push_swap_bonus.h

###################
#### MANDATORY ####
###################

SRCS = ./push_swap_bonus.c ./print_error_bonus.c ./check_input_bonus.c ./ft_atol_bonus.c\
	   ./linked_list/linked_list_utils_bonus.c ./linked_list/check_list_bonus.c ./linked_list/init_list_bonus.c\
	   ./linked_list/operations_bonus.c ./linked_list/operations2_bonus.c ./linked_list/operations3_bonus.c\
	   ./linked_list/operations_utils_bonus.c ./handle_checker_bonus.c
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
