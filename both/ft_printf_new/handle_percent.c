/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartyn- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 20:27:50 by jmartyn-          #+#    #+#             */
/*   Updated: 2019/09/29 21:00:57 by jmartyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_print_percent(t_struct *list, char c)
{
	int				len;

	len = 0;
	if (list->zero == '0')
		list->morezero = '0';
	if (list->minus != '-' && list->width > 1)
		while (((list->width)-- - 1))
			len += ft_print_char(list->morezero);
	len += ft_print_char(c);
	if (list->width > 1 && list->minus == '-')
		while ((list->width)-- - 1)
			len += ft_print_char(' ');
	return (len);
}
