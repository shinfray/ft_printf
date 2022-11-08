/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:20:25 by shinfray          #+#    #+#             */
/*   Updated: 2022/11/08 16:54:21 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_p(const void *const p)
{
	int	len;

	len = 2;
	ft_putstr_fd("0x", 1);
	ft_putnbr_hexa((size_t)p, "0123456789abcdef", &len);
	return (len);
}
