#################################################################################################
###**											FdF											**###
#####***************************************************************************************#####


###-------------------------------------------------------------------------------------------###
###**							Variables and dependencies									**###
#####---------------------------------------------------------------------------------------#####
NAME = fdf

CC = cc 

INCLUDES = includes 

CFLAGS = -Wall -Werror -Wextra -g 

SRC = srcs/fdf.c srcs/llists_fts.c srcs/mlx_fts.c srcs/utils_fts.c \
		srcs/draw_fts.c srcs/utils_fts2.c srcs/hooks_fts.c srcs/hooks_fts2.c \
		srcs/rotation_fts.c	srcs/utils_fts3.c

OBJ :=$(SRC:.c=.o)

# libft
LIBFT = make -sC ./libft
LIBFT_FOLDER = ./libft

# colors
RED    = 	\033[0;31m
GREEN  = 	\033[0;32m
ORANGE = 	\033[0;33m
BLUE   = 	\033[34m
PURPLE = 	\033[35m
DEF    = 	\033[0m

###+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++###
###**								PHONY targets and rules									**###
#####+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++#####

.PHONY: all clean fclean norm re

all : $(NAME)

$(NAME): $(OBJ)
	@$(LIBFT)
	@$(CC) $(OBJ) -Llibft -lft -Lmlx_linux -lmlx_Linux -L/usr/lib \
	-Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	@echo "$(ORANGE)│                 $(PURPLE)[==========] 100%$(ORANGE)\
	                 │$(DEF)"
	@echo "$(ORANGE)├───────────────────────────────────────────────────┤"
	@echo "│                  $(GREEN)FDF IS COMPILED$(ORANGE)                  │"
	@echo "$(ORANGE)├───────────────────────────────────────────────────┤$(DEF)"
	@echo "$(ORANGE)│                 $(PURPLE)[==========] 100%$(ORANGE)\
	                 │$(DEF)"
	@echo "$(ORANGE)├───────────────────────────────────────────────────┤"
	@echo "│                 $(BLUE) How to use FdF? $(ORANGE)                 │ "
	@echo "│$(BLUE)  Choose executable and a map from $(GREEN) /maps $(BLUE)\
	 folder$(ORANGE)  │"
	@echo "│            $(BLUE)Example of use: $(GREEN)./fdf 42.fdf$(ORANGE)           │"
	@echo "$(ORANGE)└───────────────────────────────────────────────────┘$(DEF)"

%.o: %.c
	@$(CC) $(CFLAGS) -I$(INCLUDES) -I/usr/include \
	-Imlx_linux -O3 -c $< -o $@

clean:
	@rm -f $(OBJ)
	@make clean -sC ./libft
	@echo "$(ORANGE)┌───────────────────────────────────────────────────┐"
	@echo "│                    $(GREEN)[✓] CLEANED$(ORANGE)                    │"
	@echo "$(ORANGE)└───────────────────────────────────────────────────┘$(DEF)"
	
fclean : clean
	@rm -f $(NAME)
	@make fclean -sC ./libft

norm : 
	@echo "$(BLUE)      CHECK SOURSE FILES$(RESET)"
	@echo "$(ORANGE)******************************$(GREEN)"
	@norminette $(SRC)
	@echo "$(BLUE)        CHECK INCLUDES$(RESET)"
	@echo "$(ORANGE)******************************$(GREEN)"
	@norminette $(INCLUDES)
	@echo "$(BLUE)         CHECK  LIBFT$(RESET)"
	@echo "$(ORANGE)******************************$(GREEN)"
	@norminette $(LIBFT_FOLDER)
	@echo "$(ORANGE)******************************$(BLUE)"
	@echo "        NO NORM ERRORS$(RESET)"
	@echo "$(ORANGE)******************************$(DEF)"

re : fclean all


#####***************************************************************************************#####
###**										Good luck!										**###
#################################################################################################
