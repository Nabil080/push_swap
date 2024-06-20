/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:49:26 by nbellila          #+#    #+#             */
/*   Updated: 2024/06/20 15:10:36 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*stack_max(t_list *stack)
{
	t_list	*max;
	t_list	*current;

	max = stack;
	current = stack->next;
	while (current)
	{
		if (*(int*)max->content < *(int*)current->content)
			max = current;
		current = current->next;
	}
	return (max);
}

t_list	*stack_min(t_list *stack)
{
	t_list	*min;
	t_list	*current;

	min = stack;
	current = stack->next;
	while (current)
	{
		if (*(int*)min->content > *(int*)current->content)
			min = current;
		current = current->next;
	}
	return (min);
}

t_list	*stack_closest(t_list *stack, int nb)
{
	t_list	*closest;
	t_list	*current;
	int		current_nb;

	closest = stack_max(stack);
	current = stack;
	while (current)
	{
		current_nb = *(int*)current->content;
		// if (ft_abs(current_nb - nb) < ft_abs(*(int*)closest->content - nb))
		if (nb > ft_lsttoi(current) && nb - ft_lsttoi(current) < ft_lsttoi(closest))
			closest = current;
		current = current->next;
	}
	return (closest);
}