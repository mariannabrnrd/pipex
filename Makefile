# file name
NAME = pipex
NAME_BONUS = pipex_bonus

# colorssss
PURPLE = \033[1;35m
LIGHT_CYAN = \033[1;36m
RESET = \033[0m

# directory
LIBFT_DIR 		= 	lib/libft/
PRINTF_DIR 		=	lib/ft_printf/
OBJ_DIR 		= 	obj/

# path to .a files
LIBFT_PATH		=	$(LIBFT_DIR)/libft.a
PRINTF_PATH		=	$(PRINTF_DIR)/libftprintf.a

#compiler and flag
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -I. -I$(LIBFT_DIR) -I$(PRINTF_DIR) -g -gdwarf-4

#file
SOURCES = 	pipex.c \
			utils.c

SOURCES_BONUS = pipex_bonus.c \
				utils_bonus.c \
				utils.c

OBJECTS = $(addprefix $(OBJ_DIR), $(SOURCES:.c=.o))
OBJECTS_BONUS = $(addprefix $(OBJ_DIR), $(SOURCES_BONUS:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT_PATH) $(PRINTF_PATH) $(OBJECTS)
	@$(CC) $(CFLAGS) -o $@ $(OBJECTS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf 
	@echo "$(PURPLE)$(NAME) OK!$(RESET)"

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(LIBFT_PATH) $(PRINTF_PATH) $(OBJECTS_BONUS)
	@$(CC) $(CFLAGS) -o $@ $(OBJECTS_BONUS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf 
	@echo "$(PURPLE)$(NAME_BONUS) OK!$(RESET)"

$(LIBFT_PATH):
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)

$(PRINTF_PATH):
	@$(MAKE) --no-print-directory -C $(PRINTF_DIR)

$(OBJ_DIR)%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	


clean:
		@$(RM) -r $(OBJ_DIR)
		@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean
		@$(MAKE) --no-print-directory -C $(PRINTF_DIR) clean

fclean: clean
		@$(RM) $(NAME)
		@$(RM) $(NAME_BONUS)
		@$(RM) $(LIBFT_PATH)
		@$(RM) $(PRINTF_PATH)
		@echo "$(LIGHT_CYAN)Full cleanup done!$(RESET)"

re: fclean all

.PHONY: all re clean fclean bonus 