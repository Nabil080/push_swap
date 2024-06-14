/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:19:29 by nbellila          #+#    #+#             */
/*   Updated: 2024/06/14 14:35:09 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTERS_H
# define PRINTERS_H

/*
* va_arg / write
*/
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);

int		ft_putchar_fd(char c, int fd);

int		ft_putstr_fd(const char *s, int fd);

size_t	ft_putendl_fd(const char *s, int fd);

size_t	ft_putnbr_fd(int nbr, int fd);

size_t	ft_putnbr_base(long nbr, const char *base);

size_t	ft_putunsigned_base(unsigned long int nbr, const char *base);

#endif