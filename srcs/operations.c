/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:31:04 by nbellila          #+#    #+#             */
/*   Updated: 2024/06/22 17:26:41 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **a)
{
	swap_top(a);
	ft_printf("sa\n");
}

void	sb(t_list **b)
{
	swap_top(b);
	ft_printf("sb\n");
}

void	ss(t_list **a, t_list **b)
{
	swap_top(a);
	swap_top(b);
	ft_printf("ss\n");
}

void	pa(t_list **a, t_list **b)
{
	push_top(b, a);
	ft_printf("pa\n");
}

void	pb(t_list **a, t_list **b)
{
	push_top(a, b);
	ft_printf("pb\n");
}
