/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:31:26 by dferreir          #+#    #+#             */
/*   Updated: 2022/10/28 15:36:09 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../Libft/libft.h"

int		ft_printptr(unsigned long long ptr)
{
	int	len;
	char *address;
	

	len = 0;
	len += write (1, "0x", 2);
	ptr += 2;
	if (!ptr)
		len += write (1, "0", 1);
	else
	{
		address = ft_itoa(ptr);
		len += ft_printstr(address);
	}
	return (len);
}
