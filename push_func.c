/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkasbaou <hkasbaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:02:18 by hkasbaou          #+#    #+#             */
/*   Updated: 2023/02/02 21:59:28 by hkasbaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	rrr(t_element *a, t_element *b, int top_a, int top_b)
{
	rra(a, top_a);
	rrb(b, top_b);
	write(1, "rrr\n", 4);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;

	s = malloc(count * size);
	if (!s)
		return (0);
	ft_bzero(s, count * size);
	return (s);
}

static int	space(char str)
{
	if (str == ' ' || str == '\r' || str == '\f' || str == '\v' || str == '\n'
		|| str == '\t')
		return (1);
	return (0);
}

long	ft_atoi(const char *str)
{
	long	i;
	int		sign;
	long	rsl;

	rsl = 0;
	i = 0;
	sign = 1;
	while (space(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		rsl = str[i] + (rsl * 10) - '0';
		i++;
	}
	return (rsl * sign);
}
