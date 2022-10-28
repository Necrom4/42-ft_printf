/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:09:59 by dferreir          #+#    #+#             */
/*   Updated: 2022/10/28 16:11:17 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../Libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *str, ...);

int		ft_printchar(int c);

int		ft_printhex(unsigned int nbr, char type);

int		ft_printnbr(int	n);

int		ft_printunbr(unsigned int n);

int		ft_printptr(unsigned long ptr);

int		ft_printstr(char *str);

#endif
