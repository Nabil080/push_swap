/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opeartions_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:46:29 by nbellila          #+#    #+#             */
/*   Updated: 2024/06/20 11:55:05 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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