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

int	bigestone(int *a, int len)
{
	int	i;
	int	max;
	int	j;

	i = 0;
	max = a[0];
	j = 0;
	while (i <= len + 1)
	{
		if (a[i] == 0)
			a[i] = 0;
		else if (max < a[i])
			max = a[i];
		i++;
	}
	return (max);
}

int	smalestone(int *a, int len)
{
	int	i;
	int	min;
	int	j;

	i = 0;
	min = a[0];
	j = 0;
	while (i <= len)
	{
		if (a[i] == 0)
			a[i] = 0;
		else if (min > a[i])
			min = a[i];
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
	if (a[0].nbr >= a[1].nbr && a[1].nbr >= a[2].nbr && a[0].nbr >= a[2].nbr)
	{
		sa(a, lenA);
		rra(a, lenA);
	}
	if (a[0].nbr >= a[1].nbr && a[1].nbr <= a[2].nbr && a[0].nbr >= a[2].nbr)
		ra(a, lenA);
	if (a[0].nbr <= a[1].nbr && a[1].nbr >= a[2].nbr && a[0].nbr <= a[2].nbr)
	{
		sa(a, lenA);
		ra(a, lenA);
	}
	if (a[0].nbr <= a[1].nbr && a[1].nbr >= a[2].nbr && a[0].nbr >= a[2].nbr)
		rra(a, lenA);
}

// void	swap2(int *a, int *b, int *lenA, int *lenB)
// {
// 	pa(a, b, lenA, lenB);
// 	ra(a, *lenA);
// 	pa(a, b, lenA, lenB);
// }

// void	sort5(int *a, int *b, int lenA, int lenB)
// {
// 	int	min;
// 	int	max;
// 	int	i;

// 	i = 0;
// 	min = smalestone(a, lenA);
// 	while (a[0] != min)
// 		ra(a, lenA);
// 	pb(a, b, &lenA, &lenB);
// 	min = smalestone(a, lenA);
// 	max = bigestone(a, lenA);
// 	while (min != a[i] && a[i] != max)
// 		ra(a, lenA);
// 	pb(a, b, &lenA, &lenB);
// 	sort3(a, b, lenA, lenB);
// 	if (b[0] == min)
// 	{
// 		pa(a, b, &lenA, &lenB);
// 		pa(a, b, &lenA, &lenB);
// 	}
// 	if (b[0] == max)
// 		swap2(a, b, &lenA, &lenB);
// }
