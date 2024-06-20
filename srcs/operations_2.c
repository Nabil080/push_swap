/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:32:52 by nbellila          #+#    #+#             */
/*   Updated: 2024/06/20 13:51:16 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **a, t_list **b)
{
	rotate(a);
	ft_printf("Operation done : ra\n");
	show_stacks(a, b);
}

void	rb(t_list **a, t_list **b)
{
	rotate(b);
	ft_printf("Operation done : rb\n");
	show_stacks(a, b);
}

void	rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
	ft_printf("Operation done : rr\n");
	show_stacks(a, b);
}

void	rra(t_list **a, t_list **b)
{
	reverse_rotate(a);
	ft_printf("Operation done : rra\n");
	show_stacks(a, b);
}

void	rrb(t_list **a, t_list **b)
{
	reverse_rotate(b);
	ft_printf("Operation done : rrb\n");
	show_stacks(a, b);
}
