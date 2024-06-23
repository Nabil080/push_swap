/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:31:04 by nbellila          #+#    #+#             */
/*   Updated: 2024/06/22 16:14:14 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **a)
{
	swap_top(a);
}

void	sb(t_list **b)
{
	swap_top(b);
}

void	ss(t_list **a, t_list **b)
{
	swap_top(a);
	swap_top(b);
}

void	pa(t_list **a, t_list **b)
{
	push_top(b, a);
}

void	pb(t_list **a, t_list **b)
{
	push_top(a, b);
}
