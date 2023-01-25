/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkasbaou <hkasbaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:55:24 by hkasbaou          #+#    #+#             */
/*   Updated: 2022/12/11 14:32:22 by hkasbaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <limits.h>

typedef struct s_element
{
	int nbr;
	int pos;
} t_element;

typedef struct s_stack
{
	t_element *stack;
	int size;
} t_stack;

void		sa(t_element *tab, int len);
void		sb(t_element *b, int len);
void		ss(t_element *a, t_element *b, int top_a, int top_b);
void		pa(t_element *a, t_element *b, int *top_a, int *top_b);
void		pb(t_element *a, t_element *b, int *top_a, int *top_b);
void		ra(t_element *a, int top_a);
void		rb(t_element *b, int top_b);
void		rr(t_element *a, t_element *b, int top_a, int top_b);
void		rra(t_element *a, int top_a);
void		rrb(t_element *b, int top_b);
void		rrr(t_element *a, t_element *b, int top_a, int top_b);
//
int checker(char **av, int ac,int **tab,int *len);
int check_if_sorted(int *vars, int len);
//////swap5 and 3
int		bigestone(t_element *a, int len);
int		smalestone(t_element *a, int len);
void	sort3(t_element *a, t_element *b, int lenA, int lenB);
void	sort5(t_element *a, t_element *b, int lenA, int lenB);
void 	sort15(t_stack *a,t_stack *b);
void sort_big(t_stack *a,t_stack *b,int range);
//swap more 10
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int	ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
int	ft_strncmp(const char *str1, const char *str2, size_t n);
char	**ft_split(char *s, char c);
char	*ft_strrchr(const char *str, int c);


#endif
