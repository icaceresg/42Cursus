/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icaceres <icaceres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:24:55 by icaceres          #+#    #+#             */
/*   Updated: 2022/02/12 18:32:17 by icaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_clean2(char *content, int i, int j)
{
	char	*aux;

	aux = malloc ((ft_strlen(content) - (i - 1)) * sizeof(char));
	if (aux == NULL)
	{
		free(content);
		return (NULL);
	}
	while (content[i] != '\0')
	{
		aux[j] = content[i];
		i++;
		j++;
	}
	aux[j] = '\0';
	free(content);
	return (aux);
}

char	*ft_clean(char *str, char *content)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (content == NULL || str == NULL)
	{
		free(str);
		free(content);
		return (NULL);
	}
	if (ft_new_line(content) == 1)
	{
		while ((str[i] != '\0' && content [i] == str[i]))
			i++;
		return (ft_clean2(content, i, j));
	}
	free(content);
	return (NULL);
}

int	ft_new_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_managment(char **str, char **content)
{
	*str = malloc ((BUFFER_SIZE + 1) * sizeof (char));
	if (*str == NULL)
	{
		if (*content != NULL)
			free(*content);
		return (0);
	}
	if (*content == NULL)
	{
		*content = malloc ((BUFFER_SIZE + 1) * sizeof (char));
		if (*content == NULL)
		{
			free(*str);
			return (0);
		}
		**content = '\0';
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*content;
	int			bytes;
	char		*str;

	if (!ft_managment(&str, &content))
		return (NULL);
	while (!ft_new_line(content))
	{
		bytes = read(fd, str, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		str[bytes] = '\0';
		content = ft_strjoin (content, str);
	}
	if (str != NULL && content != NULL)
	{
		free(str);
		str = ft_line (content);
		content = ft_clean (str, content);
		return (str);
	}
	if (str != NULL)
		free(str);
	free(content);
	return (NULL);
}
