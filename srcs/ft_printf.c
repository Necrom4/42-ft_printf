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

int	format(va_list *args, const char *str)
{
	int				end;
	struct s_flags	flags;

	end = first_specifier_pos(str);
	if (end < 0)
		return (0);
	parse_flags(str, end, &flags);
	return (handle_conversion(args, str[end], flags));
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;
	int		consumed;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			consumed = first_specifier_pos(&str[i + 1]);
			if (consumed >= 0)
			{
				len += format(&args, &str[i + 1]);
				i += consumed + 1;
			}
		}
		else
			len += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}

/*int main()
{
	char str[] = "Hello";
	int nbr = -42;

	printf("%s and %d", str, nbr);
	return (0);
}*/
