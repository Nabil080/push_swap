/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:31:04 by nbellila          #+#    #+#             */
/*   Updated: 2024/06/20 18:27:57 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **a, t_list **b)
{
	swap_top(a);
	show_stacks(a, b);
	ft_printf("sa\n");
}

void	sb(t_list **a, t_list **b)
{
	swap_top(b);
	ft_printf("sb\n");
	show_stacks(a,b);
}

void	ss(t_list **a, t_list **b)
{
	swap_top(a);
	swap_top(b);
	ft_printf("ss\n");
	show_stacks(a,b);
}

void	pa(t_list **a, t_list **b)
{
	push_top(b, a);
	ft_printf("pa\n");
	show_stacks(a,b);
}

void	pb(t_list **a, t_list **b)
{
	push_top(a, b);
	ft_printf("pb\n");
	show_stacks(a,b);
}
