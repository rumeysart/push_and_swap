/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rutatar <rutatar@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:16:38 by rutatar           #+#    #+#             */
/*   Updated: 2024/01/28 15:16:41 by rutatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./ft_printf/ft_printf.h"

void	pa(t_lst **a, t_lst **b, int print)
{
	t_lst	*first_b;
	t_lst	*second_b;

	if (!*b)
		return ;
	first_b = *b;
	second_b = (*b)->nx;
	*b = second_b;
	first_b->nx = *a;
	*a = first_b;
	if (print)
		ft_printf("pa\n");
}

void	pb(t_lst **b, t_lst **a, int print)
{
	t_lst	*first_a;
	t_lst	*second_a;

	if (!*a)
		return ;
	first_a = *a;
	second_a = (*a)->nx;
	*a = second_a;
	first_a->nx = *b;
	*b = first_a;
	if (print)
		ft_printf("pb\n");
}
