/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icaceres <icaceres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:21:34 by icaceres          #+#    #+#             */
/*   Updated: 2022/02/12 18:32:35 by icaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char const *s2)
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
	free(s1);
	return (ptr);
}

char	*ft_clone(int i, int aux, char *str)
{
	char	*sol;

	sol = malloc ((i + aux + 1) * sizeof(char));
	if (sol == NULL)
		return (NULL);
	sol[i + aux] = '\0';
	aux = -1;
	while (++aux <= i)
		sol[aux] = str[aux];
	return (sol);
}

char	*ft_line(char *str)
{
	int		i;
	int		aux;
	char	*sol;

	i = 0;
	if (str[0] == 0)
		return (NULL);
	aux = 1;
	while (1)
	{
		if (str[i] == '\n' || str[i] == '\0')
		{
			if (str[i] == '\0')
				aux = 0;
			return (ft_clone(i, aux, str));
		}
		i++;
	}
	free(sol);
	return (NULL);
}
