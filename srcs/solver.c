/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:15:26 by nbellila          #+#    #+#             */
/*   Updated: 2024/06/22 16:13:19 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	solve_size_3(t_list **stack)
{
	t_list	*max;

	max = stack_max(*stack);
	if (ft_lstlast(*stack) == max)
		ra(stack);
	else if (ft_lsttoi((*stack)->next) == ft_lsttoi(max))
		rra(stack);
	if (ft_lsttoi(*stack) > ft_lsttoi((*stack)->next))
		sa(stack);
}

static void	find_best_pb(t_list **a, t_list **b)
{
	t_list	*cheapest;

	if (ft_lstsize(*b) < 2)
		return (pb(a, b));
	cheapest = get_cheapest_pb(*a, *b);
	do_cheapest_pb(cheapest, a, b);
}

static void	find_best_pa(t_list **a, t_list **b)
{
	t_list	*top_b;
	t_list	*target;

	top_b = ft_lstlast(*b);
	if (ft_lsttoi(top_b) > ft_lsttoi(stack_max(*a)))
		return (pa(a, b));
	target = stack_closest_superior(*a, ft_lsttoi(top_b));
	while (target->next)
	{
		if (isabovemid(target, *a))
			ra(a);
		else
			rra(a);
	}
	pa(a, b);
}

static void	find_next_operation(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) == 2)
		sa(a);
	else if (ft_lstsize(*a) == 3)
		solve_size_3(a);
	else
		find_best_pb(a, b);
}

void	push_swap_sort(t_list **a, t_list **b)
{
	while (!is_stack_sorted(*a))
		find_next_operation(a, b);
	while (ft_lstsize(*b) > 0)
		find_best_pa(a, b);
	while (!is_stack_sorted(*a))
	{
		if (ft_lstindex(stack_max(*a), *a) < ft_lstsize(*a) / 2)
			rra(a);
		else
			ra(a);
	}
}
