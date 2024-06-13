/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:15:26 by nbellila          #+#    #+#             */
/*   Updated: 2024/06/13 21:31:39 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//1-2-3 -> (sa)1-3-2 -> (rra)3-2-1 -> sorted
//2-3-1 -> (sa)2-1-3 -> (rra)3-2-1 -> sorted
//3-1-2 -> (sa)3-2-1 -> sorted
//1-3-2 -> (rra)3-2-1 -> sorted
//2-1-3 -> (ra)3-2-1 -> sorted
//3-2-1 -> sorted

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
	if (first < mid && mid > last && last < first)
		sa(a, b);
	if (first > mid && mid < last && last < first)
		sa(a, b);
	if (first < mid && mid > last && last > first)
		rra(a, b);
	if (first > mid && mid < last && last > first)
		ra(a, b);
	if (!is_sorted(a, NULL))
		solve_size_3(a, b);
}

static void	find_next_operation(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) == 2)
		sa(a, b);
	if (ft_lstsize(*a) == 3)
		solve_size_3(a, b);
	if (ft_lstsize(*a) > 3 && ft_lstsize(*b) < 2)
		pb(a, b);
	//TODO : trouver quel noeud de a push dans b
	// * -> b est trie jusqu'a ce que a tombe a 3elements et se trie
	// if (ft_lstsize(*b) > 2)
	// 	find_best_pb(a, b);
	//TODO : si a est sort (3elem) on push de b dans a au bon endroit
	// * -> a est trie, done gg wp ez

}

void	push_swap_sort(t_list **a, t_list **b)
{
	show_stacks(a, b);
	while (!is_sorted(a, b))
		find_next_operation(a, b);
	return ;
}