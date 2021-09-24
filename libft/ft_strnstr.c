/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icaceres <icaceres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:41:44 by icaceres          #+#    #+#             */
/*   Updated: 2021/09/24 16:59:31 by icaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	check;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && len > 0)
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			k = i;
			check = len;
			while (needle[j++] == haystack[k++] && check-- > 0)
			{
				if (needle[j] == '\0')
					return ((char *)&haystack[i]);
			}
		}
		i++;
		len--;
	}
	return (NULL);
}
