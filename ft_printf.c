/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:53:29 by rugoncal          #+#    #+#             */
/*   Updated: 2023/02/11 21:12:14 by rugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_arg(const char *fmt, va_list ap, int i)
{
	int	ret;

	ret = 0;
	if (fmt[i] == 'c')
		ret = ft_putchar(va_arg(ap, int));
	else if (fmt[i] == 's')
		ret = ft_putstr(va_arg(ap, char *));
	else if (fmt[i] == 'd' || fmt[i] == 'i')
		ret = ft_putnbr(va_arg(ap, int));
	else if (fmt[i] == 'u')
		ret = ft_putnbr_base(va_arg(ap, unsigned int));
	else if (fmt[i] == '%')
		ret = ft_putchar('%');
	else if (fmt[i] == 'x')
		ret = ft_put_hex(va_arg(ap, unsigned int), 'x');
	else if (fmt[i] == 'X')
		ret = ft_put_hex(va_arg(ap, unsigned int), 'X');
	else if (fmt[i] == 'p')
		ret = ft_put_ptr(va_arg(ap, unsigned long));
	return (ret);
}

int	ft_printf(const char *fmt, ...)
{
	va_list		ap;
	int			i;
	int			ret;

	i = 0;
	ret = 0;
	va_start (ap, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%')
			ret += ft_printf_arg(fmt, ap, ++i);
		else
			ret += ft_putchar(fmt[i]);
		i++;
	}
	va_end (ap);
	return (ret);
}
