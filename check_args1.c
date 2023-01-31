/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkasbaou <hkasbaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:53:25 by hkasbaou          #+#    #+#             */
/*   Updated: 2023/01/29 14:53:26 by hkasbaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = ft_strlen(str);
	if (!(char)c)
		return ((char *)str + i);
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i--;
	}
	return (0);
}

void	freestr(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i++]);
	}
	free(str);
}

int	chek_max_int(long nbr)
{
	if (nbr > INT_MAX)
	{
		printf("ERROR");
		return (1);
	}
	return (0);
}

int	more_than_one(char *str, int **vars, int j, char **spliter)
{
	static int	k;
	long		nbr;

	if (ft_strrchr(str, ' '))
	{
		j = 0;
		spliter = ft_split(str, ' ');
		while (spliter[j] != NULL)
		{
			nbr = ft_atoi(spliter[j]);
			if (chek_max_int(nbr))
				return (0);
			(*vars)[k++] = ft_atoi(spliter[j++]);
		}
		freestr(spliter);
	}
	else
	{
		nbr = ft_atoi(str);
		if (chek_max_int(nbr))
			return (0);
		(*vars)[k++] = ft_atoi(str);
	}
	return (1);
}

int	remplir_a(int ac, char **av, int *vars, int *len)
{
	int		i;
	int		j;
	int		k;
	char	**str;

	(void)len;
	str = NULL;
	i = 0;
	k = 0;
	while (++i < ac)
	{
		j = 0;
		if (!more_than_one(av[i], &vars, j, str))
			return (0);
	}
	return (1);
}
