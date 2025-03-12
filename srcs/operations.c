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

void sa(t_list **a)
{
	swap_top(a);
#ifndef CHECKER
	ft_printf("sa\n");
#endif
}

void sb(t_list **b)
{
	swap_top(b);
#ifndef CHECKER
	ft_printf("sb\n");
#endif
}

void ss(t_list **a, t_list **b)
{
	swap_top(a);
	swap_top(b);
#ifndef CHECKER
	ft_printf("ss\n");
#endif
}

void pa(t_list **a, t_list **b)
{
	push_top(b, a);
#ifndef CHECKER
	ft_printf("pa\n");
#endif
}

void pb(t_list **a, t_list **b)
{
	push_top(a, b);
#ifndef CHECKER
	ft_printf("pb\n");
#endif
}

void ra(t_list **a)
{
	rotate(a);
#ifndef CHECKER
	ft_printf("ra\n");
#endif
}

void rb(t_list **b)
{
	rotate(b);
#ifndef CHECKER
	ft_printf("rb\n");
#endif
}

void rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
#ifndef CHECKER
	ft_printf("rr\n");
#endif
}

void rra(t_list **a)
{
	reverse_rotate(a);
#ifndef CHECKER
	ft_printf("rra\n");
#endif
}

void rrb(t_list **b)
{
	reverse_rotate(b);
#ifndef CHECKER
	ft_printf("rrb\n");
#endif
}

void rrr(t_list **a, t_list **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
#ifndef CHECKER
	ft_printf("rrr\n");
#endif
}
