/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:12:01 by rugoncal          #+#    #+#             */
/*   Updated: 2023/02/20 22:15:13 by rugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = -1;
	if (s == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (s[++i])
		write(1, &s[i], 1);
	return (i);
}

int	ft_putnbr(int nb)
{
	int	ret;

	ret = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb < 0)
	{
		ret += ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
		ret += ft_putnbr(nb / 10);
	ret += ft_putchar(nb % 10 + 48);
	return (ret);
}

int	ft_put_ptr(unsigned long long nbr)
{
	int	ret;

	ret = 0;
	if (nbr == 0)
		ret += ft_putstr("(nil)");
	else
	{	
		ret += ft_putstr("0x");
		ret += ft_put_hex(nbr, 'x');
	}
	return (ret);
}

int	ft_putnbr_base(unsigned long nbr)
{
	int	ret;

	ret = 0;
	if (nbr > 9)
		ret += ft_putnbr_base(nbr / 10);
	ret += ft_putchar(nbr % 10 + 48);
	return (ret);
}
