/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:12:29 by nbellila          #+#    #+#             */
/*   Updated: 2024/06/14 18:37:25 by nbellila         ###   ########.fr       */
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
t_list	*stack_closest(t_list *stack, int nb)
{
	t_list	*closest;
	t_list	*current;
	int		current_nb;

	closest = stack;
	current = closest->next;
	while (current)
	{
		current_nb = *(int*)current->content;
		if (ft_abs(current_nb - nb) < ft_abs(*(int*)closest->content - nb))
			closest = current;
		current = current->next;
	}
	return (closest);
}

void	rotate_top(size_t index, t_list **a, t_list **b)
{
	size_t	lstsize;

	lstsize = ft_lstsize(*a);
	// si index dans moitie basse, rotate vers le bas
	if (index < lstsize / 2)
	{
		while (index > 0)
		{
			rra(a, b);
			index--;
		}
		rra(a, b);
	}
	// sinon rotate vers le haut
	else
	{
		while (index + 1 < lstsize)
		{
			ra(a, b);
			index++;
		}
	}
}

void	rotate_bot(size_t index, t_list **a, t_list **b)
{
	size_t	lstsize;

	lstsize = ft_lstsize(*a);
	// si index dans moitie basse, rotate vers le bas
	if (index < lstsize / 2)
	{
		while (index > 0)
		{
			rra(a, b);
			index--;
		}
	}
	// sinon rotate vers le haut
	else
	{
		while (index < lstsize)
		{
			ra(a, b);
			index++;
		}
	}
}

