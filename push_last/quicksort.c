/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rutatar <rutatar@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:16:46 by rutatar           #+#    #+#             */
/*   Updated: 2024/02/22 15:26:35 by rutatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort(t_stack *stack, int size)
{
	if (is_sorted(stack->a, 'a', size) == 0)
	{
		if (size == 2)
			sa(&stack->a, 1);
		else if (size == 3)
			ft_three(stack);
		else
			ft_quicksort_a(stack, stack->str_count, 0);
	}
	return (0);
}

int	is_sorted(t_lst *list, char c, int len)
{
	while (c == 'a' && --len)
	{
		if (list->cnt > list->nx->cnt)
			return (0);
		list = list->nx;
	}
	while (c == 'b' && --len)
	{
		if (list->cnt < list->nx->cnt)
			return (0);
		list = list->nx;
	}
	return (1);
}

void	ft_quick_3(t_stack *stack, int len)
{
	if (len == 3 && stacksize(stack->a) == 3)
		ft_three(stack);
	else if (len == 2)
	{
		if (stack->a->cnt > stack->a->nx->cnt)
			sa(&stack->a, 1);
	}
	else if (len == 3)
	{
		while (len != 3 || !(stack->a->cnt < stack->a->nx->cnt
				&& stack->a->nx->cnt < stack->a->nx->nx->cnt))
		{
			if (len == 3 && stack->a->cnt > stack->a->nx->cnt
				&& stack->a->nx->nx->cnt)
				sa(&stack->a, 1);
			else if (len == 3 && !(stack->a->nx->nx->cnt > stack->a->cnt
					&& stack->a->nx->nx->cnt > stack->a->nx->cnt))
				len = ft_push(&stack->a, &stack->b, len, 0);
			else if (stack->a->cnt > stack->a->nx->cnt)
				sa(&stack->a, 1);
			else if (len++)
				pa(&stack->a, &stack->b, 1);
		}
	}
}

int	ft_quicksort_a(t_stack *stack, int len, int count)
{
	int	pivot;
	int	items;

	if (is_sorted(stack->a, 'a', len) == 1)
		return (1);
	items = len;
	if (len <= 3)
	{
		ft_quick_3(stack, len);
		return (1);
	}
	if (!ft_middle(&pivot, stack->a, len))
		return (0);
	while (len != items / 2 + items % 2)
	{
		if (stack->a->cnt < pivot && (len--))
			pb(&stack->b, &stack->a, 1);
		else if (++count)
			ra(&stack->a, 1);
	}
	while (items / 2 + items % 2 != stacksize(stack->a) && count--)
		rra(&stack->a, 1);
	return (ft_quicksort_a(stack, items / 2 + items % 2, 0)
		&& ft_quicksort_b(stack, items / 2, 0));
}

int	ft_quicksort_b(t_stack *stack, int len, int count)
{
	int	pivot;
	int	items;

	if (is_sorted(stack->b, 'b', len) == 1)
		while (len--)
			pa(&stack->a, &stack->b, 1);
	if (len <= 3)
	{
		ft_sort_small_b(stack, len);
		return (1);
	}
	items = len;
	if (!ft_middle(&pivot, stack->b, len))
		return (0);
	while (len != items / 2)
	{
		if (stack->b->cnt >= pivot && (len--))
			pa(&stack->a, &stack->b, 1);
		else if (++count)
			rb(&stack->b, 1);
	}
	while (items / 2 != stacksize(stack->b) && count--)
		rrb(&stack->b, 1);
	return (ft_quicksort_a(stack, items / 2 + items % 2, 0)
		&& ft_quicksort_b(stack, items / 2, 0));
}
