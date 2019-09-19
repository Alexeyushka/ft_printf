/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartyn- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:39:19 by jmartyn-          #+#    #+#             */
/*   Updated: 2019/09/14 15:39:54 by jmartyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

struct	p ft_putnbr(int nb, struct p parsed)
{
	if (nb < 0)
	{
		nb = -nb;
	}
	if (nb >= 10)
	{
		parsed = ft_putnbr((nb / 10), parsed);
		parsed = ft_putnbr((nb % 10), parsed);
	}
	else
	{
		ft_putchar(nb + '0');
		parsed.ret++;
	}
	return (parsed);
}
