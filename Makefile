NAME = fdf
CC = gcc 

#SRC = $(wildcard *.c)
SRC = fdf.c llists_fts.c mlx_fts.c utils_fts.c draw_fts.c	\
		utils_fts2.c
OBJ :=$(SRC:.c=.o)

# libft
LIBFT = make -sC ./libft

# colors
GREEN = \033[0;32m
RED = \033[0;31m
DEF = \033[0m

all : $(NAME)

$(NAME): $(OBJ)
	@$(LIBFT)
	@$(CC) $(OBJ) -Llibft -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	@make clean -sC ./libft
	@rm -f $(OBJ)
	@echo "$(GREEN)It's happened!$(DEF)"

%.o: %.c
	@$(CC)  -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	@rm -f $(OBJ)
	@make clean -sC ./libft

fclean : clean
	@rm -f $(NAME)
	@make fclean -sC ./libft

re : fclean all