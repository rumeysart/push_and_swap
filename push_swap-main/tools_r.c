/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rutatar <rutatar@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:14:29 by rutatar           #+#    #+#             */
/*   Updated: 2024/01/28 15:16:05 by rutatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./ft_printf/ft_printf.h"
#include <stdlib.h>

void	ra(t_lst **a, int print)
{
	if (stacksize(*a) > 1)
	{
		rotate(a);
		if (print)
			ft_printf("ra\n");
	}
}

void	rb(t_lst **b, int print)
{
	if (stacksize(*b) > 1)
	{
		rotate(b);
		if (print)
			ft_printf("rb\n");
	}
}

void	rr(t_lst **a, t_lst **b, int print)
{
	ra(a, 0);
	rb(b, 0);
	if (print)
		ft_printf("rr\n");
}

void	rotate(t_lst **stack)
{
	t_lst	*first;
	t_lst	*last;

	if (!(*stack) || !(*stack)->nx)
		return ;
	first = *stack;
	last = *stack;
	while (last->nx != NULL)
		last = last->nx;
	*stack = (*stack)->nx;
	last->nx = first;
	first->nx = NULL;
}
