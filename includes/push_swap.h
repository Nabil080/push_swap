/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:17:03 by nbellila          #+#    #+#             */
/*   Updated: 2024/06/20 19:33:58 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

/*
* parsing	
*/
void	args_check(size_t argc, char **argv);

t_list	*parse_as_lst(size_t argc, char **argv);

int		ft_min(int a, int b);
/*
* outputs
*/
int		is_stack_sorted	(t_list *stack);

void	exit_error(void);

void	exit_malloc(void);

void	exit_success(t_list	*a, t_list	*b);
/*
* solver
*/
void	push_swap_sort(t_list **a, t_list **b);
/*
* stack
*/
t_list	*stack_max(t_list *stack);

t_list	*stack_min(t_list *stack);

t_list	*stack_closest_inferior(t_list *stack, int nb);

t_list	*stack_closest_superior(t_list *stack, int nb);
/*
* solver_utils
*/
t_list	*get_cheapest_pb(t_list *a, t_list *b);

void	do_cheapest_pb(t_list *cheapest, t_list **a, t_list **b);
/*
* operations
*/
typedef void	(*t_operations)(t_list **, t_list **);

void	swap_top(t_list **stack);

void	sa(t_list **a);

void	sb(t_list **b);

void	ss(t_list **a, t_list **b);

void	push_top(t_list **src, t_list **dst);

void	pa(t_list **a, t_list **b);

void	pb(t_list **a, t_list **b);

void	rotate(t_list **stack);

void	ra(t_list **a);

void	rb(t_list **b);

void	rr(t_list **a, t_list **b);

void	reverse_rotate(t_list **stack);

void	rra(t_list **a);

void	rrb(t_list **b);

void	rrr(t_list **a, t_list **b);

void	rotate_top(size_t index, t_list **a, t_list **b);

void	rotate_bot(size_t index, t_list **a, t_list **b);

#endif