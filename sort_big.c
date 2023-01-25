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

int	get_index(t_stack *arr)
{
	int i = 0;
	int max = arr->stack[0].nbr;
	int ind = 0;
	while (i <= arr->size)
	{
		if(arr->stack[i].nbr >= max)
		{
			max = arr->stack[i].nbr;
			ind = i;
		}
		i++;
	}
	return(ind);
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

void push_b(t_stack *a,t_stack *b, int range,int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if(check_if_in_down(a,i,range))
		{
			push_range(a,b,range);
			i += range;
		}
		else if (a->stack[0].pos < i)
		{
			pb(a->stack,b->stack,&a->size,&b->size);
			rb(b->stack,b->size);
			i++;
		}
		else if (a->stack[0].pos < i + range)
		{
			pb(a->stack,b->stack,&a->size,&b->size);
			i++;
		}
		else
			ra(a->stack,a->size);
	}
}
void push_back(t_stack *a, t_stack *b, int max)
{
	int tmp;
	int index;
	while (max >= 0)
	{
		index = get_index(b);
		tmp = b->stack[index].nbr;
		if(index < (b->size / 2))
		{
			while (b->stack[0].nbr != tmp)
				rb(b->stack,b->size);
		}
		else
		{
			while (b->stack[0].nbr != tmp)
				rrb(b->stack,b->size);
		}
		pa(a->stack,b->stack,&a->size,&b->size);
		max--;
	}
}

void sort15(t_stack *a,t_stack *b)
{
	int index;
	int tmp;

	while (a->size > 0)
	{
		index = get_index(a);
		tmp = a->stack[index].nbr;
		if(index < (a->size / 2))
		{
			while (a->stack[0].nbr != tmp)
				ra(a->stack,a->size);
		}
		else
		{
			while (a->stack[0].nbr != tmp)
				rra(a->stack,a->size);
		}
		pb(a->stack,b->stack,&a->size,&b->size);
	}
}

void sort_big(t_stack *a,t_stack *b,int range)
{
	int len;
	int max;

	len = a->size;
	max = len;
	if(range == 1)
		range = 3;
	if(range == 2)
		range = 15;
	else if(range == 3)
		range = 30;
	push_b(a,b,range,len);
	max--;
	push_back(a,b,max);
}