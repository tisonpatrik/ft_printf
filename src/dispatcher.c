/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrik <patrik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 19:58:46 by ptison            #+#    #+#             */
/*   Updated: 2025/06/10 10:25:29 by patrik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "parser.h"

// Function prototypes for handlers (to be implemented)
int handle_char(t_format fmt, va_list args);
int handle_string(t_format fmt, va_list args);
int handle_pointer(t_format fmt, va_list args);
int handle_decimal(t_format fmt, va_list args);
int handle_unsigned(t_format fmt, va_list args);
int handle_hex(t_format fmt, va_list args);
int handle_percent(t_format fmt);

int dispatch_conversion(t_format fmt, va_list args)
{
    if (fmt.type == 'c')
        return handle_char(fmt, args);
    else if (fmt.type == 's')
        return handle_string(fmt, args);
    else if (fmt.type == 'p')
        return handle_pointer(fmt, args);
    else if (fmt.type == 'd' || fmt.type == 'i')
        return handle_decimal(fmt, args);
    else if (fmt.type == 'u')
        return handle_unsigned(fmt, args);
    else if (fmt.type == 'x' || fmt.type == 'X')
        return handle_hex(fmt, args);
    else if (fmt.type == '%')
        return handle_percent(fmt);
    return 0;
}

