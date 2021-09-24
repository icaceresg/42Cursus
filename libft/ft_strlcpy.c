/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icaceres <icaceres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 09:12:50 by icaceres          #+#    #+#             */
/*   Updated: 2021/09/24 16:59:08 by icaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (src [i] != '\0')
	{
		len++;
		i++;
	}
	i = 0;
	while (dstsize > 1 && i < len)
	{
		dst [i] = src [i];
		dstsize--;
		i++;
	}
	if (dstsize != 0)
		dst [i] = '\0';
	return (len);
}
