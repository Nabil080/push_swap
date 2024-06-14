/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:15:26 by nbellila          #+#    #+#             */
/*   Updated: 2024/06/14 16:20:37 by nbellila         ###   ########.fr       */
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

static void	find_best_pb(t_list **a, t_list ** b)
{
	if (ft_lstsize(*b) < 2)
		return (pb(a, b));
}

//7-6-0-null | 2-9-null
//7-6-0-9-null | 2-null
//6-0-9-7-null | 2-null
//0-9-7-6-null | 2-null
//0-9-7-6-2-null | null
//9-7-6-2-0-null | null
static void find_best_pa(t_list **a, t_list **b)
{
	int	top_a;
	int	top_b;
	
	top_a = *(int *)ft_lstlast(*a)->content;
	top_b = *(int *)ft_lstlast(*b)->content;
	//todo si top_b > max de a, on peut push direct
	//todo trouver le nbr de a avec la plus petite difference de top_b
	//todo rotate pour que ce nbr soit en haut 
	ft_printf("\n--------------------DEBUG--------------------\n\n");
	ft_printf("TOP A : %d, TOP B : %d\n", top_a, top_b);
	ft_printf("\n--------------------DEBUG--------------------\n\n");
}

static void	find_next_operation(t_list **a, t_list **b)
{
	//? si a = 2, trie done
	if (ft_lstsize(*a) == 2)
		sa(a, b);
	//? si a = 3, trie done
	else if (ft_lstsize(*a) == 3)
		solve_size_3(a, b);
	//todo si a > 3, push dans b au bon endroit
	else
		find_best_pb(a, b);
}

void	push_swap_sort(t_list **a, t_list **b)
{
	show_stacks(a, b);
	//todo tant que a n'est pas trie, on cherche la meilleure operation
	while (!is_sorted(a, NULL))
		find_next_operation(a, b);
	//? trouve le premier push dans a
	find_best_pa(a, b);
	//? tant que b n'est pas vide, on push dans a
	while (ft_lstsize(*b) > 0)
		pa(a, b);
	//todo une fois que tout est au bon endroit dans a, on termine le tri (ra/rra)
	// while (!is_sorted(a, NULL))
	// {
	// 	// si le min est plus proche de la fin, ra
	// 	if (ft_lstindex(stack_min(a)) > ft_lstsize(*a) / 2)
	// 		ra(a, b);
	// 	// si le min est plus proche du debut, rra
	// 	else
	// 		rra(a, b);
	// }
}