/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rutatar <rutatar@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:13:37 by rutatar           #+#    #+#             */
/*   Updated: 2024/01/28 15:13:40 by rutatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	lstpush(t_lst **list, int number)
{
	t_lst	*new;

	new = (t_lst *)malloc(sizeof(t_lst));
	if (!list || !new)
		return ;
	new->cnt = number;
	new->nx = *list;
	*list = new;
}

int	stacksize(t_lst *a)
{
	int	i;

	if (!a)
		return (0);
	i = 0;
	while (a->nx != NULL)
	{
		a = a->nx;
		i++;
	}
	return (i + 1);
}

void	lstclear(t_lst **lst)
{
	t_lst	*contents;

	if (!lst)
		return ;
	while (*lst)
	{
		contents = (*lst);
		*lst = (*lst)->nx;
		free(contents);
	}
}

int	ft_sort_small_b(t_stack *stack, int len)
{
	if (len == 1)
		pa(&stack->a, &stack->b, 1);
	else if (len == 2)
	{
		if (stack->b->cnt < stack->b->nx->cnt)
			sb(&stack->b, 1);
		while (len--)
			pa(&stack->a, &stack->b, 1);
	}
	else if (len == 3)
	{
		while (len || !(stack->a->cnt < stack->a->nx->cnt
				&& stack->a->nx->cnt < stack->a->nx->nx->cnt))
		{
			if (len == 1 && stack->a->cnt > stack->a->nx->cnt)
				sa(&stack->a, 1);
			else if (len == 1 || (len >= 2 && stack->b->cnt > stack->b->nx->cnt)
				|| (len == 3 && stack->b->cnt > stack->b->nx->nx->cnt))
				len = ft_push(&stack->a, &stack->b, len, 1);
			else
				sb(&stack->b, 1);
		}
	}
	return (0);
}
