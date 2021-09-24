/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icaceres <icaceres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 14:15:12 by icaceres          #+#    #+#             */
/*   Updated: 2021/09/24 16:57:05 by icaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*a;
	size_t					i;
	unsigned char			pol;

	a = s;
	i = 0;
	pol = (unsigned char) c;
	if (pol == 0 && n == 0)
		return (NULL);
	while (n > 0)
	{
		if (a[i] == pol)
			return ((void *) &a[i]);
		i++;
		n--;
	}
	if (pol == '\0')
		return ((void *) &a[i]);
	return (NULL);
}
