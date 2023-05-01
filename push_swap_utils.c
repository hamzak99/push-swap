/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkasbaou <hkasbaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:55:37 by hkasbaou          #+#    #+#             */
/*   Updated: 2023/02/18 18:14:08 by hkasbaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	sa(t_element *tab, int len)
{
	t_element	tmp;

	(void)len;
	if (len >= 2)
	{
		write(1, "sa\n", 3);
		tmp = tab[0];
		tab[0] = tab[1];
		tab[1] = tmp;
	}
}

void	sb(t_element *b, int len)
{
	t_element	tmp;

	(void)len;
	if (len >= 1)
	{
		write(1, "sb\n", 3);
		tmp = b[0];
		b[0] = b[1];
		b[1] = tmp;
	}
}

void	ss(t_element *a, t_element *b, int top_a, int top_b)
{
	write(1, "ss\n", 3);
	sa(a, top_a + 1);
	sb(b, top_b + 1);
}

int	ra(t_element *a, int top_a)
{
	int			i;
	t_element	tmp;

	if (top_a >= 2)
	{
		write(1, "ra\n", 3);
		tmp = a[0];
		i = 0;
		while (i <= top_a - 1)
		{
			a[i] = a[i + 1];
			i++;
		}
		a[top_a - 1] = tmp;
		return (1);
	}
	return (0);
}

int	rb(t_element *b, int top_b)
{
	int			i;
	t_element	tmp;

	if (top_b >= 1)
	{
		write(1, "rb\n", 3);
		tmp = b[0];
		i = 0;
		while (i <= top_b)
		{
			b[i] = b[i + 1];
			i++;
		}
		b[top_b] = tmp;
		return (1);
	}
	return (0);
}
