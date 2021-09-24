/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icaceres <icaceres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 19:49:15 by icaceres          #+#    #+#             */
/*   Updated: 2021/09/24 16:58:45 by icaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*ptr;

	len = ft_strlen(s1);
	ptr = (char *) malloc (sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	ptr = ft_memcpy(ptr, s1, len);
	ptr[len] = '\0';
	return (ptr);
}
