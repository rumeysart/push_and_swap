/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rutatar <rutatar@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:14:12 by rutatar           #+#    #+#             */
/*   Updated: 2024/01/28 15:16:29 by rutatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include "./ft_printf/ft_printf.h"

void	rra(t_lst **a, int print)
{
	reverse_rotate(a);
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_lst **b, int print)
{
	reverse_rotate(b);
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_lst **a, t_lst **b, int print)
{
	rra(a, 0);
	rrb(b, 0);
	if (print)
		ft_printf("rrr\n");
}

void	reverse_rotate(t_lst **stack)
{
	t_lst	*second_last;
	t_lst	*last;

	if (!(*stack) || !(*stack)->nx)
		return ;
	second_last = *stack;
	last = *stack;
	while (last->nx != NULL)
	{
		second_last = last;
		last = last->nx;
	}
	last->nx = *stack;
	*stack = last;
	second_last->nx = NULL;
}
