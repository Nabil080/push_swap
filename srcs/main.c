/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:19:49 by nbellila          #+#    #+#             */
/*   Updated: 2024/06/20 19:34:01 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_sorted(t_list *stack)
{
	t_list	*itered;

	while (stack->next)
	{
		itered = stack->next;
		while (itered)
		{
			if (ft_lsttoi(stack) < ft_lsttoi(itered))
				return (0);
			itered = itered->next;
		}
		stack = stack->next;
	}
	return (1);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

	args_check(argc, argv);
	a = parse_as_lst(argc, argv);
	if (!a)
		exit_malloc();
	b = NULL;
	push_swap_sort(&a, &b);
	exit_success(a, b);
}
