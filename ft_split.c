#include "push_swap.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (s);
}
// void	ft_bzero(void *s, size_t n)
// {
// 	ft_memset(s, '\0', n);
// }
// void	*ft_calloc(size_t count, size_t size)
// {
// 	void	*s;

// 	s = malloc(count * size);
// 	if (!s)
// 		return (0);
// 	ft_bzero(s, count * size);
// 	return (s);
// }

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	if (!s)
// 		return (0);
// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

static int	counting(char const *s, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
			if (s[i] != 0)
				cnt++;
		}
		else
			i++;
	}
	return (cnt + 1);
}

static char	**find_word(const char *s, char c, char **ss, int i)
{
	int	wrd;
	int	cnt;

	cnt = 0;
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		wrd = 0;
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			wrd++;
			i++;
		}
		ss[cnt] = ft_calloc(sizeof(char), (wrd + 1));
		if (!ss)
			return (NULL);
		cnt++;
		while (s[i] == c && s[i] != '\0')
			i++;
	}
	return (ss);
}

static char	**fill(char *s, char c, char **ss)
{
	int	wrd;
	int	i;

	wrd = 0;
	while (*s == c)
		s++;
	while (*s != '\0')
	{
		i = 0;
		while (*s == c && *s != '\0')
			s++;
		while (*s != c && *s != '\0')
		{
			ss[wrd][i++] = *s;
			s++;
		}
		wrd++;
	}
	return (ss);
}

char	**ft_split(char *s, char c)
{
	char	**ss;
	int		wrd;
	int		i;
	int		cnt;

	if (!s)
		return (NULL);
	if (!*s)
		return (ft_calloc(sizeof(char *), 1));
	cnt = 0;
	i = 0;
	wrd = counting(s, c);
	ss = ft_calloc(wrd + 1, sizeof(char *));
	if (!ss)
		return (NULL);
	if (!*s)
		return (ss);
	ss = find_word(s, c, ss, i);
	ss = fill(s, c, ss);
	return (ss);
}
