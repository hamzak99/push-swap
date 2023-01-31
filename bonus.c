/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkasbaou <hkasbaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:53:13 by hkasbaou          #+#    #+#             */
/*   Updated: 2023/01/31 23:01:31 by hkasbaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int	if_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->size - 1)
	{
		if (a->stack[i].nbr > a->stack[i + 1].nbr)
			return (1);
		i++;
	}
	return (0);
}

void	doo(char *str, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(str, "sa", ft_strlen(str)))
		sa_b(a->stack, a->size);
	else if (!ft_strncmp(str, "sb", ft_strlen(str)))
		sb_b(b->stack, b->size);
	else if (!ft_strncmp(str, "ra", ft_strlen(str)))
		ra_b(a->stack, a->size);
	else if (!ft_strncmp(str, "rb", ft_strlen(str)))
		rb_b(b->stack, b->size);
	else if ((!ft_strncmp(str, "rr", ft_strlen(str))))
		rr_b(a->stack, b->stack, a->size, b->size);
	else if (!ft_strncmp(str, "rra", ft_strlen(str)))
		rra_b(a->stack, a->size);
	else if (!ft_strncmp(str, "rrb", ft_strlen(str)))
		rrb_b(b->stack, b->size);
	else if ((!ft_strncmp(str, "rrr", ft_strlen(str))))
		rrr_b(a->stack, b->stack, a->size, b->size);
	else if (!ft_strncmp(str, "pa", ft_strlen(str)))
		pa_b(a->stack, b->stack, &a->size, &b->size);
	else if (!ft_strncmp(str, "pb", ft_strlen(str)))
		pb_b(a->stack, b->stack, &a->size, &b->size);
	else
	{
		printf("ERROR");
		exit(1);
	}
}

void	bonus(t_stack *a, t_stack *b)
{
	char	c;
	char	str[3];
	int		i;
	int		len;

	i = 0;
	len = a->size;
	while (read(0, &c, 1))
	{
		if (c != '\n')
			str[i++] = c;
		else
		{
			str[i] = '\0';
			if (str[0] != '\n')
			{
				doo(str, a, b);
				i = 0;
			}
		}
	}
	if (!if_sorted(a) && b->size == -1)
		printf("OK\n");
	else
		printf("KO\n");
}

void	check_bonus(int *tab, int len, t_stack *a)
{
	t_stack	b;

	(void)tab;
	remplir_stack_b(len, &b);
	bonus(a, &b);
	free(b.stack);
}

int	main(int ac, char *av[])
{
	t_stack	a;
	int		len;
	int		*tab;

	if (ac < 2)
		return (0);
	tab = NULL;
	len = 1;
	if (checker(av, ac, &tab, &len) == 0)
	{
		free(tab);
		return (0);
	}
	remplir_stack_a(&a, len, tab);
	free(tab);
	check_bonus(tab, len, &a);
	free(a.stack);
	return (0);
}
