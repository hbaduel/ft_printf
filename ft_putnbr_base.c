/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaduel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:19:05 by hbaduel           #+#    #+#             */
/*   Updated: 2023/02/17 18:21:56 by hbaduel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned long long nb, int *hmp, char type)
{
	if (type == 'p')
	{
		if (nb == 0)
		{
			ft_putstr("(nil)", hmp);
			return ;
		}
		ft_putstr("0x", hmp);
		type = 'x';
	}
	if (type == 'x')
	{
		if (nb >= 16)
			ft_putnbr_base((nb / 16), hmp, type);
		ft_putchar("0123456789abcdef"[nb % 16], hmp);
	}
	if (type == 'X')
	{
		if (nb >= 16)
			ft_putnbr_base((nb / 16), hmp, type);
		ft_putchar("0123456789ABCDEF"[nb % 16], hmp);
	}
}
