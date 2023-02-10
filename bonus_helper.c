/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkasbaou <hkasbaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:16:12 by hkasbaou          #+#    #+#             */
/*   Updated: 2023/02/10 15:17:59 by hkasbaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	remplir_stack_a(t_stack *a, int len, int *tab)
{
	int	i;

	i = 0;
	a->size = len;
	a->stack = malloc(len * sizeof(t_element));
	while (i < len)
	{
		a->stack[i].nbr = tab[i];
		i++;
	}
}

void	remplir_stack_b(int len, t_stack *stack_b)
{
	int	i;

	i = 0;
	stack_b->stack = malloc(len * sizeof(t_element));
	while (i < len)
	{
		stack_b->stack[i++].nbr = 0;
	}
	stack_b->size = -1;
}

void	rrr_b(t_element *a, t_element *b, int top_a, int top_b)
{
	rra_b(a, top_a);
	rrb_b(b, top_b);
}
