/* ************************************************************************** */
/*	                                                                          */
/*                                                        :::      ::::::::   */
/*   libft.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:58:27 by nbellila          #+#    #+#             */
/*   Updated: 2024/05/18 14:35:07 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
*	BASES
*/
# define DECIMAL "0123456789"
# define HEXA "0123456789abcdef"
# define HEXA_UP "0123456789ABCDEF"

/*
*	INT_MAX / SIZE_MAX
*/
# include <limits.h>
# include <stdint.h>
/*
*	write / malloc
*/
# include <unistd.h>
# include <stdlib.h>
/*
* va_arg
*/
# include <stdarg.h>
/*
*	is_check
*/
int		ft_isalpha(int c);

int		ft_isspace(int c);

int		ft_isdigit(int c);

int		ft_isalnum(int c);	

int		ft_isascii(int c);

int		ft_isprint(int c);
/*
*	strs
*/
size_t	ft_strlen(const char *s);

size_t	ft_strlcpy(char *dst, const char *src, size_t siz);

size_t	ft_strlcat(char *dst, const char *src, size_t siz);

size_t	ft_strlcpy(char *dst, const char *src, size_t size);

size_t	ft_strlcat(char *dst, const char *src, size_t siz);

size_t	ft_countchar(char const *s, char const c);

size_t	ft_skipchar(char const *s, char c);

size_t	ft_reachchar(char const *s, char c);

char	*ft_strchr(const char *s, int c);

char	*ft_strrchr(const char *s, int c);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	*ft_strnstr(const char *big, const char *little, size_t len);

int		ft_atoi(const char *nptr);

char	*ft_strdup(const char *s);

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strtrim(char const *s1, char const *set);

char	**ft_split(char const *s, char c);

char	*ft_itoa(int n);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void	ft_striteri(char *s, void (*f)(unsigned int, char *));
/*
*	chars
*/
int		ft_toupper(int c);

int		ft_tolower(int c);
/*
*	memory
*/
void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t nmemb, size_t size);

void	*ft_memset(void *s, int c, size_t n);

void	*ft_memcpy(void *dest, const void *src, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n);

void	*ft_memchr(const void *s, int c, size_t n);

int		ft_memcmp(const void *s1, const void *s2, size_t n);
/*
*	printers / putters
*/
int		ft_printf(const char *str, ...);

int		ft_putchar_fd(char c, int fd);

int		ft_putstr_fd(const char *s, int fd);

size_t	ft_putendl_fd(const char *s, int fd);

size_t	ft_putnbr_fd(int nbr, int fd);

size_t	ft_putnbr_base(long nbr, const char *base);

size_t	ft_putunsigned_base(unsigned long int nbr, const char *base);
/*
*	linked list
*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(void *content);

void	ft_lstadd_front(t_list **lst, t_list *new);

int		ft_lstsize(t_list *lst);

t_list	*ft_lstlast(t_list *lst);

t_list	*ft_lstlast_offset(t_list *lst, size_t offset);

void	ft_lstadd_back(t_list **lst, t_list *new);

void	ft_lstdelone(t_list *lst, void (*del)(void *));

void	*ft_lstclear(t_list **lst, void (*del)(void *));

void	ft_lstiter(t_list *lst, void (*f)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif