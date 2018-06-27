NAME=minishell

SRC=main.c change_dir.c ft_freetab.c pwd.c

OBJ=main.o change_dir.o ft_freetab.o pwd.o

FLAGS= -Wall -Wextra -Werror -g3 -fsanitize=address

INCLUDE=minishell.h

all: $(NAME)

$(NAME): $(OBJ) 
	make -C libft/
	clang $(FLAGS) $(OBJ) libft/libft.a -o $(NAME)
#	clang $(FLAGS) -c $(SRC)

%.o: %.c
	clang $(FLAGS) -c -o $@ $^

fclean: clean
	make fclean -C libft/
	rm -rf $(NAME)

clean:
	rm -rf $(OBJ)
	make clean -C libft/

re: fclean all
