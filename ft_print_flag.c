/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 03:02:21 by shinfray          #+#    #+#             */
/*   Updated: 2022/11/02 11:42:12 by shinfray         ###   ########.fr       */
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

char	ft_print_c(int c)
{
	unsigned char	u_c;

	u_c = (unsigned char)c;
	write(1, &u_c, 1);
	return (1);
}

int	ft_print_x(size_t x, const char flag)
{
	int	len;

	len = 0;
	if (flag == 'x')
		ft_putnbr_exa(x, "0123456789abcdef", &len);
	if (flag == 'X')
		ft_putnbr_exa(x, "0123456789ABCDEF", &len);
	return (len);
}

int	ft_print_u(unsigned int u)
{
	int	len;

	len = 0;
	ft_putnbr_decimal(u, &len);
	return (len);
}

int	ft_print_d_i(int num)
{
	char	*s;
	int		len;

	s = ft_itoa(num);
	len = ft_print_s(s);
	free(s);
	return (len);
}

int	ft_print_p(void *p)
{
	int	len;

	len = 2;
	ft_putstr_fd("0x", 1);
	ft_putnbr_exa((size_t)p, "0123456789abcdef", &len);
	return (len);
}
