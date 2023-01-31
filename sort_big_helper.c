/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkasbaou <hkasbaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:18:58 by hkasbaou          #+#    #+#             */
/*   Updated: 2023/01/28 20:24:32 by hkasbaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	push_range(t_stack *a, t_stack *b, int range)
{
	int	len;
	int	i;

	len = a->size;
	i = a->size - range;
	while (i < len)
	{
		rra(a->stack, a->size);
		pb(a->stack, b->stack, &a->size, &b->size);
		i++;
	}
}

int	check_if_in_down(t_stack *a, int ind, int range)
{
	int	len;
	int	i;

	(void)ind;
	len = a->size;
	i = a->size - range;
	while (i < len)
	{
		if (a->stack[i].nbr > a->stack[i + 1].nbr)
			i++;
		else
			return (0);
	}
	i = a->size - range;
	return (1);
}

void	print(t_stack a, t_stack b, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		printf("%d \t %d\n", a.stack[i].nbr, b.stack[i].nbr);
		i++;
	}
}

void	remplir_0(t_element *arr)
{
	arr->nbr = 0;
	arr->pos = 0;
}
