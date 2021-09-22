/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icaceres <icaceres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:24:30 by icaceres          #+#    #+#             */
/*   Updated: 2021/09/15 17:15:47 by icaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	const unsigned char	*b;
	unsigned char		*a;

	a = dst;
	b = src;
	if (dst == '\0' && src == '\0')
		return (NULL);
	if (a > b && (b + n > a))
	{
		a = a + n - 1;
		b = b + n - 1;
		while (n-- > 0)
		{
			*a-- = *b--;
		}
	}
	else
	{
		while (n > 0)
		{
			*a++ = *b++;
			n--;
		}
	}
	return (dst);
}
