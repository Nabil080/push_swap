/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 18:12:14 by nbellila          #+#    #+#             */
/*   Updated: 2024/06/13 17:47:26 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_countwords(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static void	*free_tab(char **tab, size_t col)
{
	while (col--)
		free(tab[col]);
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	col;
	size_t	start;
	size_t	i;

	tab = malloc((ft_countwords(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	col = 0;
	i = 0;
	while (s[i])
	{
		i += ft_skipchar(&s[i], c);
		start = i;
		i += ft_reachchar(&s[i], c);
		if (start == i)
			break ;
		tab[col] = ft_substr(s, start, i - start);
		if (!tab[col])
			return (free_tab(tab, col));
		col++;
	}
	tab[col] = 0;
	return (tab);
}
/*
int	main(int argc, char const *argv[])
{
	char	**split;
	size_t	i;

	if (argc != 3)
		return (1);
	split = ft_split(argv[1], *argv[2]);
	if (!split)
		return (1);
	i = 0;
	while (split[i])
	{
		printf("%s\n", split[i]);
		free(split[i]);
		i++;
	}
	free(split);
	return (0);
}
*/