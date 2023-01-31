NAME = push_swap

NAME_B = checker
flags = -Wall -Wextra -Werror


src = push_swap.c push_swap_utils.c  push_swap_utils1.c check_args1.c  remplire_stack.c\
		push_func.c ft_split.c check_args.c sort_big.c swap_3_5.c  sort_big_helper.c leaks_checker.c
srcB = bonus.c check_args.c check_args1.c sort_big_helper.c utils_bonus.c push_swap_utils.c  push_swap_utils1.c remplire_stack.c\
	push_func.c ft_split.c utils_bonus1.c bonus_helper.c leaks_checker.c

obj = $(src:.c=.o)
objB = $(srcB:.c=.o)


all: $(NAME)

$(NAME):  $(obj) push_swap.h
	cc $(flags) $(obj) -o $(NAME)
bonus: $(objB) push_bonus.h
	cc $(flags) $(objB) -o $(NAME_B)
%.o: %.c push_swap.h
	$(CC) -Wall -Wextra -Werror -c $< -o $@


clean:
	rm -rf $(obj) $(objB)

fclean: clean
	rm -rf $(NAME) 

re: fclean all