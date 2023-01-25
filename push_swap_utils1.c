/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkasbaou <hkasbaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:57:21 by hkasbaou          #+#    #+#             */
/*   Updated: 2022/12/09 15:05:33 by hkasbaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_element *a, t_element *b, int top_a, int top_b)
{
	printf("rr\n");
	ra(a, top_a);
	rb(b, top_b);
}
void remplir_0(t_element *arr)
{
	arr->nbr = 0;
	arr->pos = 0;
}
void	pa(t_element *a, t_element *b, int *top_a, int *top_b)
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
	remplir_0(&b[*top_b]);
	a[0] = tmp;
	*top_b -= 1;
}

void	pb(t_element *a, t_element *b, int *top_a, int *top_b)
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
	remplir_0(&a[*top_a]);
	b[0] = tmp;
	*top_a -= 1;
}

void	rra(t_element *a, int top_a)
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

void	rrb(t_element *b, int top_b)
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

