# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: icaceres <icaceres@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/10 19:13:50 by icaceres          #+#    #+#              #
#    Updated: 2021/10/29 21:11:44 by icaceres         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
SRCS	= ft_printf.c ft_hexa.c ft_pointer.c ft_putstr.c ft_putchar.c ft_decimal.c ft_putchar.c
OBJS	= $(SRCS:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

all: $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS) 
clean:
			$(RM) $(OBJS)
			
fclean:		clean
	$(RM) $(NAME)
re:			fclean all
.PHONY:     bonus all clean fclean re
