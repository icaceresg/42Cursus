/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icaceres <icaceres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:31:50 by icaceres          #+#    #+#             */
/*   Updated: 2021/10/29 21:25:16 by icaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"
//#include "./libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s [len] != '\0')
		len++;
	return (len);
}

static int	ft_strrchr(const char *s, char c)
{
	size_t			i;
	int				encuentra;

	encuentra = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			encuentra = 1;
		}
		i++;
	}
	if (encuentra)
		return (1);
	return (0);
}

static size_t	ft_flags(char c, va_list param)
{
	size_t	cont;

	cont = 0;
	if (c == 'c')
		cont = ft_putchar_fd(va_arg(param, int), 1);
	else if (c == 's')
		cont = ft_putstr_fd (va_arg(param, char *), 1, 0);
	else if (c == 'p')
		cont = ft_pointer(va_arg(param, long long));
	else if (c == 'd' || c == 'i')
		cont = ft_putstr_fd(ft_itoa(va_arg(param, int)), 1, 1);
	else if (c == 'u')
		cont = ft_putstr_fd(ft_itoa((unsigned int)va_arg(param, int)), 1, 1);
	else if (c == 'X' || c == 'x')
		cont = ft_hexa(va_arg(param, int), c != 'x');
	else if (c == '%')
		cont = ft_putchar_fd('%', 1);
	return (cont);
}

static size_t	ft_checker(const char*c, va_list param)
{
	size_t	cont;
	size_t	i;
	char	*alphabet;

	alphabet = "cspdiuxX%%";
	cont = 0;
	i = 0;
	while (c[i] != '\0')
	{
		if (c[i] == 37 && ft_strrchr(alphabet, c[i + 1]))
		{
			cont = cont + ft_flags(c[i + 1], param);
			i += 2;
		}
		else
		{
			ft_putchar_fd(c[i], 1);
			i++;
			cont++;
		}
	}
	if (cont)
		return (cont);
	return (cont);
}

int	ft_printf(const char	*c, ...)
{
	int		i;
	int		cont;
	va_list	parametros;

	i = 0;
	va_start (parametros, c);
	cont = ft_checker(c, parametros);
	va_end(parametros);
	return (cont);
}
