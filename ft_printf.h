/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:24:21 by shinfray          #+#    #+#             */
/*   Updated: 2022/11/02 11:45:06 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

int		ft_printf(const char *format, ...);
int		ft_print_s(char *s);
char	ft_print_c(int c);
int		ft_print_x(size_t x, const char flag);
int		ft_print_u(unsigned int u);
int		ft_print_d_i(int num);
int		ft_print_p(void *p);
void	ft_putnbr_exa(size_t n, char *base, int *len);
void	ft_putnbr_decimal(unsigned int n, int *len);

#endif
