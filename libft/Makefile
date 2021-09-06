# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssylvana <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/23 14:32:59 by ssylvana          #+#    #+#              #
#    Updated: 2021/01/26 18:15:56 by ssylvana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 		ft_putchar.c ft_strcpy.c ft_memset.c ft_strlen.c ft_atoi.c ft_strncmp.c ft_memcmp.c ft_strnstr.c ft_strchr.c ft_strrchr.c ft_strlcat.c ft_strlcpy.c ft_memcpy.c ft_memchr.c ft_bzero.c ft_memccpy.c ft_memmove.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c ft_split.c ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strmapi.c ft_strjoin.c ft_strtrim.c

OBJS    	= $(SRCS:.c=.o)

NAME = 		libft.a

CC      	= gcc

RM      	= rm -f

FLAGS   	= -Wall -Wextra -Werror

%.c.o:
			$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME): 	$(OBJS)
			ar rc $(NAME) $(OBJS)

all:    	$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:
			all  clean  fclean  re
