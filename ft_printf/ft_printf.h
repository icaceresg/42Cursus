/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icaceres <icaceres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 20:22:15 by icaceres          #+#    #+#             */
/*   Updated: 2021/10/29 20:21:52 by icaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

/*
** function list
*/
size_t	ft_strlen(const char *s);
size_t	ft_putchar_fd(char c, int fd);
size_t	ft_putstr_fd(char *s, int fd, int malloc);
char	*ft_itoa(long n);
size_t	ft_pointer(unsigned long long num);
size_t	ft_hexa(long num, int up);
int		ft_printf(const char	*c, ...);

#endif