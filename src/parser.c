/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrik <patrik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 19:56:42 by ptison            #+#    #+#             */
/*   Updated: 2025/06/10 10:27:56 by patrik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include "parser.h"

t_format parse_format(const char *format, int *i, va_list args)
{
    t_format fmt;
    (void)args; // Suppress unused parameter warning for now
    
    // Initialize all fields to 0/default values
    fmt.flag_minus = 0;
    fmt.flag_zero = 0;
    fmt.flag_dot = 0;
    fmt.flag_hash = 0;
    fmt.flag_space = 0;
    fmt.flag_plus = 0;
    fmt.width = 0;
    fmt.precision = -1;  // -1 means precision not specified
    fmt.type = 0;
    
    // For now, just parse the basic conversion character
    // TODO: Implement full flag parsing for bonus features
    
    // Skip any flags for now and just get the conversion character
    while (format[*i] && format[*i] != 'c' && format[*i] != 's' && 
           format[*i] != 'p' && format[*i] != 'd' && format[*i] != 'i' &&
           format[*i] != 'u' && format[*i] != 'x' && format[*i] != 'X' &&
           format[*i] != '%')
    {
        (*i)++;
    }
    
    // Get the conversion character
    if (format[*i])
    {
        fmt.type = format[*i];
        (*i)++;
    }
    
    return fmt;
}
