/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:41:45 by rugoncal          #+#    #+#             */
/*   Updated: 2023/02/21 13:23:13 by rugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *fmt, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int nb);
int		ft_put_hex(unsigned long long n, char fmt);
int		ft_putnbr_base(unsigned long nbr);
int		ft_put_ptr(unsigned long long nbr);
int		ft_printf_arg(const char *fmt, va_list ap, int i);
void	ft_hex(unsigned long long n, char *base);

#endif
