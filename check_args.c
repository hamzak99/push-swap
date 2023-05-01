/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkasbaou <hkasbaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:25:13 by hkasbaou          #+#    #+#             */
/*   Updated: 2023/02/11 19:12:43 by hkasbaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int	check_num(char *av)
{
	int	i;

	i = 0;
	if (av[0] == '\0')
		return (0);
	while (av[i] == ' ' || av[i] == '-' || av[i] == '+')
	{
		i++;
	}
	if (av[i] == '\0')
		return (0);
	i = 0;
	while (av[i] != '\0')
	{
		if (!((av[i] >= '0' && av[i] <= '9') || av[i] == ' ' || av[i] == '-'
				|| av[i] == '+'))
			return (0);
		i++;
	}
	return (1);
}

int	check_if_all_num(char **av, int ac, int *len)
{
	int		i;
	int		k;
	char	**str;

	i = 1;
	while (i < ac)
	{
		k = 0;
		if (check_num(av[i]) == 0)
			return (0);
		if (ft_strrchr(av[i], ' '))
		{
			str = ft_split(av[i], ' ');
			while (str[k] != NULL)
				k++;
			(*len) += k;
			freestr(str);
		}
		else
			(*len)++;
		i++;
	}
	return (1);
}

int	check_if_sorted(int *vars, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (vars[i] > vars[i + 1] && (i + 1) != len)
			return (0);
		i++;
	}
	return (1);
}

int	check_if_repet(int *vars, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (vars[i] == vars[j] && i != j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	checker(char **av, int ac, int **tab, int *len)
{
	int	i;
	int	tru;

	tru = *len;
	*len = 0;
	i = 0;
	if (check_if_all_num(av, ac, len) == 0)
	{
		write(1, "ERROR", 5);
		return (0);
	}
	*tab = malloc((*len) * sizeof(int));
	if (!remplir_a(ac, av, *tab, len))
		return (0);
	if (tru == 0)
		if (check_if_sorted(*tab, *len))
			return (0);
	if (check_if_repet(*tab, *len))
	{
		write(1, "ERROR", 5);
		return (0);
	}
	return (1);
}
