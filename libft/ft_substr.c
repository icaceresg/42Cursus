/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icaceres <icaceres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 13:28:13 by icaceres          #+#    #+#             */
/*   Updated: 2021/09/17 14:52:48 by icaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	lon;

	i = 0;
	if (s == NULL)
		return (NULL);
	lon = ft_strlen(s) - start;
	if (lon < len)
		len = lon;
	if (start > ft_strlen(s))
		len = ft_strlen(s);
	ptr = (char *) malloc (sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	if (ft_strlen(s) <= start)
	{
		ptr[i] = '\0';
		return (ptr);
	}
	while (len-- > 0)
		ptr[i++] = s[start++];
	ptr[i] = '\0';
	return (ptr);
}
