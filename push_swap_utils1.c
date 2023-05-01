/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkasbaou <hkasbaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:57:21 by hkasbaou          #+#    #+#             */
/*   Updated: 2023/02/19 00:08:27 by hkasbaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	rr(t_element *a, t_element *b, int top_a, int top_b)
{
	int	n1;
	int	n2;

	n1 = ra(a, top_a);
	if (n1 == 1)
	{
		n2 = rb(b, top_b);
		if (n2 == 1)
			write(1, "rr\n", 3);
	}
}

void	pa(t_element *a, t_element *b, int *top_a, int *top_b)
{
	int			i;
	t_element	tmp;

	if (*top_b >= 0)
	{
		tmp = b[0];
		write(1, "pa\n", 3);
		*top_a += 1;
		i = *top_a;
		while (i > 0)
		{
			a[i] = a[i - 1];
			i--;
		}
		i = -1;
		while (++i < *top_b)
			b[i] = b[i + 1];
		remplir_0(&b[*top_b]);
		a[0] = tmp;
		*top_b -= 1;
	}
}

void	pb(t_element *a, t_element *b, int *top_a, int *top_b)
{
	int			i;
	t_element	tmp;

	if (*top_a >= 1)
	{
		tmp = a[0];
		write(1, "pb\n", 3);
		*top_b += 1;
		i = *top_b;
		while (i > 0)
		{
			b[i] = b[i - 1];
			i--;
		}
		i = -1;
		while (++i < *top_a)
			a[i] = a[i + 1];
		remplir_0(&a[*top_a]);
		b[0] = tmp;
		*top_a -= 1;
	}
}

int	rra(t_element *a, int top_a)
{
	int			i;
	t_element	tmp;

	if (top_a >= 2)
	{
		write(1, "rra\n", 4);
		tmp = a[top_a - 1];
		i = 0;
		while (0 < top_a)
		{
			a[top_a] = a[top_a - 1];
			top_a--;
		}
		a[0] = tmp;
		return (1);
	}
	return (0);
}

int	rrb(t_element *b, int top_b)
{
	int			i;
	t_element	tmp;

	if (top_b >= 1)
	{
		write(1, "rrb\n", 4);
		tmp = b[top_b];
		i = 0;
		while (0 < top_b)
		{
			b[top_b] = b[top_b - 1];
			top_b--;
		}
		b[0] = tmp;
		return (1);
	}
	return (0);
}
