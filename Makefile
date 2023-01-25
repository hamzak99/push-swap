NAME = push_swap

NAME_B = checker
flags = -Wall -Wextra -Werror


src = push_swap.c push_swap_utils.c  push_swap_utils1.c \
		push_func.c ft_split.c swap_3_5.c leaks_checker.c
srcB = bonus.c push_swap.c swap_3_5.c 	push_swap_utils.c  push_swap_utils1.c \
	push_func.c ft_split.c 

obj = $(src:.c=.o)
objB = $(srcB:.c=.o)


all: $(NAME)

$(NAME):  $(obj) push_swap.h
	cc $(flags) $(obj) -o $(NAME)
bonus: $(objB) push_swap.h
	cc $(flags) $(objB) -o $(NAME_B)
%.o: %.c push_swap.h
	$(CC) -Wall -Wextra -Werror -c $< -o $@


clean:
	rm -rf $(obj) $(objB)

fclean: clean
	rm -rf $(NAME) 

re: fclean all