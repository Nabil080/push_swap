/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:49:26 by nbellila          #+#    #+#             */
/*   Updated: 2024/06/20 19:08:34 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*stack_max(t_list *stack)
{
	t_list	*max;
	t_list	*current;

	max = stack;
	current = stack->next;
	while (current)
	{
		if (ft_lsttoi(max) < ft_lsttoi(current))
			max = current;
		current = current->next;
	}
	return (max);
}

t_list	*stack_min(t_list *stack)
{
	t_list	*min;
	t_list	*current;

	min = stack;
	current = stack->next;
	while (current)
	{
		if (ft_lsttoi(min) > ft_lsttoi(current))
			min = current;
		current = current->next;
	}
	return (min);
}

t_list	*stack_closest_inferior(t_list *stack, int nb)
{
	t_list	*closest;

	if (nb < ft_lsttoi(stack_min(stack)))
		return (stack_max(stack));
	closest = NULL;
	while (stack)
	{
		if (nb > ft_lsttoi(stack))
			if (!closest || nb - ft_lsttoi(stack) < nb - ft_lsttoi(closest))
				closest = stack;
		stack = stack->next;
	}
	return (closest);
}

t_list	*stack_closest_superior(t_list *stack, int nb)
{
	t_list	*closest;

	if (nb > ft_lsttoi(stack_max(stack)))
		return (stack_min(stack));
	closest = NULL;
	while (stack)
	{
		if (nb < ft_lsttoi(stack))
			if (!closest || nb - ft_lsttoi(stack) > nb - ft_lsttoi(closest))
				closest = stack;
		stack = stack->next;
	}
	return (closest);
}
