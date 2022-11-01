# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 16:37:12 by shinfray          #+#    #+#              #
#    Updated: 2022/11/01 12:18:39 by shinfray         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= 	ft_printf.c \
				ft_print_flag.c \
				ft_printf_putnbr.c \
				libft/ft_itoa.c \
				libft/ft_putstr_fd.c \
				libft/ft_putchar_fd.c \
				libft/ft_strlen.c \
				libft/ft_calloc.c \
				libft/ft_memset.c

#B_SRCS		=	

OBJS		= ${SRCS:.c=.o}

#B_OBJS		= ${B_SRCS:.c=.o}

NAME		= libftprintf.a

CC			= @gcc

RM			= @rm -f

CFLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			@ar rcs ${NAME} ${OBJS}

all:		${NAME}

#bonus:		${OBJS} ${B_OBJS}
#			@ar rcs ${NAME} ${OBJS} ${B_OBJS}

clean:
			${RM} ${OBJS} #${B_OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus
