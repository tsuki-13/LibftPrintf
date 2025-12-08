NAME=libftprintf.a
SRC=ft_printf.c ft_putnbr_hexa.c ft_putnbr_u.c ft_putnbr_fdd.c ft_putnbr_hexa_p.c ft_putstr_fdd.c
OBJ=$(SRC:.c=.o)
CC=cc
FLAGS=-Wall -Wextra -Werror

all:$(NAME)

$(NAME):$(OBJ)
	ar rcs $(NAME) $(OBJ)
%.o:%.c
	$(CC) $(FLAGS) -c $< -o $@
clean:
	rm -rf $(OBJ)
fclean:clean
	rm -rf $(NAME)
re:fclean all

.PHONY:all clean fclean re
