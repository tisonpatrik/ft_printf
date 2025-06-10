/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrik <patrik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 21:16:10 by ptison            #+#    #+#             */
/*   Updated: 2025/06/10 13:06:19 by patrik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "parser.h"
#include "libft.h"

int dispatch_conversion(t_format fmt, va_list args);

int ft_printf(const char* format, ...)
{
	int i = 0;
	int total = 0;
	va_list args;
	
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++; // Skip the '%'
			t_format fmt = parse_format(format, &i, args);
			total += dispatch_conversion(fmt, args);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			total++;
			i++;
		}
	}
	va_end(args);
	return total; // Return total characters printed
}
