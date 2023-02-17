/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaduel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:45:03 by hbaduel           #+#    #+#             */
/*   Updated: 2023/02/17 18:18:22 by hbaduel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

void	ft_putchar(char c, int *hmp);
void	ft_putstr(const char *s, int *hmp);
void	ft_putnbr(long n, int *hmp);
void	ft_putnbr_base(unsigned long long nb, int *hmp, char type);
int		ft_printf(const char *str, ...);

#endif
