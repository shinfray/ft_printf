/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:29:18 by shinfray          #+#    #+#             */
/*   Updated: 2022/11/01 15:27:53 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	ft_print_percent(void)
{
	write(1, "%", 1);
	return (1);
}

static char	ft_print_normal_char(const char *c)
{
	ft_putchar_fd(*c, 1);
	return (1);
}

static size_t	ft_check_flag(const char *format, va_list *ap)
{
	va_list	ap_cpy;
	size_t	count;

	va_copy(ap_cpy, *ap);
	count = 0;
	while (*format != '\0')
	{
		if (*format != '%')
			count += ft_print_normal_char(*format);
		else
		{
			if (format[1] == '%')
				count += ft_print_percent();
			else if (format[1] == 's')
				count += ft_print_s(va_arg(ap_cpy, char *));
			else if (format[1] == 'c')
				count += ft_print_c(va_arg(ap_cpy, int));
			else if (format[1] == 'd' || format[1] == 'i')
				count += ft_print_d_i(va_arg(ap_cpy, int));
			else if (format[1] == 'u')
				count += ft_print_u(va_arg(ap_cpy, unsigned int));
			else if (format[1] == 'p')
				count += ft_print_p(va_arg(ap_cpy, void *));
			else if (format[1] == 'x' || format[1] == 'X')
				count += ft_print_x(va_arg(ap_cpy, unsigned int), format[1]);
			++format;
		}
		++format;
	}
	va_end(ap_cpy);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	count;

	va_start(ap, format);
	count = ft_check_flag(format, &ap);
	va_end(ap);
	return (count);
}
