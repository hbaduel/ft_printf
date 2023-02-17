/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaduel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:34:09 by hbaduel           #+#    #+#             */
/*   Updated: 2023/02/17 18:16:48 by hbaduel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_whichtype(char c, va_list args, int *hmp)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), hmp);
	if (c == 's')
		ft_putstr((const char *) va_arg(args, char *), hmp);
	if (c == 'p')
		ft_putnbr_base((unsigned long long) va_arg(args, void *), hmp, 'p');
	if (c == 'd' || c == 'i')
		ft_putnbr((long) va_arg(args, int), hmp);
	if (c == 'u')
		ft_putnbr((long) va_arg(args, unsigned int), hmp);
	if (c == 'x')
		ft_putnbr_base((unsigned long long) va_arg(args, unsigned int), \
		hmp, 'x');
	if (c == 'X')
		ft_putnbr_base((unsigned long long) va_arg(args, unsigned int), \
		hmp, 'X');
	if (c == '%')
		ft_putchar('%', hmp);
}

int	ft_printf(const char *str, ...)
{
	int		hmp;
	size_t	i;
	va_list	args;

	hmp = 0;
	if (!str)
		return (hmp);
	i = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		while (str[i] != '%' && str[i] != '\0')
		{
			ft_putchar(str[i], &hmp);
			i++;
		}
		if (str[i] == '%')
		{
			ft_whichtype(str[i + 1], args, &hmp);
			i += 2;
		}
	}
	va_end(args);
	return (hmp);
}
