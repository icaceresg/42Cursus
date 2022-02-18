/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icaceres <icaceres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:26:25 by icaceres          #+#    #+#             */
/*   Updated: 2022/02/17 16:50:54 by icaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char		*get_next_line(int fd);
char		*ft_clean2(char *content, int i, int j);
char		*ft_clean(char *str, char *content);
char		*ft_line(char *str);
char		*ft_clone(int i, int aux, char *str);
char		*ft_strjoin(char *s1, char const *s2);
size_t		ft_strlen(const char *s);
int			ft_managment(char **str, char **content);
int			ft_new_line(char *str);

#endif