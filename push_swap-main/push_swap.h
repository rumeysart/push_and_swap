/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rutatar <rutatar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 19:36:19 by rutatar           #+#    #+#             */
/*   Updated: 2024/02/15 01:04:57 by rutatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_lst
{
	long			cnt;
	struct s_lst	*nx;
}			t_lst;

typedef struct s_stack
{
	char	**all;
	t_lst	*a;
	t_lst	*b;
	int		split_count;
	int		str_count;
}			t_stack;

char	**add_list(int ac, char **av, t_stack *stack);
char	**add_list_split(char **av, t_stack *stack);
char	*get_next_line(int fd);
char	**ft_free_array(char **tab, size_t i);
void	ft_error(t_stack *stack, size_t flag);
void	check(t_stack *stack);
void	ft_del_content(void *content);
void	lstpush(t_lst **list, int number);
void	lstclear(t_lst **lst);
int		ft_atol(t_stack *stack, const char *str, int sign, long res);
int		ft_lstdup(t_lst *stack, int nbr);
int		stacksize(t_lst *a);
int		ft_quicksort_a(t_stack *stack, int len, int count);
int		ft_quicksort_b(t_stack *stack, int len, int count);
int		ft_charcount(char const *s, char c);
int		ft_push(t_lst **a, t_lst **b, int len, int operation);
int		ft_middle(int *pivot, t_lst *list, int size);
int		ft_sort_small_b(t_stack *stack, int len);
int		is_sorted(t_lst *list, char c, int len);
int		ft_sort(t_stack *stack, int size);
void	ft_sort_int_tmp(int *tmp_stack, int size);
void	ft_quick_3(t_stack *stack, int len);
void	ft_three(t_stack *stack);
void	pa(t_lst **a, t_lst **b, int print);
void	pb(t_lst **b, t_lst **a, int print);
void	rr(t_lst **a, t_lst **b, int print);
void	rrr(t_lst **a, t_lst **b, int print);
void	rotate(t_lst **stack);
void	ra(t_lst **a, int print);
void	rb(t_lst **b, int print);
void	reverse_rotate(t_lst **stack);
void	rra(t_lst **a, int print);
void	rrb(t_lst **b, int print);
void	swap(t_lst **stack);
void	sa(t_lst **a, int print);
void	sb(t_lst **b, int print);
void	ss(t_lst **a, t_lst **b, int print);
void	checker(t_stack *stack);
int		checker_control(t_stack *stack);
int		ft_strcount(char const *s, char c);
int		first_part(t_stack *stack, char *line);

#endif
