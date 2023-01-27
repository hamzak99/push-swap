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

// void	sort5(t_element *a, t_element *b, int lenA, int lenB)
// {
// 	int	min;
// 	int	max;
// 	int	i;

// 	i = 0;
// 	// lenA--;
// 	min = smalestone(a, lenA);
// 	printf("smal->%d\n",min);
// 	printf("len->%d\n",lenA);
// 	printf("%d \t %d\n",a[0].nbr,b[0].nbr);
// 	printf("%d \t %d\n",a[1].nbr,b[1].nbr);
// 	printf("%d \t %d\n",a[2].nbr,b[2].nbr);
// 	printf("%d \t %d\n",a[3].nbr,b[3].nbr);
// 	printf("%d \t %d\n",a[4].nbr,b[4].nbr);
// 	while (a[0].nbr != min)
// 		ra(a, lenA);
// 	pb(a, b, &lenA, &lenB);
// 	min = smalestone(a, lenA);
// 	max = bigestone(a, lenA);
// 	while (min != a[i].nbr && a[i].nbr != max)
// 		ra(a, lenA);
// 	pb(a, b, &lenA, &lenB);
// 	sort3(a, b, lenA, lenB);
// 	if (b[0].nbr == min)
// 	{
// 		pa(a, b, &lenA, &lenB);
// 		pa(a, b, &lenA, &lenB);
// 	}
// 	if (b[0].nbr == max)
// 		swap2(a, b, &lenA, &lenB);
// 	printf("%d \t %d\n",a[0].nbr,b[0].nbr);
// 	printf("%d \t %d\n",a[1].nbr,b[1].nbr);
// 	printf("%d \t %d\n",a[2].nbr,b[2].nbr);
// 	printf("%d \t %d\n",a[3].nbr,b[3].nbr);
// 	printf("%d \t %d\n",a[4].nbr,b[4].nbr);
// }
void	sort5(t_element *a, t_element *b, int lenA, int lenB)
{
	int	min;
	int	max;
	int	i;

	i = 0;
	min = smalestone(a, lenA);
	// printf("%d\n",min);
	// printf("len->%d\n",lenA);
	// printf("%d \t %d\n",a[0].nbr,b[0].nbr);
	// printf("%d \t %d\n",a[1].nbr,b[1].nbr);
	// printf("%d \t %d\n",a[2].nbr,b[2].nbr);
	// printf("%d \t %d\n",a[3].nbr,b[3].nbr);
	// printf("%d \t %d\n",a[4].nbr,b[4].nbr);
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
// void	sort_5el(t_element *a, t_element *b, int lenA, int lenB)
// {
// 	if (findmin(a->nbr, info->x_a + 1) < 2)
// 	{
// 		while (findmin(info->tab_a, info->x_a + 1) != 4)
// 			rra(info->tab_a, info->f_e, info->x_a);
// 	}
// 	else
// 	{
// 		while (findmin(info->tab_a, info->x_a + 1) != 4)
// 			ra(info->tab_a, info->f_e, info->x_a);
// 	}
// 	pb(info);
// 	if (findmin(info->tab_a, info->x_a + 1) < 2)
// 	{
// 		while (findmin(info->tab_a, info->x_a + 1) != 3)
// 			rra(info->tab_a, info->f_e, info->x_a);
// 	}
// 	else
// 	{
// 		while (findmin(info->tab_a, info->x_a + 1) != 3)
// 			ra(info->tab_a, info->f_e, info->x_a);
// 	}
// 	pb(info);
// 	sort_3el(info);
// 	pa(info);
// 	pa(info);
// }