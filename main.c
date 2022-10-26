/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:03:56 by shinfray          #+#    #+#             */
/*   Updated: 2022/10/26 16:13:51 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	main(void)
{
	char	s[] = "comment";
	char	s2[] = "hello";
	char	c = 't';

	ft_printf("coucou %s ca %s, %cva", s, s2, c);
	return (0);
}
