#include "push_swap.h"

void	sa_b(t_element *tab, int len)
{
	t_element	tmp;
	(void)len;
	printf("sa\n");
	tmp = tab[0];
	tab[0] = tab[1];
	tab[1] = tmp;
}

void	sb_b(t_element *b, int len)
{
	t_element	tmp;
	(void)len;
	printf("sb\n");
	tmp = b[0];
	b[0] = b[1];
	b[1] = tmp;
}

void	ss_b(t_element *a, t_element *b, int top_a, int top_b)
{
	printf("ss\n");
	sa(a, top_a + 1);
	sb(b, top_b + 1);
}

void	ra_b(t_element *a, int top_a)
{
	int	i;
	t_element	tmp;

	printf("ra\n");
	tmp = a[0];
	
	i = 0;
	while (i <= top_a - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[top_a - 1] = tmp;
}

void	rb_b(t_element *b, int top_b)
{
	int	i;
	t_element	tmp;
	if(top_b >= 0)
	{
		printf("rb\n");
		tmp = b[0];
		i = 0;
		while (i <= top_b)
		{
			b[i] = b[i + 1];
			i++;
		}
		b[top_b] = tmp;
	}
}

void	rr_b(t_element *a, t_element *b, int top_a, int top_b)
{
	printf("rr\n");
	ra(a, top_a);
	rb(b, top_b);
}
void remplir_0_b(t_element *arr)
{
	arr->nbr = 0;
	arr->pos = 0;
}
void	pa_b(t_element *a, t_element *b, int *top_a, int *top_b)
{
	int	i;
	t_element tmp = b[0];
	printf("pa\n");
	*top_a += 1;
	i = *top_a;
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	i = 0;
	while (i < *top_b)
	{
		b[i] = b[i + 1];
		i++;
	}
	remplir_0_b(&b[*top_b]);
	a[0] = tmp;
	*top_b -= 1;
}

void	pb_b(t_element *a, t_element *b, int *top_a, int *top_b)
{
	int	i;
	t_element tmp = a[0];
	printf("pb\n");
	*top_b += 1;
	i = *top_b;
	while (i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	i = 0;
	while (i < *top_a)
	{
		a[i] = a[i + 1];
		i++;
	}
	remplir_0_b(&a[*top_a]);
	b[0] = tmp;
	*top_a -= 1;
}

void	rra_b(t_element *a, int top_a)
{
	int	i;
	t_element	tmp;

	printf("rra\n");
	tmp = a[top_a];
	i = 0;
	while (0 < top_a)
	{
		a[top_a] = a[top_a - 1];
		top_a--;
	}
	a[0] = tmp;
}

void	rrb_b(t_element *b, int top_b)
{
	int	i;
	t_element	tmp;

	printf("rrb\n");
	tmp = b[top_b];
	i = 0;
	while (0 < top_b)
	{
		b[top_b] = b[top_b - 1];
		top_b--;
	}
	b[0] = tmp;
}

void	rrr_b(t_element *a, t_element *b, int top_a, int top_b)
{
	rra(a, top_a);
	rrb(b, top_b);
	printf("rrr\n");
}
