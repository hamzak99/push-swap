/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_3_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkasbaou <hkasbaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:04:52 by hkasbaou          #+#    #+#             */
/*   Updated: 2022/11/20 23:44:40 by hkasbaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// 
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
	int	j;

	i = 0;
	min = a[0].nbr;
	j = 0;
	while (i < len)
	{
		if (a[i].nbr == 0)
			a[i].nbr = 0;
		else if (min > a[i].nbr)
			min = a[i].nbr;
		i++;
	}
	return (min);
}

void	sort3(t_element *a, t_element *b, int lenA, int lenB)
{
	(void)lenA;
	(void)lenB;
	(void)b;
	if (a[0].nbr >= a[1].nbr && a[1].nbr <= a[2].nbr && a[0].nbr <= a[2].nbr)
		sa(a, lenA);
	else if (a[0].nbr >= a[1].nbr && a[1].nbr >= a[2].nbr && a[0].nbr >= a[2].nbr)
	{
		sa(a, lenA);
		rra(a, lenA);
	}
	else if (a[0].nbr >= a[1].nbr && a[1].nbr <= a[2].nbr && a[0].nbr >= a[2].nbr)
		ra(a, lenA);
	else if (a[0].nbr <= a[1].nbr && a[1].nbr >= a[2].nbr && a[0].nbr <= a[2].nbr)
	{
		sa(a, lenA);
		ra(a, lenA);
	}
	else if (a[0].nbr <= a[1].nbr && a[1].nbr >= a[2].nbr && a[0].nbr >= a[2].nbr)
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
	int	min;
	int	max;
	int	i;

	i = 0;
	min = smalestone(a, lenA);
	while (a[0].nbr != min)
		ra(a, lenA);
	pb(a, b, &lenA, &lenB);
	min = smalestone(a, lenA);
	max = bigestone(a, lenA);
	while (min != a[i].nbr && a[i].nbr != max)
		ra(a, lenA);
	pb(a, b, &lenA, &lenB);
	sort3(a, b, lenA, lenB);
	if (b[0].nbr == min)
	{
		pa(a, b, &lenA, &lenB);
		pa(a, b, &lenA, &lenB);
	}
	if (b[0].nbr == max)
		swap2(a, b, &lenA, &lenB);
}