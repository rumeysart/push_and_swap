/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rutatar <rutatar@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 19:36:39 by rutatar           #+#    #+#             */
/*   Updated: 2024/02/29 07:38:07 by rutatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"
#include <unistd.h>

char	**add_list(int ac, char **av, t_stack *stack)
{
	char	**list;

	list = av + 1;
	stack->str_count = ac - 1;
	return (list);
}

char	**add_list_split(char **av, t_stack *stack)
{
	char	**list;

	list = ft_split(av[1], ' ');
	stack->split_count = 1;
	stack->str_count = ft_strcount(av[1], ' ');
	return (list);
}

void	check(t_stack *stack)
{
	int	i;
	int	nbr;

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
	i = stack->str_count - 1;
	while (i >= 0)
	{
		nbr = ft_atol(stack, stack->all[i], 1, 0);
		if (ft_lstdup(stack->a, nbr))
			return (write(2, "Error\n", 6), ft_error(stack, 1));
		lstpush(&stack->a, nbr);
		i--;
	}
}

int	main(int ac, char **av)
{
	t_stack	stack;

	stack.a = 0;
	stack.b = 0;
	stack.split_count = 0;
	if (ac < 2)
		return (0);
	else if (ac == 2)
	{
		stack.all = add_list_split(av, &stack);
		if (!stack.all)
			return (write(2, "Error\n", 6), 1);
	}
	else
		stack.all = add_list(ac, av, &stack);
	check(&stack);
	if (stack.str_count)
		ft_sort(&stack, stack.str_count);
	ft_error(&stack, 0);
	return (0);
}
