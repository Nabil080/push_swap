/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:12:29 by nbellila          #+#    #+#             */
/*   Updated: 2024/06/20 19:14:47 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	return (cost);
}

static t_list	*get_target(t_list *current, t_list *stack)
{
	if (ft_lsttoi(current) > ft_lsttoi(stack_max(stack)))
		return (stack_max(stack));
	return (stack_closest_inferior(stack, ft_lsttoi(current)));
}

static size_t	get_pb_cost(t_list *current, t_list *a, t_list *b)
{
	t_list	*target;
	size_t	a_cost;
	size_t	b_cost;
	size_t	cost;

	target = get_target(current, b);
	a_cost = get_top_cost(current, a);
	b_cost = get_top_cost(target, b);
	cost = a_cost + b_cost;
	if (ft_lstindex(current, a) + 1 > ft_lstsize(a) / 2)
		if (ft_lstindex(target, b) + 1 > ft_lstsize(b) / 2)
			cost -= ft_min(a_cost, b_cost);
	if (ft_lstindex(current, a) + 1 <= ft_lstsize(a) / 2)
		if (ft_lstindex(target, b) + 1 <= ft_lstsize(b) / 2)
			cost -= ft_min(a_cost, b_cost);
	return (cost);
}

t_list	*get_cheapest_pb(t_list *a, t_list *b)
{
	t_list	*current;
	t_list	*cheapest;

	current = a;
	cheapest = current;
	while (current)
	{
		if (get_pb_cost(current, a, b) < get_pb_cost(cheapest, a, b))
			cheapest = current;
		current = current->next;
	}
	return (cheapest);
}

void	do_cheapest_pb(t_list *cheapest, t_list **a, t_list **b)
{
	t_list	*target;

	target = get_target(cheapest, *b);
	while (cheapest->next || target->next)
	{
		if (cheapest->next && isabovemid(cheapest, *a))
		{
			if (target->next && isabovemid(target, *b))
				rr(a, b);
			else
				ra(a, b);
		}
		else if (cheapest->next)
		{
			if (target->next && !isabovemid(target, *b))
				rrr(a, b);
			else
				rra(a, b);
		}
		else if (target->next && isabovemid(target, *b))
			rb(a, b);
		else if (target->next && !isabovemid(target, *b))
			rrb(a, b);
	}
	pb(a, b);
}
