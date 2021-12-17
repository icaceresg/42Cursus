/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icaceres <icaceres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:24:55 by icaceres          #+#    #+#             */
/*   Updated: 2021/12/17 19:43:24 by icaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 25

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s [len] != '\0')
		len++;
	return (len);
}

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

char	*ft_line(char *str)
{
	int		i;
	int		j;
	char	*sol;

	j = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			sol = malloc ((i + 2) * sizeof(char));
			if (sol == '\0')
				return (NULL);
			sol[i + 1] = '\0';
			while (j <= i)
			{
				sol[j] = str[j];
				j++;
			}
			return (sol);
		}
		i++;
	}
	return (NULL);
}

char	*ft_clean(char *str, char *content)
{
	int		i;
	char	*aux;
	char	*sub_content;
	int		j;

	i = 0;
	j = 0;
	if (str == NULL)
		return (content);
	while (content[i] != '\0' && str[i] != '\0' && content [i] == str[i])
		i++;
	aux = malloc ((ft_strlen(content) - (i + 1)) * sizeof(char));
	if (aux == '\0')
		return (NULL);
	while (content[i] != '\0')
	{
		aux[j] = content[i];
		i++;
		j++;
	}
	aux[j] = '\0';
	free(content);
	sub_content = malloc ((ft_strlen(aux) + 1) * sizeof(char));
	if (sub_content == '\0')
		return (NULL);
	sub_content = ft_strjoin(sub_content, aux);
	free(aux);
	return (sub_content);
}

int	ft_new_line (char *str)
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

char	*get_next_line(int fd)
{
	static char	*content;
	int			bytes;
	char		*str;

	str = malloc ((BUFFER_SIZE + 1) * sizeof (char));
	content = malloc ((BUFFER_SIZE + 1) * sizeof (char));
	if (str == '\0' || content == '\0')
		return (NULL);
	while (!ft_new_line(content))
	{
		bytes = read(fd, str, BUFFER_SIZE);
		if (bytes <= 0)
			break;
		str[bytes] = '\0';
		content = ft_strjoin (content, str); // Mete en contetn todo str
	}
	free(str);
	str = ft_line (content);
	content = ft_clean (str, content);
	printf("%s", str);
	return (str);
}

int main ()
{
	int		fd;
	char	*line;
	int	num = 1;

	fd = open("file.txt", O_RDONLY);
	line = get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	/*
	while (line)
	{
		printf("%i- %s", num, line);
		free(line);
		line = get_next_line(fd);
		num++;
	}*/
	//get_next_line("hola\nadios\npepe");
}
