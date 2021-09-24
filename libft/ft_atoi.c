/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icaceres <icaceres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:35:20 by icaceres          #+#    #+#             */
/*   Updated: 2021/09/24 16:44:36 by icaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long	pick_num(const char *str, int i, int flag)
{
	unsigned long	num;
	unsigned long	mod;

	num = 0;
	mod = 1;
	if (str[i] == 45)
	{
		flag = 1;
		i++;
	}
	if (str[i] < 48 || str[i] > 57)
		return (num);
	while (str[i] > 47 && str[i] < 58 && str[i] != '\0')
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	if (num > 2147483648 && flag == 1)
		return (0);
	if (num > 2147483647 && flag == 0)
		return (-1);
	if (flag)
		num *= -1;
	return (num);
}

int	ft_atoi(const char *str)
{
	int						flag;
	size_t					i;
	unsigned long			num;

	flag = 0;
	i = 0;
	num = 0;
	while (str[i] != '\0' && (str[i] == '\t' || str[i] == 32
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r'
			|| str[i] == '\n' || str[i] == 43))
	{
		if (str[i] == 43)
		{
			i++;
			if (str[i] == 45)
				return (0);
			break ;
		}
		i++;
	}
	num = pick_num(str, i, flag);
	return (num);
}
