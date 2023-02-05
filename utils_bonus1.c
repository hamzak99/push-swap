/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkasbaou <hkasbaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:26:17 by hkasbaou          #+#    #+#             */
/*   Updated: 2023/02/05 17:42:23 by hkasbaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa_b(t_element *a, t_element *b, int *top_a, int *top_b)
{
	int			i;
	t_element	tmp;

	tmp = b[0];
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

void	pb_b(t_element *a, t_element *b, int *top_a, int *top_b)
{
	int			i;
	t_element	tmp;

	tmp = a[0];
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

void	rra_b(t_element *a, int top_a)
{
	int			i;
	t_element	tmp;

	tmp = a[top_a - 1];
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
	int			i;
	t_element	tmp;

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
	rra_b(a, top_a);
	rrb_b(b, top_b);
}
