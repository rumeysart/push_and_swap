/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rutatar <rutatar@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:13:45 by rutatar           #+#    #+#             */
/*   Updated: 2024/02/29 07:30:33 by rutatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

int	ft_lstdup(t_lst *stack, int nbr)
{
	if (!stack)
		return (0);
	if (stack->cnt == nbr)
		return (1);
	return (ft_lstdup(stack->nx, nbr));
}

void	ft_error(t_stack *stack, size_t flag)
{
	if (stack->split_count)
		ft_free_array(stack->all, 0);
	lstclear(&stack->a);
	lstclear(&stack->b);
	if (flag == 1)
		exit (1);
}

int	ft_atol(t_stack *stack, const char *str, int sign, long res)
{
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-')
		sign = -1;
	if ((*str == '+' || *str == '-') && !(*++str >= '0' && *str <= '9'))
		return (write(2, "Error\n", 6), ft_error(stack, 1), 0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (write(2, "Error\n", 6), ft_error(stack, 1), 0);
		res = (*str - '0') + (res * 10);
		if ((res > 2147483648 && sign == -1) || (res > 2147483647 && sign == 1))
			return (write(2, "Error\n", 6), ft_error(stack, 1), 0);
		str++;
	}
	return (res * sign);
}
