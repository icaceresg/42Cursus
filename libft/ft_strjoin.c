/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icaceres <icaceres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 14:54:33 by icaceres          #+#    #+#             */
/*   Updated: 2021/09/17 15:52:29 by icaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lens1;
	size_t	lens2;
	char	*ptr;
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (s1 == '\0' || s2 == '\0')
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	ptr = (char *) malloc (sizeof(char) * (lens1 + lens2 + 1));
	if (ptr == NULL)
		return (NULL);
	while (lens1-- > 0)
	{
		ptr[i] = s1[i];
		i++;
	}
	while (lens2-- > 0)
		ptr[i++] = s2[k++];
	ptr[i] = '\0';
	return (ptr);
}
