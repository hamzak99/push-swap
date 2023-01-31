/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkasbaou <hkasbaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:18:33 by hkasbaou          #+#    #+#             */
/*   Updated: 2023/01/29 17:18:34 by hkasbaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_b(t_element *tab, int len)
{
	t_element	tmp;

	(void)len;
	tmp = tab[0];
	tab[0] = tab[1];
	tab[1] = tmp;
}

void	sb_b(t_element *b, int len)
{
	t_element	tmp;

	(void)len;
	tmp = b[0];
	b[0] = b[1];
	b[1] = tmp;
}

void	ss_b(t_element *a, t_element *b, int top_a, int top_b)
{
	sa(a, top_a + 1);
	sb(b, top_b + 1);
}

void	ra_b(t_element *a, int top_a)
{
	int			i;
	t_element	tmp;

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
	int			i;
	t_element	tmp;

	if (top_b >= 0)
	{
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
