/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkasbaou <hkasbaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:21:08 by hkasbaou          #+#    #+#             */
/*   Updated: 2023/02/11 00:30:08 by hkasbaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

int	*copy(int *tab, int len)
{
	int	i;
	int	*tab_sorted;

	tab_sorted = malloc((len) * sizeof(int));
	i = 0;
	while (i < len)
	{
		tab_sorted[i] = tab[i];
		i++;
	}
	return (tab_sorted);
}

void	sort_tab(int *tab, int len)
{
	int	i;
	int	x;
	int	j;

	i = 0;
	i = 0;
	while (i < len - 1)
	{
		j = 0;
		x = 0;
		while (j < len - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				swap(&tab[j], &tab[j + 1]);
				x = 1;
			}
			j++;
		}
		if (x == 0)
			break ;
		i++;
	}
}

void	sorting(int *tab, int len)
{
	t_stack	a;
	t_stack	b;
	int		*tab_sorted;

	(void)tab;
	tab_sorted = copy(tab, len);
	sort_tab(tab_sorted, len);
	stack_a_creator(tab, tab_sorted, len, &a);
	stack_b_creator(len, &b);
	if (len == 2)
		sa(a.stack, len);
	else if (len == 3)
		sort3(a.stack, b.stack, a.size, b.size);
	else if (len == 5)
		sort5(a.stack, b.stack, a.size, b.size);
	else if (len <= 15)
		sort_big(&a, &b, 1);
	else if (len <= 100)
		sort_big(&a, &b, 2);
	else if (len > 100)
		sort_big(&a, &b, 3);
	freeall(&a, &b, &tab, &tab_sorted);
}

int	main(int ac, char *av[])
{
	int	*tab;
	int	len;

	tab = NULL;
	len = 0;
	if (checker(av, ac, &tab, &len) == 0)
	{
		free(tab);
		return (0);
	}
	if (len == 1 || len == 0)
		return (0);
	sorting(tab, len);
	return (0);
}
