#include "push_swap.h"

void swap(int *a,int *b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

void sort_tab(int *tab,int len)
{
	int i = 0;
	int x;
	int j;
	i = 0;
	// while (i< len)
	// {
	//     printf("%d\n",tab[i++]);
	// }
	while (i < len - 1)
	{
		j = 0;
		x = 0;
		while (j < len - 1)
		{
			if(tab[j] > tab[j + 1])
			{
				swap(&tab[j],&tab[j+1]);
				x = 1;
			}
			j++;
		}
		if(x == 0)
			break;
		i++;
	}
}


void	stack_a_creator(int *tab,int *tab_sorted,int len,t_stack *stack_a)
{
	int i; 
	int j;
	(void)tab_sorted;
	(void)tab;
	stack_a->stack = (t_element *)malloc(len * sizeof(t_element));
	i = 0;
	while (i < len)
	{
		stack_a->stack[i].nbr = tab[i];
		i++;
	}
	i = 0;
	// while (j < len)
	// {
	// 	printf("%d\n",stack_a.stack[j++].nbr);
	// }
	// printf("%d \t %d\n %d",tab[i],tab_sorted[j],len);
	while (i < len)
	{
		// printf("()");
		j = 0;
		while (j < len)
		{
			if (tab[i] == tab_sorted[j])
				stack_a->stack[i].pos = j;
			j++;
		}
		i++;		
	}
	j = 0;
	// while (j < len)
	// {
	// 	printf("%d \t %d\n",stack_a->stack[j].pos , stack_a->stack[j].nbr);
	// 	j++;
	// }
}
void	stack_b_creator(int len,t_stack *stack_b)
{
	stack_b->stack = (t_element *)malloc(len * sizeof(t_element));
	stack_b->size = -1;
}

void print(t_stack a,t_stack b,int len)
{
	int i = 0;
	// if(a.size > b.size)
	// {
	// 	while (i < a.size)
	// 	{
	// 		printf("%d \t %d\n",a.stack[i].nbr,b.stack[i].nbr);
	// 		i++;
	// 	}
	// 	printf("a \t b\n");
	// }
	// else
	// {
	// 	while (i < b.size)
	// 	{
	// 		printf("%d \t||\t %d\n",a.stack[i].nbr,b.stack[i].nbr);
	// 		i++;
	// 	}
	// 	printf("a \t b\n");
	// }
	while (i < len)
		{
			printf("%d \t %d\n",a.stack[i].nbr,b.stack[i].nbr);
			i++;
		}
}

int	get_index(t_stack *arr)
{
	int i = 0;
	int max = arr->stack[0].nbr;
	int ind = 0;
	while (i < arr->size)
	{
		if(arr->stack[i].nbr >= max)
		{
			max = arr->stack[i].nbr;
			ind = i;
		}
		i++;
	}
	printf("max -> %d \t ind-> %d\n",max,ind);
	return(ind);
}
void sort_big(t_stack *a,t_stack *b)
{
	int i;
	int len;
	int max;
	int index;
	int tmp;

	len = a->size;
	max = len;
	i = 0;
	while (i < len)
	{
		if (a->stack[0].pos < i)
		{
			pb(a->stack,b->stack,&a->size,&b->size);
			rb(b->stack,b->size);
			i++;
		}
		else if (a->stack[0].pos < i + 15)
		{
			pb(a->stack,b->stack,&a->size,&b->size);
			i++;
		}
		else
		{
			ra(a->stack,a->size);
		}
		// print(*a,*b,len);
		// printf("----------------------\n");
		// printf("----------------------\n");
		// printf("----------------------\n");
	}
	print(*a,*b,len );
	max--;
	while (max >= 0)
	{
		printf("b[len]->%d\n",b->stack[b->size].nbr);
		index = get_index(b);
		tmp = b->stack[index].nbr;
		// printf("ind-> %d \t maxN -> %d\n",index,max);
		if(index < (b->size / 2))
		{
			while (b->stack[0].nbr != tmp)
			{
				// print(*a,*b,len);
				// printf("----------------------\n");
				// printf("----------------------\n");
				// printf("----------------------\n");
				rb(b->stack,b->size);
				printf("b[len]->%d\n",b->stack[b->size].nbr);
			}
		}
		else
		{
			while (b->stack[0].nbr != tmp)
			{
				// print(*a,*b,len);
				// printf("----------------------\n");
				// printf("----------------------\n");
				// printf("----------------------\n");
				rrb(b->stack,b->size);
				printf("b[len]->%d\n",b->stack[b->size].nbr);
			}
		}
		print(*a,*b,len);
		printf("{{{{{{{{{{{{{{{{{{}}}}}}}}}}}}}}}}}}}}}}}{{{{{{{{{{{}}}}}}}}}}}\n");
		pa(a->stack,b->stack,&a->size,&b->size);
		max--;
		
	}
	print(*a,*b,len);
}

// void sort15(t_stack *a,t_stack *b)
// {
// 	int max;
// }
int main(int ac, char *av[])
{
	t_stack stack_a;
	t_stack stack_b;
	int *tab;
	int *tab_sorted;
	int i = 1;

	(void)av;
	int len;
	len = ac - 1;
	stack_a.size  = len;
	stack_b.size = -1;
	
	tab = malloc(stack_a.size * sizeof(int));
	tab_sorted = malloc(stack_a.size * sizeof(int));
	while (i <= stack_a.size)
	{
		tab[i - 1] = ft_atoi(av[i]);
		tab_sorted[i - 1] = ft_atoi(av[i]);
		i++;
	}
	sort_tab(tab_sorted,stack_a.size);
	stack_a_creator(tab,tab_sorted,stack_a.size,&stack_a);
	stack_b_creator(stack_a.size,&stack_b);
	i = 0;
	sort_big(&stack_a,&stack_b);
	// while (i < stack_a.size)
	// {
	// 	printf("%d \t %d\n",stack_a.stack[i].nbr,stack_a.stack[i].pos);
	// 	i++;
	// }
	// printf("------------AFTER---------------\n");
	// t_stack tmp;
	// tmp.stack = (t_element *)malloc(1 * sizeof(t_element));
	// tmp.stack[0] = stack_a.stack[0];
	// tmp.stack[0].pos = stack_a.stack[1].pos;
	// printf("%d \t %d\n",tmp.stack[0].nbr,tmp.stack[0].pos);
	// sa(stack_a.stack,stack_a.size);
	// sort100(&stack_a,&stack_b);
	// rra(stack_a.stack,stack_a.size);
	// sort3(stack_a.stack,stack_b.stack,stack_a.size,stack_b.size);
	// i = 0;
	// while (i < stack_a.size)
	// {
	// 	printf("%d \t %d\n",stack_a.stack[i].nbr,stack_a.stack[i].pos);
	// 	i++;
	// }

	return 0;
}
