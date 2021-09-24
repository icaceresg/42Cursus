/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icaceres <icaceres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 12:53:13 by icaceres          #+#    #+#             */
/*   Updated: 2021/09/24 16:59:38 by icaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*a;
	size_t			i;
	int				encuentra;
	unsigned char	pol;

	encuentra = 0;
	i = 0;
	pol = c;
	while (s[i] != '\0')
	{
		if (s[i] == pol)
		{
			a = ((char *)&s[i]);
			encuentra = 1;
		}
		i++;
	}
	if (pol == '\0' && s[i] == pol)
		return ((char *)&s[i]);
	if (encuentra)
		return (a);
	return (NULL);
}
