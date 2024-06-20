/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:15:26 by nbellila          #+#    #+#             */
/*   Updated: 2024/06/20 15:04:15 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	solve_size_3(t_list **a, t_list **b)
{
	int	last;
	int	mid;
	int	first;

	first = *(int*)(*a)->content;
	mid = *(int*)(*a)->next->content;
	last = *(int*)(*a)->next->next->content;

	if (first < mid && mid < last)
		sa(a, b);
	else if (first < mid && mid > last && last < first)
		sa(a, b);
	else if (first > mid && mid < last && last < first)
		sa(a, b);
	else if (first < mid && mid > last && last > first)
		rra(a, b);
	else if (first > mid && mid < last && last > first)
		ra(a, b);
	if (!is_sorted(a, NULL))
		solve_size_3(a, b);
}

static void	find_best_pb(t_list **a, t_list **b)
{
	t_list	*cheapest;

	if (ft_lstsize(*b) < 2)
		return (pb(a, b));
	cheapest = get_cheapest_pb(*a, *b);
	ft_printf("CHEAPEST : %d\n", ft_lsttoi(cheapest));
	do_cheapest_pb(cheapest, a, b);
}

static void find_best_pa(t_list **a, t_list **b)
{
	t_list	*top_b;
	t_list	*closest;
	size_t	closest_index;
	
	top_b = ft_lstlast(*b)->content;
	if (*(int*)top_b > *(int *)stack_max(*a)->content)
		return (pa(a, b));
	closest = stack_closest(*a, *(int*)top_b);
	closest_index = ft_lstindex(closest, *a);
	if (*(int*)closest->content < *(int*)top_b)
		rotate_bot(closest_index, a, b);
	else
		rotate_top(closest_index, a, b);
	return (pa(a ,b));
}

static void	find_next_operation(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) == 2)
		sa(a, b);
	else if (ft_lstsize(*a) == 3)
		solve_size_3(a, b);
	//todo si a > 3, push dans b au bon endroit
	else
		find_best_pb(a, b);
}

void	push_swap_sort(t_list **a, t_list **b)
{
	//todo tant que a n'est pas trie, on cherche la meilleure operation
	while (!is_sorted(a, NULL))
		find_next_operation(a, b);
	while(1);
	while (ft_lstsize(*b) > 0)
		find_best_pa(a, b);
	while (!is_sorted(a, NULL))
	{
		// si le max est plus proche du debut, rra
		if (ft_lstindex(stack_max(*a), *a) < ft_lstsize(*a) / 2)
			rra(a, b);
		// si le min est plus proche du debut, rra
		else
			ra(a, b);
	}
}