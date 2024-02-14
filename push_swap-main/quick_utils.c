/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rutatar <rutatar@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:16:53 by rutatar           #+#    #+#             */
/*   Updated: 2024/01/28 15:16:55 by rutatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	ft_push(t_lst **a, t_lst **b, int len, int operation)
{
	if (operation == 0)
		pb(b, a, 1);
	else
		pa(a, b, 1);
	len--;
	return (len);
}

void	ft_sort_int_tmp(int *tmp_stack, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tmp_stack[i] > tmp_stack[j])
			{
				tmp = tmp_stack[i];
				tmp_stack[i] = tmp_stack[j];
				tmp_stack[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static void	ft_three_2(t_stack *stack)
{
	if ((stack->a)->cnt < (stack->a)->nx->cnt
		&& (stack->a)->cnt < (stack->a)->nx->nx->cnt
		&& (stack->a)->nx->cnt > (stack->a)->nx->nx->cnt)
	{
		sa(&stack->a, 1);
		ra(&stack->a, 1);
	}
	if ((stack->a)->cnt < (stack->a)->nx->cnt
		&& (stack->a)->cnt > (stack->a)->nx->nx->cnt
		&& (stack->a)->nx->cnt > (stack->a)->nx->nx->cnt)
		rra(&stack->a, 1);
}

void	ft_three(t_stack *stack)
{
	if ((stack->a)->cnt > (stack->a)->nx->cnt
		&& (stack->a)->cnt < (stack->a)->nx->nx->cnt
		&& (stack->a)->nx->cnt < (stack->a)->nx->nx->cnt)
		sa(&stack->a, 1);
	if ((stack->a)->cnt > (stack->a)->nx->cnt
		&& (stack->a)->cnt > (stack->a)->nx->nx->cnt
		&& (stack->a)->nx->cnt > (stack->a)->nx->nx->cnt)
	{
		sa(&stack->a, 1);
		rra(&stack->a, 1);
	}
	if ((stack->a)->cnt > (stack->a)->nx->cnt
		&& (stack->a)->cnt > (stack->a)->nx->nx->cnt
		&& (stack->a)->nx->cnt < (stack->a)->nx->nx->cnt)
		ra(&stack->a, 1);
	ft_three_2(stack);
}

int	ft_middle(int *pivot, t_lst *list, int size)
{
	int	i;
	int	*tmp;

	tmp = (int *)malloc(sizeof(int) * size);
	if (!tmp)
		return (0);
	i = 0;
	while (i < size)
	{
		tmp[i] = list->cnt;
		list = list->nx;
		i++;
	}
	ft_sort_int_tmp(tmp, size);
	*pivot = tmp[size / 2];
	free(tmp);
	return (1);
}
