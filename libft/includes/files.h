/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:31:43 by nbellila          #+#    #+#             */
/*   Updated: 2024/06/21 18:56:16 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
# define FD_MAX 1024

char	*get_next_line(int fd);

int		read_line(t_list **lst, int fd);

char	*lst_to_line(t_list *lst);

int		clean_lst(t_list **lst);

int		ft_lstcontains(t_list *lst, char c);

size_t	ft_lststrlen(t_list *lst);

int		ft_strcontains(char *str, char c);

#endif
