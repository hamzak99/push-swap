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

//////swap5 and 3
int		bigestone(t_element *a, int len);
int		smalestone(t_element *a, int len);
void	sort3(t_element *a, t_element *b, int lenA, int lenB);
void	sort5(t_element *a, t_element *b, int lenA, int lenB);
void	sortless10(int *a, int *b, int lenA, int lenB);
//swap more 10
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int	ft_atoi(const char *str);


#endif




//void		sa(int *tab, int len, char c);
//void		sb(int *b, int len, char c);
//void		ss(int *a, int *b, int top_a, int top_b);
//void		pa(int *a, int *b, int *top_a, int *top_b);
//void		pb(int *a, int *b, int *top_a, int *top_b);
//void		ra(int *a, int top_a, char c);
//void		rb(int *b, int top_b, char c);
//void		rr(int *a, int *b, int top_a, int top_b);
//void		rra(int *a, int top_a);
//void		rrb(int *b, int top_b);
//void		rrr(int *a, int *b, int top_a, int top_b);