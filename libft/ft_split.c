/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icaceres <icaceres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 20:18:38 by icaceres          #+#    #+#             */
/*   Updated: 2021/09/21 21:00:29 by icaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static size_t	len_string(size_t i, char const *s, char c)
{
	size_t	count;

	count = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		count++;
		i++;
	}
	return (count);
}

static void	divide(char const *s, char c, char **ptr)
{
	size_t	count;
	size_t	i;
	size_t	k;
	size_t	j;

	i = 0;
	k = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c && s[i - 1] == c) || (i == 0 && s[i] != c))
		{
			count = len_string (i, s, c);
			ptr[j] = (char *) malloc (sizeof(char) * (count + 1));
			if (ptr[j] == NULL)
				ptr[j] = NULL;
			ptr[j][count] = '\0';
			while (count-- > 0)
				ptr[j][k++] = s[i++];
			k = 0;
			j++;
		}
		if (s[i] != '\0')
			i++;
	}
}

char	**total_string(char const *s)
{
	char	**ptr;

	ptr = (char **) malloc (sizeof(char *) * 2);
	if (ptr == NULL)
		return (NULL);
	ptr[0] = (char *) malloc(ft_strlen(s) * sizeof(char));
	ft_strlcpy(ptr[0], s, ft_strlen(s) + 1);
	ptr[1] = NULL;
	return (ptr);
}

size_t	counter(char const *s, char c, size_t *i)
{
	size_t	count;

	count = 0;
	if (s[0] != c)
		count++;
	while (s[*i] != '\0')
	{
		if (s[*i] == c && s[(*i) + 1] != c && s[(*i) + 1] != '\0')
			count++;
		(*i)++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	size_t	i;
	char	**ptr;

	i = 0;
	if (s == NULL || *s == '\0')
	{
		ptr = (char **) malloc (sizeof(char *) * 1);
		if (ptr == NULL)
			return (NULL);
		ptr[0] = NULL;
		return (ptr);
	}
	if (c == '\0')
		return (total_string(s));
	count = counter(s, c, &i);
	if (count == 0 && s[i - 1] != c)
		return (total_string(s));
	ptr = (char **) malloc (sizeof (char *) * (count + 1));
	if (ptr == NULL)
		return (NULL);
	divide(s, c, ptr);
	ptr[count] = NULL;
	return (ptr);
}
