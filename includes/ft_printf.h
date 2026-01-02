/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:09:59 by dferreir          #+#    #+#             */
/*   Updated: 2022/10/31 10:08:38 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../Libft/libft.h"
# include <stdarg.h>

struct s_flags
{
	int	hash;
	int	plus;
	int	space;
};

int		ft_printf(const char *str, ...);

int		ft_printchar(int c);

int		ft_printhex(unsigned int nbr, char type);

int		ft_printnbr(int n);

int		ft_printunbr(unsigned int n);

int		ft_printptr(unsigned long long ptr);

int		ft_printstr(char *str);

// utils.c

int		first_specifier_pos(const char *str);

int		handle_conversion(va_list *args, char k, struct s_flags f);

void	parse_flags(const char *str, int end, struct s_flags *f);

// ---

#endif
