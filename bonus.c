#include "push_swap.h"


int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < (int)n - 1 && str1[i] && str2[i] && str1[i] == str2[i])
	{
		i++;
	}
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
void remplir_stack_a(t_stack *a,int len,int *tab)
{
	int i =0;
	a->size = len;
	a->stack = malloc(len * sizeof(int));
	while (i < len)
	{
		a->stack[i].nbr = tab[i];
		i++;
		// printf("%d\n",a->stack[i++].nbr);
	}
	
}
void remplir_stack_b(t_stack *b,int len)
{
	b->stack = malloc(len * sizeof(int));
	b->size = -1;
}
int if_sorted(t_stack *a)
{
	int i = 0;
	while (i < a->size - 1)
	{
		// printf("%d",a->stack[i].nbr);
		if(a->stack[i].nbr > a->stack[i + 1].nbr)
			return 1;
		i++;
	}
	printf("sorted");
	return 0;
	
}
void doo(char *str,t_stack *a,t_stack *b)
{
	int i = 0;
	
	if(!ft_strncmp(str,"sa",ft_strlen(str)))
		sa(a->stack,a->size);
	else  if(!ft_strncmp(str,"sb",ft_strlen(str)))
		sb(b->stack,b->size);
	else if(!ft_strncmp(str,"ra",ft_strlen(str)))
		ra(a->stack,a->size);
	else if(!ft_strncmp(str,"rb",ft_strlen(str)))
		rb(b->stack,b->size);
	else if(!ft_strncmp(str,"rra",ft_strlen(str)))
		rra(a->stack,a->size);
	else if(!ft_strncmp(str,"rrb",ft_strlen(str)))
		rrb(b->stack,b->size);
	else if(!ft_strncmp(str,"pa",ft_strlen(str)))
		pb(a->stack,b->stack,&a->size, &b->size);
	else if(!ft_strncmp(str,"pb",ft_strlen(str)))
		pb(a->stack,b->stack,&a->size, &b->size);
	else 
		exit(1);
	while (i < a->size)
	{
		printf("%d\n",a->stack[i].nbr);
		i++;
	}
	if(!if_sorted(a))
		exit(1);
}
void bonus(t_stack *a,t_stack *b)
{
	char c;
	char str[3];
	int i;
	i = 0;
	// printf("fuuck");
	while (read(0,&c,1))
	{
		if(c != '\n')
			str[i++] = c;
		else
		{
			str[i] = '\0';
			if(str[0] != '\n')
			{
				doo(str,a,b);
				i = 0;
				str [0]= 0;
				str [1]= 0;
				str [2]= 0;
			}
		}
	}
	
}
void check_bonus(int *tab, int len)
{
	t_stack a;
	t_stack b;

	remplir_stack_a(&a,len,tab);
	remplir_stack_b(&b,len);
	int i = 0;
	while (i < a.size)
	{
		printf("%d\n",a.stack[i].nbr);
		i++;
	}
	bonus(&a,&b);
}
int main(int ac, char  *av[])
{
	int len;
	int *tab = NULL;
	if(checker(av,ac,&tab,&len) == 0)
		return 0;
	// printf("%d\n",len);;
	check_bonus(tab,len);
	

	return 0;
}
