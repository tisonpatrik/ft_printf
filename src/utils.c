/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrik <patrik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 19:49:37 by ptison            #+#    #+#             */
/*   Updated: 2025/06/10 12:58:40 by patrik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void ft_putnbr_unsigned(unsigned int n)
{
	if (n >= 10)
		ft_putnbr_unsigned(n / 10);
	ft_putchar_fd((n % 10) + '0', 1);
}

void ft_putnbr_hex(unsigned int n, int uppercase)
{
	char *hex_digits;
	
	if (uppercase)
		hex_digits = "0123456789ABCDEF";
	else
		hex_digits = "0123456789abcdef";
	
	if (n >= 16)
		ft_putnbr_hex(n / 16, uppercase);
	ft_putchar_fd(hex_digits[n % 16], 1);
}

void ft_putptr(void *ptr)
{
	unsigned long addr = (unsigned long)ptr;
	char *hex_digits = "0123456789abcdef";
	
	if (addr >= 16)
		ft_putptr((void *)(addr / 16));
	ft_putchar_fd(hex_digits[addr % 16], 1);
}
