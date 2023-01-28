#include "push_swap.h"

void freeall(t_stack *a,t_stack *b,int **tab,int **tab_sorted)
{
	free(a->stack);
	free(b->stack);
	free(*tab);
	free(*tab_sorted);
}

void	stack_b_creator(int len,t_stack *stack_b)
{
	int i = 0;
	stack_b->stack = (t_element *)malloc(len * sizeof(t_element));
	while (i < len)
	{
		stack_b->stack[i++].nbr = 0;
	}
	
	stack_b->size = -1;
}

void	stack_a_creator(int *tab,int *tab_sorted,int len,t_stack *stack_a)
{
	int i; 
	int j;
	stack_a->stack = (t_element *)malloc(len * sizeof(t_element));
	i = -1;
	while (++i < len)
		stack_a->stack[i].nbr = tab[i];
	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < len)
			if (tab[i] == tab_sorted[j])
				stack_a->stack[i].pos = j;
	}
	stack_a->size = len;
}