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

int check_num(char *av)
{
	int i;

	i = 0;
	while (av[i] != '\0')
	{
		if(!((av[i] >= '0' && av[i] <= '9') || av[i] == ' ' || av[i] == '-' || av[i] == '+'))
			return 0;
		i++;
	}
	return 1;
}
int chek_max_int(long nbr)
{
	// printf("%ld \t %d\n",nbr,INT_MAX);
	if(nbr > INT_MAX)
	{
		printf("ERROR");
		return 1;
	}
	return 0;
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

int check_if_all_num(char **av, int ac, int *len)
{
	int i;
	int k;
	char **str;
	i = 1;
	while (i < ac)
	{
		k = 0;
		if(check_num(av[i]) == 0)
			return 0;
		if(ft_strrchr(av[i], ' '))
		{
			str = ft_split(av[i],' ');
			while (str[k] != NULL)
				k++;
			(*len)+= k;
			freestr(str);
		}
		else
			(*len)++;
		i++;
	}
	return 1;
}

int check_if_sorted(int *vars, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		// printf("len=%d \t i =%d\n",len,i);
		// printf("%d \t %d\n",vars[i],INT_MAX);
		if( vars[i] > INT_MAX)
			return 0;
		if( vars[i] > vars[i + 1] && (i + 1) != len)
		// printf("i=%d \t i+1=%d\n",vars[i],vars[i + 1]);
			return 0;
		i++;
	}
	return 1;
}

int check_if_repet(int *vars,int len)
{
	int i;
	int j;

	i = 0;
	while (i < len)
	{
		j = 0 ;
		while (j < len)
		{
			if(vars[i] == vars[j] && i != j)
				return 1;
			j++;
		}
		i++;
	}
	return 0;
}

int checker(char **av, int ac,int **tab,int *len)
{
	int i;
	i = 0;
	if(check_if_all_num(av,ac,len) == 0)
	{
		printf("ERROR");
		return 0;
	}
	
	*tab = malloc((*len) * sizeof(int));
	if(!remplir_a(ac,av,*tab,len))
	{
		return 0;
	}
	if(check_if_sorted(*tab,*len))
		return 0;
	if(check_if_repet(*tab,*len))
	{
		printf("ERROR");
		return 0;
	}
	return 1;
}


