/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icaceres <icaceres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:48:27 by icaceres          #+#    #+#             */
/*   Updated: 2021/10/29 20:30:50 by icaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_hexa_ptr(size_t i, unsigned long long num)
{
	char				*ptr;
	unsigned long long	resto;
	char				*hexa;

	hexa = "0123456789abcdef";
	ptr = malloc (sizeof(char) * (i + 1));
	if (ptr == '\0')
		return (0);
	ptr[i] = '\0';
	i = 0;
	while (num >= 16)
	{
		resto = num % 16;
		ptr[i] = hexa[resto];
		num /= 16;
		i++;
	}
	if (num > 0)
		ptr[i] = hexa [num];
	return (ptr);
}

size_t	ft_how_many(unsigned long long aux)
{
	size_t	i;

	i = 0;
	while (aux >= 16)
	{
		aux /= 16;
		i++;
	}
	i++;
	return (i);
}

size_t	ft_pointer(unsigned long long num)
{
	unsigned long long	aux;
	size_t				i;
	char				*ptr;

	if (num == 0)
	{
		write (1, "0x0", 3);
		return (3);
	}
	ptr = ft_hexa_ptr(ft_how_many(num), num);
	i = ft_strlen(ptr);
	write (1, "0x", 2);
	aux = 2;
	while (i > 0)
	{
		write(1, &ptr[--i], 1);
		aux++;
	}
	free (ptr);
	return ((size_t)aux);
}
