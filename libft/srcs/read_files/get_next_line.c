/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:07:00 by nbellila          #+#    #+#             */
/*   Updated: 2024/06/22 15:30:39 by nbellila         ###   ########.fr       */
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
		if (!new->content)
		{
			free(new);
			return (0);
		}
		read_count = read(fd, new->content, BUFFER_SIZE);
		*((char *)new->content + read_count) = 0;
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
		while (*(char *)lst->content + i && *((char *)(lst->content + i)) != '\n')
		{
			line[total_len] = *((char *)lst->content + i );
			total_len++;
			i++;
		}
		if (*((char *)(lst->content + i )) == '\n')
			line[total_len++] = '\n';
		lst = lst->next;
	}
	line[total_len] = 0;
	return (line);
}

int	clean_lst(t_list **lst)
{
	char	*clean;
	t_list	*current;
	t_list	*next;

	current = *lst;
	while (current->next)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
	clean = ft_strdup(&current->content[ft_strcontains(current->content, '\n') + 1]);
	if (!clean)
		return (0);
	free(current->content);
	current->content = clean;
	*lst = current;
	return (1);
}
/*
int	main(int argc, char **argv)
{
	char	*line;
	size_t	i;
	size_t	count;
	int empty;
	int	fd;
	int	fd2;

	if (argc < 2)
		count = 5;
	else
		count = atoi(argv[1]);
	empty = open("empty", O_RDONLY);
	fd = open("fd1", O_RDONLY);
	fd2 = open("fd2", O_RDONLY);
	printf("Buffer size : %d\n", BUFFER_SIZE);
	i = 0;
	while (i < count)
	{
		if (argc > 2 && i % 2)
			line = get_next_line(fd2);
		else
			line = get_next_line(empty);
		printf("---Line %zu---\n", i + 1);
		printf("%s", line);
		free(line);
		i++;
	}
	close(empty);
	close(fd);
	close(fd2);
	return (0);
}
*/
/*
int main(void)
{
	int fd = open("slt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
}
*/