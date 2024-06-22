/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:22:51 by nbellila          #+#    #+#             */
/*   Updated: 2024/06/22 16:08:58 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	check_operation(char *operation, t_list **a, t_list **b)
{
	if (!ft_strcmp(operation, "sa\n"))
		sa(a);
	else if (!ft_strcmp(operation, "sb\n"))
		sb(b);
	else if (!ft_strcmp(operation, "ss\n"))
		ss(a, b);
	else if (!ft_strcmp(operation, "pa\n"))
		pa(a, b);
	else if (!ft_strcmp(operation, "pb\n"))
		pb(a, b);
	else if (!ft_strcmp(operation, "ra\n"))
		ra(a);
	else if (!ft_strcmp(operation, "rb\n"))
		rb(b);
	else if (!ft_strcmp(operation, "rr\n"))
		rr(a, b);
	else if (!ft_strcmp(operation, "rra\n"))
		rra(a);
	else if (!ft_strcmp(operation, "rrb\n"))
		rrb(b);
	else if (!ft_strcmp(operation, "rrr\n"))
		rrr(a, b);
	else
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	*operation;

	args_check(argc, argv);
	a = parse_as_lst(argc, argv);
	if (!a)
		exit_malloc();
	b = NULL;
	operation = get_next_line(0);
	while (operation)
	{
		if (!check_operation(operation, &a, &b))
		{
			free(operation);
			exit_error();
		}
		free(operation);
		operation = get_next_line(1);
	}
	if (is_stack_sorted(a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	exit_success(a, b);
}