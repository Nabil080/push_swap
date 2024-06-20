/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:31:04 by nbellila          #+#    #+#             */
/*   Updated: 2024/06/14 23:50:43 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **a, t_list **b)
{
	swap_top(a);
	ft_printf("Operation done : sa\n");
	show_stacks(a, b);
}

void	sb(t_list **a, t_list **b)
{
	swap_top(b);
	ft_printf("Operation done : sb\n");
	show_stacks(a, b);
}

void	ss(t_list **a, t_list **b)
{
	swap_top(a);
	swap_top(b);
	ft_printf("Operation done : ss\n");
	show_stacks(a, b);
}

void	pa(t_list **a, t_list **b)
{
	push_top(b, a);
	ft_printf("Operation done : pa\n");
	show_stacks(a, b);
}

void	pb(t_list **a, t_list **b)
{
	push_top(a, b);
	ft_printf("Operation done : pb\n");
	show_stacks(a, b);
}
