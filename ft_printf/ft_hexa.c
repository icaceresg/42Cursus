/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icaceres <icaceres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:24:26 by icaceres          #+#    #+#             */
/*   Updated: 2021/10/29 20:30:37 by icaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ptr_hexa(long num, size_t i, char *hexa)
{
	char			*ptr;
	unsigned long	resto;

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

static size_t	ft_how_many(unsigned long aux)
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

size_t	ft_hexa(long num, int up)
{
	char			*hexa;
	unsigned long	aux;
	size_t			i;
	char			*ptr;

	if (!up)
		hexa = "0123456789abcdef";
	else
		hexa = "0123456789ABCDEF";
	if (num == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	else if (num < 0)
		num = 4294967296 + num;
	ptr = ptr_hexa(num, ft_how_many(num), hexa);
	i = ft_strlen(ptr);
	aux = i;
	while (i > 0)
		write(1, &ptr[--i], 1);
	free(ptr);
	return ((size_t)aux);
}
