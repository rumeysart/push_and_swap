/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rutatar <rutatar@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:17:16 by rutatar           #+#    #+#             */
/*   Updated: 2024/02/29 07:35:34 by rutatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"
#include <unistd.h>

void	checker(t_stack *stack)
{
	int	i;
	int	num;

	i = 0;
	while (i < stack->str_count)
	{
		if (ft_isdigit(stack->all[i]))
		{
			if (stack->split_count)
				ft_free_array(stack->all, 0);
			return (write(2, "Error\n", 6), exit(1));
		}
		i++;
	}
	while (--i > -1)
	{
		num = ft_atol(stack, stack->all[i], 1, 0);
		if (ft_lstdup(stack->a, num))
			return (write(2, "Error\n", 6), ft_error(stack, 1));
		lstpush(&stack->a, num);
	}
	if (checker_control(stack))
		return (ft_printf("OK\n"), ft_error(stack, 1));
	return (write(2, "KO\n", 3), ft_error(stack, 1));
}

int	checker_control(t_stack *stack)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (first_part(stack, line))
			;
		else
		{
			write(2, "Error\n", 6);
			return (free(line), ft_error(stack, 1), 1);
		}
		free(line);
		line = get_next_line(0);
	}
	if (!is_sorted(stack->a, 'a', stack->str_count) || stacksize(stack->b))
		return (0);
	return (1);
}

int	first_part(t_stack *stack, char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		sa(&stack->a, 0);
	else if (!ft_strcmp(line, "sb\n"))
		sb(&stack->b, 0);
	else if (!ft_strcmp(line, "ss\n"))
		ss(&stack->a, &stack->b, 0);
	else if (!ft_strcmp(line, "pa\n"))
		pa(&stack->a, &stack->b, 0);
	else if (!ft_strcmp(line, "pb\n"))
		pb(&stack->b, &stack->a, 0);
	else if (!ft_strcmp(line, "ra\n"))
		ra(&stack->a, 0);
	else if (!ft_strcmp(line, "rb\n"))
		rb(&stack->b, 0);
	else if (!ft_strcmp(line, "rr\n"))
		rr(&stack->a, &stack->b, 0);
	else if (!ft_strcmp(line, "rra\n"))
		rra(&stack->a, 0);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb(&stack->b, 0);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(&stack->a, &stack->b, 0);
	else
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	stack;

	stack.a = (void *)0;
	stack.b = (void *)0;
	stack.split_count = 0;
	if (ac == 1)
		return (0);
	if (ac == 2)
	{
		stack.all = ft_split(av[1], 32);
		if (!stack.all)
			return (write(2, "Error\n", 6), ft_error(&stack, 1), 1);
		stack.split_count = 1;
		stack.str_count = ft_strcount(av[1], 32);
		if (stack.str_count == 0)
			return (write(2, "Error\n", 6), ft_free_array(stack.all, 0), 0);
	}
	else
	{
		stack.all = av + 1;
		stack.str_count = ac - 1;
	}
	return (checker(&stack), 0);
}
