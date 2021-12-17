/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icaceres <icaceres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 20:11:49 by icaceres          #+#    #+#             */
/*   Updated: 2021/10/29 20:12:12 by icaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putstr_fd(char *s, int fd, int malloc)
{
	size_t	len;

	if (!s)
	{
		write (1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(s);
	write(fd, s, len);
	if (malloc)
		free (s);
	return (len);
}
