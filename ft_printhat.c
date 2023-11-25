/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaduel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:49:23 by hbaduel           #+#    #+#             */
/*   Updated: 2023/02/17 18:17:10 by hbaduel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *hmp)
{
	write(1, &c, 1);
	*hmp += 1;
}

void	ft_putstr(const char *s, int *hmp)
{
	size_t	i;

	if (!s)
	{
		ft_putstr("(null)", hmp);
		return ;
	}
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i], hmp);
		i++;
	}
}

void	ft_putnbr(long nb, int *hmp)
{
	if (nb < 0)
	{
		ft_putchar('-', hmp);
		nb *= -1;
	}
	if (nb > 9)
		ft_putnbr(nb / 10, hmp);
	ft_putchar(nb % 10 + 48, hmp);
}
