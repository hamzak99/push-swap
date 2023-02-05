/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_3_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkasbaou <hkasbaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:07:38 by hkasbaou          #+#    #+#             */
/*   Updated: 2023/02/04 19:32:50 by hkasbaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bigestone(t_element *a, int len)
{
	int	i;
	int	max;
	int	j;

	i = 0;
	max = a[0].nbr;
	j = 0;
	while (i <= len + 1)
	{
		if (a[i].nbr == 0)
			a[i].nbr = 0;
		else if (max < a[i].nbr)
			max = a[i].nbr;
		i++;
	}
	return (max);
}

int	smalestone(t_element *a, int len)
{
	int	i;
	int	min;
	int	ind;
	int	j;

	i = 0;
	min = a[0].nbr;
	ind = 0;
	j = 0;
	while (i < len)
	{
		if (a[i].nbr == 0)
			a[i].nbr = 0;
		else if (min > a[i].nbr)
		{
			min = a[i].nbr;
			ind = i;
		}
		i++;
	}
	return (ind);
}

void	sort3(t_element *a, t_element *b, int lenA, int lenB)
{
	(void)lenA;
	(void)lenB;
	(void)b;
	if (a[0].nbr >= a[1].nbr && a[1].nbr <= a[2].nbr && a[0].nbr <= a[2].nbr)
		sa(a, lenA);
	else if (a[0].nbr >= a[1].nbr && a[1].nbr >= a[2].nbr
		&& a[0].nbr >= a[2].nbr)
	{
		sa(a, lenA);
		rra(a, lenA);
	}
	else if (a[0].nbr >= a[1].nbr && a[1].nbr <= a[2].nbr
		&& a[0].nbr >= a[2].nbr)
		ra(a, lenA);
	else if (a[0].nbr <= a[1].nbr && a[1].nbr >= a[2].nbr
		&& a[0].nbr <= a[2].nbr)
	{
		sa(a, lenA);
		ra(a, lenA);
	}
	else if (a[0].nbr <= a[1].nbr && a[1].nbr >= a[2].nbr
		&& a[0].nbr >= a[2].nbr)
		rra(a, lenA);
}

void	swap2(t_element *a, t_element *b, int *lenA, int *lenB)
{
	pa(a, b, lenA, lenB);
	ra(a, *lenA);
	pa(a, b, lenA, lenB);
}

void	sort5(t_element *a, t_element *b, int lenA, int lenB)
{
	int	i;

	i = smalestone(a, lenA);
	if (i < 2)
		while (i-- > 0)
			ra(a, lenA);
	else
		while (i++ < lenA)
			rra(a, lenA);
	pb(a, b, &lenA, &lenB);
	i = smalestone(a, lenA);
	if (i < 2)
		while (i-- > 0)
			ra(a, lenA);
	else
		while (i++ < lenA)
			rra(a, lenA);
	pb(a, b, &lenA, &lenB);
	sort3(a, b, lenA, lenB);
	pa(a, b, &lenA, &lenB);
	pa(a, b, &lenA, &lenB);
}
