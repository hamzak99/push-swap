#include "push_swap.h"

void swap(int *a,int *b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}
int *copy(int *tab,int len)
{
	int i;
	int *tab_sorted;
	tab_sorted = malloc((len) * sizeof(int));
	i = 0;
	while (i < len)
	{
		tab_sorted[i] = tab[i];
		i++;
	}
	return tab_sorted;
}
void sort_tab(int *tab,int len)
{
	int i = 0;
	int x;
	int j;
	i = 0;
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
	stack_a->stack = (t_element *)malloc(len * sizeof(t_element));
	i = 0;
	while (i < len)
	{
		stack_a->stack[i].nbr = tab[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
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
			{
				rb(b->stack,b->size);
			}
		}
		else
		{
			while (b->stack[0].nbr != tmp)
			{
				rrb(b->stack,b->size);
			}
		}
		pa(a->stack,b->stack,&a->size,&b->size);
		max--;
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
	// i = 0;
	push_b(a,b,range,len);
	max--;
	push_back(a,b,max);
	// while (i < len)
	// {
	// 	if (a->stack[0].pos < i)
	// 	{
	// 		pb(a->stack,b->stack,&a->size,&b->size);
	// 		rb(b->stack,b->size);
	// 		i++;
	// 	}
	// 	else if (a->stack[0].pos < i + 15)
	// 	{
	// 		pb(a->stack,b->stack,&a->size,&b->size);
	// 		i++;
	// 	}
	// 	else
	// 		ra(a->stack,a->size);
	// }
	// while (max >= 0)
	// {
	// 	index = get_index(b);
	// 	tmp = b->stack[index].nbr;
	// 	if(index < (b->size / 2))
	// 	{
	// 		while (b->stack[0].nbr != tmp)
	// 		{
	// 			rb(b->stack,b->size);
	// 		}
	// 	}
	// 	else
	// 	{
	// 		while (b->stack[0].nbr != tmp)
	// 		{
	// 			rrb(b->stack,b->size);
	// 		}
	// 	}
	// 	pa(a->stack,b->stack,&a->size,&b->size);
	// 	max--;
	// }
}
void sort15(t_stack *a,t_stack *b)
{
	int index;
	int tmp;
	int len = a->size;
	while (a->size > 0)
	{
		index = get_index(a);
		tmp = a->stack[index].nbr;
		if(index < (a->size / 2))
		{
			while (a->stack[0].nbr != tmp)
			{
				ra(a->stack,a->size);
			}
		}
		else
		{
			while (a->stack[0].nbr != tmp)
			{
				rra(a->stack,a->size);
			}
		}
		pb(a->stack,b->stack,&a->size,&b->size);
		
	}
	print(*a,*b,len);
}




////checker
int check_num(char *av)
{
	int i;

	i = 0;
	while (av[i] != '\0')
	{
		if(!((av[i] >= '0' && av[i] <= '9') || av[i] == ' ' || av[i] == '-' || av[i] == '+'))
			return 0;
		i++;
	}
	return 1;
}

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = ft_strlen(str);
	if (!(char)c)
		return ((char *)str + i);
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i--;
	}
	return (0);
}
int check_if_all_num(char **av, int ac, int *len)
{
	int i;
	int k;
	char **str;
	i = 1;
	while (i < ac)
	{
		k = 0;
		if(check_num(av[i]) == 0)
			return 0;
		if(ft_strrchr(av[i], ' '))
		{
			str = ft_split(av[i],' ');
			while (str[k] != NULL)
				k++;
			(*len)+= k;
		}
		else
			(*len)++;
		i++;
	}
	return 1;
}
void remplir_a(int ac,char **av,int *vars,int *len)
{
	int i;
	int j;
	int k;
	char **str;
	(void)len;

	i = 1;
	k = 0;
	while (i < ac)
	{
		if(ft_strrchr(av[i], ' '))
		{
			j = 0;
			str = ft_split(av[i], ' ');
			while (str[j] != NULL)
				vars[k++] = ft_atoi(str[j++]);
		}
		else
			vars[k++] = ft_atoi(av[i]);
		i++;
	}
	// *len = k - 1;
}
int check_if_sorted(int *vars, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if( vars[i] > INT_MAX)
			return 0;
		if( vars[i] > vars[i + 1])
			return 0;
		// else if(vars[i] < vars[i + 1])
		i++;
	}
	return 1;
}
int check_if_repet(int *vars,int len)
{
	int i;
	int j;

	i = 0;
	while (i < len)
	{
		j = 0 ;
		while (j < len)
		{
			if(vars[i] == vars[j] && i != j)
				return 1;
			j++;
		}
		i++;
	}
	return 0;
}
// int check_repeat(int *tab,int ac,char **av)
// {
// 	int len;
// 	remplir_a(ac,av,tab,&len);
// 	if(check_if_sorted(tab,len) || !check_if_repet(tab,len))
// 		return 0;
// 	return 1;
// }

int checker(char **av, int ac,int **tab,int *len)
{
	int i;
	// int len = 0;
	i = 0;
	if(check_if_all_num(av,ac,len) == 0)
	{
		printf("ERROR");
		return 0;
	}
	*tab = malloc((*len) * sizeof(int));
	remplir_a(ac,av,*tab,len);
	if(check_if_sorted(*tab,*len))
	{
		return 0;
	}
	if(check_if_repet(*tab,*len))
	{
		printf("ERROR");
		return 0;
	}
	return 1;
}
void freeall(t_stack *a,t_stack *b,int **tab,int **tab_sorted)
{
	free(a->stack);
	free(b->stack);
	free(*tab);
	free(*tab_sorted);
}
void sorting(int *tab,int len)
{
	t_stack a;
	t_stack b;
	int *tab_sorted;
	(void)tab;
	b.size = -1;
	a.size = len;
	tab_sorted=copy(tab,len);
	sort_tab(tab_sorted,len);
	stack_a_creator(tab,tab_sorted,a.size,&a);
	stack_b_creator(a.size,&b);
	if(len == 2)
		sa(a.stack,len);
	else if(len == 3)
		sort3(a.stack,b.stack,a.size,b.size);
	else if(len == 5)
		sort5(a.stack,b.stack,a.size,b.size);
	else if(len <= 15)
		sort_big(&a,&b,1);
	else if(len <= 100)
		sort_big(&a,&b,2);
	else if(len > 100)
		sort_big(&a,&b,3);
	freeall(&a,&b,&tab,&tab_sorted);

}
void check_leaks();
int main(int ac, char *av[])
{
	int *tab = NULL;

	int len;
	len =0;
	if(checker(av,ac,&tab,&len) == 0)
	{
		free(tab);
		return 0;
	}
	sorting(tab,len);
	check_leaks();

	return 0;
}
