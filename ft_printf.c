/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:29:18 by shinfray          #+#    #+#             */
/*   Updated: 2022/10/26 21:51:12 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_print_percent(void)
{
	write(1, "%", 1);
	return (1);
}

size_t	ft_print_s(char *s)
{
	if (s == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

char	ft_print_c(int c)
{
	unsigned char	u_c;

	u_c = (unsigned char)c;
	write(1, &u_c, 1);
	return (1);
}

size_t	ft_print_d_i(int num)
{
	char	*s;
	size_t	len;


	s = ft_itoa(num);
	len = ft_print_s(s);
	free(s);
	return (len);
}

size_t	ft_check_flag(const char flag, va_list *ap)
{
	if (flag == '%')
		return (ft_print_percent());
	if (flag == 's')
		return (ft_print_s(va_arg(*ap, char *)));
	if (flag == 'c')
		return (ft_print_c(va_arg(*ap, int)));
	if (flag == 'd' || flag == 'i')
		return (ft_print_d_i(va_arg(*ap, int)));
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
	return (0);
}
