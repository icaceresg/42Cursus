/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icaceres <icaceres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:11:49 by icaceres          #+#    #+#             */
/*   Updated: 2021/09/15 17:09:00 by icaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*a;
	const unsigned char	*b;
	size_t				i;

	i = 0;
	a = dst;
	b = src;
	if (dst == '\0' && src == '\0')
		return (NULL);
	while (n > 0)
	{
		a [i] = b [i];
		i++;
		n--;
	}
	return (a);
}
