# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssylvana <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/26 18:09:48 by ssylvana          #+#    #+#              #
#    Updated: 2021/01/26 18:15:52 by ssylvana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 		= ft_printf.c parser.c make_s.c make_c.c make_d.c make_u.c make_x.c make_p.c

NAME 		= libftprintf.a

OBJS 		= ${SRCS:.c=.o}

CC 		= gcc

FLAGS		= -Wall -Wextra -Werror

INCS 		= ft_printf.h

RM 		= rm -f

.c-.o:
			$(CC) $(FLAGS) -c $< -o ${<:.c=.o} -I$(INCS)

$(NAME): 	$(OBJS)
			make -C libft/
			cp libft/libft.a ./$(NAME)
			ar -rc $(NAME) $(OBJS)
			ranlib $(NAME)

all: 		$(NAME)

$(NAME): 	$(OBJS) $(INCS)

clean:
			make clean -C libft/
			$(RM) $(OBJS)

fclean: 	clean
			make fclean -C libft/
			$(RM) $(NAME)

re: 		fclean all
