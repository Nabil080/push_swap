/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:12:29 by nbellila          #+#    #+#             */
/*   Updated: 2024/06/20 12:38:37 by nbellila         ###   ########.fr       */
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
		if (*(int*)max->content < *(int*)current->content)
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
		if (*(int*)min->content > *(int*)current->content)
			min = current;
		current = current->next;
	}
	return (min);
}

t_list	*stack_closest(t_list *stack, int nb)
{
	t_list	*closest;
	t_list	*current;
	int		current_nb;

	closest = stack;
	current = closest->next;
	while (current)
	{
		current_nb = *(int*)current->content;
		if (ft_abs(current_nb - nb) < ft_abs(*(int*)closest->content - nb))
			closest = current;
		current = current->next;
	}
	return (closest);
}

static size_t	get_top_cost(t_list *current, t_list *stack)
{
	size_t	current_index;
	size_t	stack_size;
	size_t	cost;

	current_index = ft_lstindex(current, stack) + 1;
	stack_size = ft_lstsize(stack);
	if (current_index > stack_size / 2)
		cost = stack_size - current_index;
	else
		cost = current_index;
	// ft_printf("size : %d, index : %d\n", stack_size, current_index);
	return (cost);
}

size_t	get_pb_cost(t_list *current, t_list *a, t_list *b)
{
	t_list	*target;
	size_t	a_cost;
	size_t	b_cost;

	if (ft_lsttoi(current) < ft_lsttoi(stack_min(b)))
		target = (stack_max(b));
	else
		target = (stack_closest(b, ft_lsttoi(current)));
	a_cost = get_top_cost(current, a);
	b_cost = get_top_cost(target, b);
	ft_printf("Current : %d, target : %d, cost : %d + %d = %d\n",ft_lsttoi(current), ft_lsttoi(target), a_cost, b_cost, a_cost + b_cost);
	return (a_cost + b_cost);
}