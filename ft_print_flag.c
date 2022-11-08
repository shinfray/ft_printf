/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 03:02:21 by shinfray          #+#    #+#             */
/*   Updated: 2022/11/08 11:15:39 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s(char *s)
{
	if (s == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

char	ft_print_c(const int c)
{
	const unsigned char	u_c = (const unsigned char)c;

	return (write(1, &u_c, 1));
}

int	ft_print_x(const size_t x, const char flag)
{
	int	len;

	len = 0;
	if (flag == 'x')
		ft_putnbr_exa(x, "0123456789abcdef", &len);
	if (flag == 'X')
		ft_putnbr_exa(x, "0123456789ABCDEF", &len);
	return (len);
}

int	ft_print_u(const unsigned int u)
{
	int	len;

	len = 0;
	ft_putnbr_uint(u, &len);
	return (len);
}

int	ft_print_d_i(const int num)
{
	char	*s;
	int		len;

	s = ft_itoa(num);
	len = ft_print_s(s);
	free(s);
	return (len);
}
