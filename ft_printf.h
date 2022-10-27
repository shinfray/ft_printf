/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:24:21 by shinfray          #+#    #+#             */
/*   Updated: 2022/10/27 03:16:19 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

int		ft_printf(const char *format, ...);
size_t	ft_print_s(char *s);
char	ft_print_c(int c);
size_t	ft_print_x(size_t x, const char flag);
size_t	ft_print_u(unsigned int u);
size_t	ft_print_d_i(int num);
size_t	ft_print_p(void *p);
void	ft_putnbr_exa(size_t n, char *base, size_t *len);
void	ft_putnbr_decimal(unsigned int n, size_t *len);

#endif
