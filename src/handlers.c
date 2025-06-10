/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrik <patrik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 10:24:00 by patrik            #+#    #+#             */
/*   Updated: 2025/06/10 12:56:50 by patrik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
#include "parser.h"

void ft_putnbr_unsigned(unsigned int n);
void ft_putnbr_hex(unsigned int n, int uppercase);
void ft_putptr(void *ptr);

// Basic implementations - TODO: Add bonus flag handling

int handle_char(t_format fmt, va_list args)
{
    (void)fmt; // Suppress unused parameter warning
    char c = va_arg(args, int);  // char is promoted to int in va_arg
    ft_putchar_fd(c, 1);
    return 1;
}

int handle_string(t_format fmt, va_list args)
{
    (void)fmt; // Suppress unused parameter warning
    char *s = va_arg(args, char*);
    int count = 0;
    
    if (s == NULL)
        s = "(null)";
    
    count = ft_strlen(s);
    ft_putstr_fd(s, 1);
    return count;
}

int handle_pointer(t_format fmt, va_list args)
{
    (void)fmt; // Suppress unused parameter warning
    void *ptr = va_arg(args, void*);
    
    if (ptr == NULL)
    {
        ft_putstr_fd("(nil)", 1);
        return 5;
    }
    
    ft_putstr_fd("0x", 1);
    ft_putptr(ptr);
    return 2 + 16; // "0x" + hex digits (assuming 64-bit)
}

int handle_decimal(t_format fmt, va_list args)
{
    (void)fmt; // Suppress unused parameter warning
    int n = va_arg(args, int);
    int count = 0;
    int temp = n;
    
    if (n < 0)
        count = 1; // for the minus sign
    
    if (n == 0)
        count = 1;
    else
    {
        if (n < 0)
            temp = -n;
        while (temp > 0)
        {
            temp /= 10;
            count++;
        }
    }
    
    ft_putnbr_fd(n, 1);
    return count;
}

int handle_unsigned(t_format fmt, va_list args)
{
    (void)fmt; // Suppress unused parameter warning
    unsigned int n = va_arg(args, unsigned int);
    int count = 0;
    unsigned int temp = n;
    
    if (n == 0)
        count = 1;
    else
    {
        while (temp > 0)
        {
            temp /= 10;
            count++;
        }
    }
    
    ft_putnbr_unsigned(n);
    return count;
}

int handle_hex(t_format fmt, va_list args)
{
    unsigned int n = va_arg(args, unsigned int);
    int count = 0;
    unsigned int temp = n;
    
    if (n == 0)
        count = 1;
    else
    {
        while (temp > 0)
        {
            temp /= 16;
            count++;
        }
    }
    
    ft_putnbr_hex(n, (fmt.type == 'X'));
    return count;
}

int handle_percent(t_format fmt)
{
    (void)fmt; // Suppress unused parameter warning
    ft_putchar_fd('%', 1);
    return 1;
} 