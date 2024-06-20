/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:32:52 by nbellila          #+#    #+#             */
/*   Updated: 2024/06/20 18:27:33 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **a, t_list **b)
{
	rotate(a);
	ft_printf("ra\n");
	show_stacks(a,b);
}

void	rb(t_list **a, t_list **b)
{
	rotate(b);
	ft_printf("rb\n");
	show_stacks(a,b);
}

void	rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
	show_stacks(a,b);
}

void	rra(t_list **a, t_list **b)
{
	reverse_rotate(a);
	ft_printf("rra\n");
	show_stacks(a, b);
}

void	rrb(t_list **a, t_list **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
	show_stacks(a,b);
}
