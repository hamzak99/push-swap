#include "push_swap.h"

void push_range(t_stack  *a,t_stack *b,int range)
{
	int len  = a->size;
	int i = a->size - range;
	while (i < len)
	{
		rra(a->stack,a->size);
		pb(a->stack,b->stack,&a->size,&b->size);
		i++;
	}
}

int check_if_in_down(t_stack *a,int ind,int range)
{
	(void)ind;
	int len = a->size;
	int i = a->size - range;
	while(i < len)
	{
		if(a->stack[i].nbr > a->stack[i + 1].nbr)
			i++;
		else
			return 0;
	}
	i = a->size - range;
	return 1;
}