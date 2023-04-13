/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 17:02:20 by rugoncal          #+#    #+#             */
/*   Updated: 2023/02/15 21:58:15 by rugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hex(unsigned long long n, char *base)
{
	if (n < 16)
		ft_putchar(base[n]);
	else if (n >= 16)
	{
		ft_hex(n / 16, base);
		ft_hex(n % 16, base);
	}
	else
		ft_putchar(n + '0');
}

int	ft_put_hex(unsigned long long n, char fmt)
{
	char	*base_low_x;
	char	*base_up_x;
	int		len;

	base_low_x = "0123456789abcdef";
	base_up_x = "0123456789ABCDEF";
	len = 0;
	if (n == 0)
		len += write(1, "0", 1);
	else
	{
		if (fmt == 'x')
			ft_hex(n, base_low_x);
		if (fmt == 'X')
			ft_hex(n, base_up_x);
	}
	while (n)
	{
		n = n / 16;
		len++;
	}
	return (len);
}
