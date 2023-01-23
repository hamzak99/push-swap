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
	(void)len;
	printf("sa\n");
	tmp = tab[0];
	tab[0] = tab[1];
	tab[1] = tmp;
}

void	sb(t_element *b, int len)
{
	t_element	tmp;
	(void)len;
	printf("sb\n");
	tmp = b[0];
	b[0] = b[1];
	b[1] = tmp;
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
	while (i <= top_a - 1)
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
		// printf("tmp->%d\n",tmp.nbr);
		i = 0;
		while (i <= top_b)
		{
			// printf("a[0]->%d\n",b[0].nbr);
			// printf("a[1]->%d\n",b[1].nbr);
			// printf("a[2]->%d\n",b[2].nbr);
			// printf("a[3]->%d\n",b[3].nbr);
			// printf("a[4]->%d\n",b[4].nbr);
			// printf("a[5]->%d\n",b[5].nbr);
			// printf("a[6]->%d\n",b[6].nbr);
			// printf("a[7]->%d\n",b[7].nbr);
			// printf("--------------\n");
			// printf("--------------\n");
			b[i] = b[i + 1];
			i++;
		}
		// printf("index->%d \n",i);
		b[top_b] = tmp;
	}
}
