NAME=minishell

SRC=main.c change_dir.c ft_freetab.c pwd.c ft_printtab.c envrmt.c home.c setpwd.c \
	setold.c change_dir_special.c virgule_point.c builtin_gestion.c

OBJ=main.o change_dir.o ft_freetab.o pwd.o ft_printtab.o envrmt.o home.o setpwd.c \
	setold.o change_dir_special.o virgule_point.o builtin_gestion.o

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
