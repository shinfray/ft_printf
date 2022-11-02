# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 16:37:12 by shinfray          #+#    #+#              #
#    Updated: 2022/11/02 16:21:34 by shinfray         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= 	ft_printf.c \
				ft_print_flag.c \
				ft_print_p.c \
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

#LIBFT_PATH	= libft/

#DEP			= libft.a

CC			= @gcc

RM			= @rm -f

CFLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			@ar rcs ${NAME} ${OBJS}

#${DEP}:
#			@make -C ${LIBFT_PATH}
#			mv libft/${DEP} ${NAME}

all:		${NAME}

#bonus:		${OBJS} ${B_OBJS}
#			@ar rcs ${NAME} ${OBJS} ${B_OBJS}

clean:
#			@make fclean -C ${LIBFT_PATH}
			${RM} ${OBJS} #${B_OBJS}

fclean:		clean
#			${RM} ${LIBFT_PATH}${DEP}
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus
