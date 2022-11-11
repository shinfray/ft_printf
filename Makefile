# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 16:37:12 by shinfray          #+#    #+#              #
#    Updated: 2022/11/11 00:54:00 by shinfray         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= 	ft_printf.c \
				ft_printf_flags.c \
				ft_printf_hexa.c

LIBFT_PATH	=	libft/

DEP			=	libft.a

OBJS		= ${SRCS:.c=.o}

NAME		= libftprintf.a

CC			= @gcc

RM			= @rm -f

CFLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${DEP} ${OBJS}
			@ar rcs ${NAME} ${OBJS}

${DEP}:
			@make -C ${LIBFT_PATH}
			@mv libft/${DEP} ${NAME}

all:		${NAME}

clean:
			@make fclean -C ${LIBFT_PATH}
			${RM} ${OBJS}

fclean:		clean
			${RM} ${LIBFT_PATH}${DEP}
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
