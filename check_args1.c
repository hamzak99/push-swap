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

void freestr(char **str)
{
	int i;
	i = 0;
	while (str[i] != NULL)
	{
		free(str[i++]);
	}
	free(str);
}

int chek_max_int(long nbr)
{
	if(nbr > INT_MAX)
		return 1;
	return 0;
}

int remplir_a(int ac,char **av,int *vars,int *len)
{
	int i;
	int j;
	long nbr;
	int k;
	char **str;
	(void)len;

	i = 1;
	k = 0;
	while (i < ac)
	{
		if(ft_strrchr(av[i], ' '))
		{
			j = 0;
			str = ft_split(av[i], ' ');
			while (str[j] != NULL)
			{
				nbr = ft_atoi(str[j]);
				if(chek_max_int(nbr))
					return 0;
				vars[k++] = ft_atoi(str[j++]);
			}
			freestr(str);
		}
		else
		{
			nbr = ft_atoi(av[i]);
			if(chek_max_int(nbr))
					return 0;
			vars[k++] = ft_atoi(av[i]);
		}
		i++;
	}
	return 1;
}