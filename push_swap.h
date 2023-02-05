/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkasbaou <hkasbaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:55:24 by hkasbaou          #+#    #+#             */
/*   Updated: 2023/02/04 20:15:53 by hkasbaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_element
{
	int			nbr;
	int			pos;
}				t_element;

typedef struct s_stack
{
	t_element	*stack;
	int			size;
}				t_stack;

void			sa(t_element *tab, int len);
void			sb(t_element *b, int len);
void			ss(t_element *a, t_element *b, int top_a, int top_b);
void			pa(t_element *a, t_element *b, int *top_a, int *top_b);
void			pb(t_element *a, t_element *b, int *top_a, int *top_b);
void			ra(t_element *a, int top_a);
void			rb(t_element *b, int top_b);
void			rr(t_element *a, t_element *b, int top_a, int top_b);
void			rra(t_element *a, int top_a);
void			rrb(t_element *b, int top_b);
void			rrr(t_element *a, t_element *b, int top_a, int top_b);
//
int				checker(char **av, int ac, int **tab, int *len);
int				check_if_sorted(int *vars, int len);
// void print(t_stack a,t_stack b,int len);
//////swap5 and 3
void			push_range(t_stack *a, t_stack *b, int range);
int				check_if_in_down(t_stack *a, int ind, int range);
int				bigestone(t_element *a, int len);
int				smalestone(t_element *a, int len);
void			sort3(t_element *a, t_element *b, int lenA, int lenB);
void			sort5(t_element *a, t_element *b, int lenA, int lenB);
void			sort15(t_stack *a, t_stack *b);
void			sort_big(t_stack *a, t_stack *b, int range);
int				get_index(t_stack *arr);
void			remplir_0(t_element *arr);
//swap more 10
void			stack_a_creator(int *tab, int *tab_sorted, int len,
					t_stack *stack_a);
void			stack_b_creator(int len, t_stack *stack_b);
void			freeall(t_stack *a, t_stack *b, int **tab, int **tab_sorted);
//
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
long			ft_atoi(const char *str);
size_t			ft_strlen(const char *s);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
char			**ft_split(char *s, char c);
char			*ft_strrchr(const char *str, int c);
void			freestr(char **str);
int				remplir_a(int ac, char **av, int *vars, int *len);
//
void			sa_b(t_element *tab, int len);
void			sb_b(t_element *b, int len);
void			ss_b(t_element *a, t_element *b, int top_a, int top_b);
void			pa_b(t_element *a, t_element *b, int *top_a, int *top_b);
void			pb_b(t_element *a, t_element *b, int *top_a, int *top_b);
void			ra_b(t_element *a, int top_a);
void			rb_b(t_element *b, int top_b);
void			rr_b(t_element *a, t_element *b, int top_a, int top_b);
void			rra_b(t_element *a, int top_a);
void			rrb_b(t_element *b, int top_b);
void			rrr_b(t_element *a, t_element *b, int top_a, int top_b);
//
void			remplir_stack_b(int len, t_stack *stack_b);
void			remplir_stack_a(t_stack *a, int len, int *tab);
#endif
