/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:29:18 by shinfray          #+#    #+#             */
/*   Updated: 2022/11/05 16:25:30 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	ft_print_percent(void)
{
	write(1, "%", 1);
	return (1);
}

static int	ft_print(const char **format)
{
	const char *const	ptr = *format;
	int					len;

	len = 0;
	while (**format != '%' && **format != '\0')
		(*format)++;
	len = write(1, ptr, *format - ptr);
	if (**format == '%')
		(*format)++;
	return (len);
}

static int	ft_check_flag(const char *format, va_list *ap)
{
	int	count;

	count = 0;
	while (*format != '\0')
	{
		count += ft_print(&format);
		if (*format == '%')
			count += ft_print_percent();
		else if (*format == 's')
			count += ft_print_s(va_arg(*ap, char *));
		else if (*format == 'c')
			count += ft_print_c(va_arg(*ap, int));
		else if (*format == 'd' || *format == 'i')
			count += ft_print_d_i(va_arg(*ap, int));
		else if (*format == 'u')
			count += ft_print_u(va_arg(*ap, unsigned int));
		else if (*format == 'p')
			count += ft_print_p(va_arg(*ap, void *));
		else if (*format == 'x' || *format == 'X')
			count += ft_print_x(va_arg(*ap, unsigned int), *format);
		else
			continue ;
		++format;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = ft_check_flag(format, &ap);
	va_end(ap);
	return (count);
}
