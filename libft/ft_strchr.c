/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icaceres <icaceres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 12:32:00 by icaceres          #+#    #+#             */
/*   Updated: 2021/09/16 20:58:56 by icaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	pol;

	i = 0;
	pol = c;
	while (s[i] != '\0')
	{
		if (s[i] == pol)
			return ((char *)&s[i]);
		i++;
	}
	if (pol == '\0' && s[i] == pol)
		return ((char *)&s[i]);
	return (NULL);
}
