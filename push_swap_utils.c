/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkasbaou <hkasbaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:55:37 by hkasbaou          #+#    #+#             */
/*   Updated: 2022/11/17 22:57:01 by hkasbaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_element *tab, int len)
{
	t_element	tmp;

	printf("sa\n");
	tmp = tab[len - 1];
	tab[len - 1] = tab[len - 2];
	tab[len - 2] = tmp;
}

void	sb(t_element *b, int len)
{
	t_element	tmp;

	printf("sb\n");
	tmp = b[len - 1];
	b[len - 1] = b[len - 2];
	b[len - 2] = tmp;
}

void	ss(t_element *a, t_element *b, int top_a, int top_b)
{
	printf("ss\n");
	sa(a, top_a + 1);
	sb(b, top_b + 1);
}

void	ra(t_element *a, int top_a)
{
	int	i;
	t_element	tmp;

	printf("ra\n");
	tmp = a[0];
	i = 0;
	while (i <= top_a)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[top_a - 1] = tmp;
}

void	rb(t_element *b, int top_b)
{
	int	i;
	t_element	tmp;
	if(top_b >= 0)
	{
		printf("rb\n");
		tmp = b[0];
		i = 0;
		while (i <= top_b - 1)
		{
			b[i] = b[i + 1];
			i++;
		}
		b[top_b - 1] = tmp;
	}
}
