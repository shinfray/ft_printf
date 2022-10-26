/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:29:18 by shinfray          #+#    #+#             */
/*   Updated: 2022/10/26 16:16:07 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_print_s(va_list ap)
{
	char	*s;

	s = va_arg(ap, char *);
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}


size_t	ft_print_c(va_list ap)
{
	char	*c;

	c = va_arg(ap, char);
	ft_putchar_fd(*c, 1);
	return (1);
}

size_t	ft_check_flag(const char *c, va_list ap)
{
	if (*c == 's')
		return (ft_print_s(ap));
	if (*c == 'c')
		return (ft_print_c(ap));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	const char	*ptr;
	size_t		count;

	count = 0;
	va_start(ap, format);
	ptr = format;
	while (*ptr != '\0')
	{
		if (*ptr != '%')
		{
			ft_putchar_fd(*ptr, 1);
			++count;
		}
		else if (*ptr == '%' && *(ptr + 1) == '%')
			ft_putchar_fd(*++ptr, 1);
		else
		{
			count = ft_check_flag(ptr + 1, ap);
			++ptr;
		}
		++ptr;
	}
	va_end(ap);
	return (0);
}
