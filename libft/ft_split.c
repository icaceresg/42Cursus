/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icaceres <icaceres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 20:18:38 by icaceres          #+#    #+#             */
/*   Updated: 2021/09/26 17:26:45 by icaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len_string(size_t i, char const *s, char c)
{
	size_t	count;

	count = i;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i - count + 2);
}

static char	**total_string(char const *s)
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

static size_t	counter(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	if (s[0] != c)
		count++;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			while (s[i + 1] == c)
				i++;
			count++;
		}
		i++;
	}
	if (s[i - 1] != c)
		count++;
	return (count);
}

static void	field(char **ptr, char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (s[i] != c)
	{
		ptr[count] = malloc (len_string(i, s, c) * sizeof(char));
		ft_strlcpy(ptr[count++], &s[i], len_string(i, s, c) - 1);
	}
	while (s[++i] != '\0')
	{
		if (s[i - 1] == c && s[i] != c)
		{
			ptr[count] = malloc((len_string(i, s, c)) * sizeof(char));
			ft_strlcpy(ptr[count++], &s[i], len_string(i, s, c) - 1);
		}
	}
	ptr[count] = NULL;
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	size_t	i;
	char	**ptr;

	i = 0;
	count = 0;
	if (s == NULL || *s == '\0')
	{
		ptr = malloc (sizeof(char *) * 1);
		if (ptr == NULL)
			return (NULL);
		ptr[0] = NULL;
		return (ptr);
	}
	if (c == '\0')
		return (total_string(s));
	ptr = malloc (sizeof (char *) * (counter(s, c)));
	if (ptr == NULL)
		return (NULL);
	field(ptr, s, c);
	return (ptr);
}
