/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:29:18 by shinfray          #+#    #+#             */
/*   Updated: 2022/10/27 03:10:29 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	ft_print_percent(void)
{
	write(1, "%", 1);
	return (1);
}

static size_t	ft_check_flag(const char flag, va_list *ap)
{
	if (flag == '%')
		return (ft_print_percent());
	if (flag == 's')
		return (ft_print_s(va_arg(*ap, char *)));
	if (flag == 'c')
		return (ft_print_c(va_arg(*ap, int)));
	if (flag == 'd' || flag == 'i')
		return (ft_print_d_i(va_arg(*ap, int)));
	if (flag == 'u')
		return (ft_print_u(va_arg(*ap, unsigned int)));
	if (flag == 'p')
		return (ft_print_p(va_arg(*ap, void *)));
	if (flag == 'x' || flag == 'X')
		return (ft_print_x(va_arg(*ap, unsigned int), flag));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
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
		else
		{
			count += ft_check_flag(*(ptr + 1), &ap);
			++ptr;
		}
		++ptr;
	}
	va_end(ap);
	return (count);
}
