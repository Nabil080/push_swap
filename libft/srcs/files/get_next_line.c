/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:07:00 by nbellila          #+#    #+#             */
/*   Updated: 2024/06/21 18:56:14 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static t_list	*lst = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, &line, 0) < 0)
		return (ft_lstclear(&lst, free));
	if (!read_line(&lst, fd))
		return (ft_lstclear(&lst, free));
	line = lst_to_line(lst);
	if (!line)
		return (ft_lstclear(&lst, free));
	if (!clean_lst(&lst))
		return (ft_lstclear(&lst, free));
	if (!*line)
	{
		free(line);
		return (ft_lstclear(&lst, free));
	}
	return (line);
}

int	read_line(t_list **lst, int fd)
{
	t_list	*new;
	int		read_count;

	read_count = 1;
	while (read_count && !ft_lstcontains(*lst, '\n'))
	{
		new = malloc(sizeof(t_list));
		if (!new)
			return (0);
		new->content = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!ft_lsttos(new))
		{
			free(new);
			return (0);
		}
		read_count = read(fd, ft_lsttos(new), BUFFER_SIZE);
		ft_lsttos(new)[read_count] = 0;
		new->next = NULL;
		ft_lstadd_back(lst, new);
	}
	return (1);
}

char	*lst_to_line(t_list *lst)
{
	char	*line;
	size_t	i;
	size_t	total_len;

	line = malloc((ft_lststrlen(lst) + 1) * sizeof(char));
	if (!line)
		return (NULL);
	total_len = 0;
	while (lst)
	{
		i = 0;
		while (ft_lsttos(lst)[i] && ft_lsttos(lst)[i] != '\n')
		{
			line[total_len] = ft_lsttos(lst)[i];
			total_len++;
			i++;
		}
		if (ft_lsttos(lst)[i] == '\n')
			line[total_len++] = '\n';
		lst = lst->next;
	}
	line[total_len] = 0;
	return (line);
}

int	clean_lst(t_list **lst)
{
	char	*clean;
	t_list	*last;

	last = ft_lstlast(*lst);
	ft_lstlast_offset(*lst, 1)->next = NULL;
	ft_lstclear(lst, free);
	clean = ft_strdup(&ft_lsttos(last)[ft_strcontains(ft_lsttos(last), '\n') + 1]);
	if (!clean)
		return (0);
	free(last->content);
	last->content = clean;
	*lst = last;
	return (1);
}