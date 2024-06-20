/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outputs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:49:51 by nbellila          #+#    #+#             */
/*   Updated: 2024/06/20 19:16:32 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	recursive_show_stacks(t_list *a, t_list *b)
{
	if ((a && a->next) && (b && b->next))
		recursive_show_stacks(a->next, b->next);
	else if (a && a->next)
		recursive_show_stacks(a->next, NULL);
	else if (b && b->next)
		recursive_show_stacks(NULL, b->next);
	if (a && b)
		ft_printf("\t%d\t %d\n", ft_lsttoi(a), ft_lsttoi(b));
	else if (a)
		ft_printf("\t%d\t x\n", ft_lsttoi(a));
	else if (b)
		ft_printf("\tx\t %d\n", ft_lsttoi(b));
}

void	show_stacks(t_list **a, t_list **b)
{
	ft_printf("\t\n");
	recursive_show_stacks(*a, *b);
	ft_printf("\t_\t _\n");
	ft_printf("\ta\t b\n\n");
}

void	exit_error(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

void	exit_malloc(void)
{
	ft_printf("A malloc failed\n");
	exit(EXIT_FAILURE);
}

void	exit_success(t_list	*a, t_list	*b)
{
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	// ft_printf("Program successfully closed, everything freed\n");
	exit(EXIT_SUCCESS);
}
