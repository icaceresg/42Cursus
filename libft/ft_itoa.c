/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icaceres <icaceres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 17:46:03 by icaceres          #+#    #+#             */
/*   Updated: 2021/09/24 16:55:52 by icaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(int *flag, long num, int i)
{
	if (num < 0)
	{
		*flag = 1;
		num *= -1;
		i++;
	}
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

static char	*complete(char *ptr, int flag, long num, int i)
{
	int	rest;

	rest = 0;
	if (flag)
	{
		ptr[0] = '-';
		num *= -1;
	}
	while (num > 0)
	{
		rest = num % 10;
		num /= 10;
		ptr[i--] = rest + 48;
	}
	return (ptr);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*ptr;
	int		flag;

	i = 0;
	flag = 0;
	i = check(&flag, n, i);
	if (n == 0)
	{
		ptr = (char *) malloc (sizeof (char) * (2));
		if (ptr == NULL)
			return (NULL);
		ptr[0] = n + 48;
		ptr[1] = '\0';
		return (ptr);
	}
	ptr = (char *) malloc (sizeof (char) * (i + 1));
	if (ptr == NULL)
		return (NULL);
	ptr[i--] = '\0';
	return (complete(ptr, flag, n, i));
}
