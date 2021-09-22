/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icaceres <icaceres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 15:55:59 by icaceres          #+#    #+#             */
/*   Updated: 2021/09/21 20:05:22 by icaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	search(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set [i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	search_init_last(size_t *init,
	size_t *last, char const *s1, char const *set)
{
	*init = 0;
	*last = ft_strlen(s1) - 1;
	while (s1[*init] != '\0')
	{
		if (search(s1[*init], set) != 1)
			break ;
		(*init)++;
	}
	while ((*last) > 0)
	{
		if (search(s1[*last], set) != 1)
			break ;
		(*last)--;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	init;
	size_t	last;
	char	*ptr;
	size_t	i;

	if (s1 == '\0')
		return (NULL);
	i = 0;
	search_init_last(&init, &last, s1, set);
	if ((last) == 0)
	{
		ptr = (char *) malloc (sizeof(char) * 1);
		ptr[0] = '\0';
		return (ptr);
	}
	ptr = (char *) malloc (sizeof(char) * (last - init + 2));
	if (ptr == NULL)
		return (NULL);
	while ((last - init + 1) > 0)
	{
		ptr[i] = s1[init++];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
