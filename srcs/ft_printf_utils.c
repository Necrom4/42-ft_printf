/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:19:03 by dferreir          #+#    #+#             */
/*   Updated: 2022/10/31 10:07:51 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	first_specifier_pos(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strchr("cspdiuXx%", str[i]))
			return (i);
		i++;
	}
	return (-1);
}

void	parse_flags(const char *str, int end, struct s_flags *f)
{
	int	i;

	i = 0;
	f->hash = 0;
	f->plus = 0;
	f->space = 0;
	while (i < end && (str[i] == '+' || str[i] == ' ' || str[i] == '#'))
	{
		if (str[i] == '+')
			f->plus = 1;
		else if (str[i] == ' ')
			f->space = 1;
		else if (str[i] == '#')
			f->hash = 1;
		i++;
	}
}

static int	handle_signed(va_list *args, struct s_flags f)
{
	int	n;
	int	len;

	len = 0;
	n = va_arg(*args, int);
	if (n >= 0)
	{
		if (f.plus)
			len += write(1, "+", 1);
		else if (f.space)
			len += write(1, " ", 1);
	}
	len += ft_printnbr(n);
	return (len);
}

static int	handle_hex(va_list *args, struct s_flags f, char k)
{
	unsigned int	u;
	int				len;

	len = 0;
	u = va_arg(*args, unsigned int);
	if (f.hash && u != 0)
	{
		if (k == 'x')
			len += write(1, "0x", 2);
		else
			len += write(1, "0X", 2);
	}
	len += ft_printhex(u, k);
	return (len);
}

int	handle_conversion(va_list *args, char k, struct s_flags f)
{
	if (k == 'c')
		return (ft_printchar(va_arg(*args, int)));
	if (k == 's')
		return (ft_printstr(va_arg(*args, char *)));
	if (k == 'p')
		return (ft_printptr(va_arg(*args, unsigned long long)));
	if (k == 'd' || k == 'i')
		return (handle_signed(args, f));
	if (k == 'u')
		return (ft_printunbr(va_arg(*args, unsigned int)));
	if (k == 'x' || k == 'X')
		return (handle_hex(args, f, k));
	if (k == '%')
		return (write(1, "%", 1));
	return (0);
}
