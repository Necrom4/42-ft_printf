/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:23:53 by dferreir          #+#    #+#             */
/*   Updated: 2022/10/27 15:41:45 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printnbr(int	n)
{
	char	str[11];
	int		len;
	int 	i;

	i = 0;
	len = 1;
	if (n < 0)
	{
		len++;
		write (1, "-", 1);
		n *= 1;
	}
	while (n >= 10)
	{
		str[i++] = n % 10 + '0';
		n /= 10;
		len++;
	}
	while (i >= 0)
		write (1, &str[i--], 1);
	return (len);
}
