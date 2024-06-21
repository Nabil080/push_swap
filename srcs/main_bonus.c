/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:22:51 by nbellila          #+#    #+#             */
/*   Updated: 2024/06/21 17:38:52 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	args_check(argc, argv);
	a = parse_as_lst(argc, argv);
	if (!a)
		exit_malloc();
	b = NULL;
}