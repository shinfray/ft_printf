/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 03:09:46 by shinfray          #+#    #+#             */
/*   Updated: 2022/11/05 16:58:07 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_exa(size_t n, const char *const base, int *const len)
{
	if (n > 15)
		ft_putnbr_exa(n / 16, base, len);
	ft_putchar_fd(base[n % 16], 1);
	(*len)++;
}

void	ft_putnbr_u_int(const unsigned int n, int *const len)
{
	if (n > 9)
		ft_putnbr_u_int(n / 10, len);
	ft_putchar_fd(n % 10 + '0', 1);
	(*len)++;
}
