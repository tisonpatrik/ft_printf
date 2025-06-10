/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrik <patrik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 19:49:37 by ptison            #+#    #+#             */
/*   Updated: 2025/06/10 12:47:51 by patrik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putstr(char *s)
{
	if (!s)
		return;
	while (*s)
	{
		ft_putchar(*s);
		s++;
	}
}

void ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}

void ft_putnbr_unsigned(unsigned int n)
{
	if (n >= 10)
		ft_putnbr_unsigned(n / 10);
	ft_putchar((n % 10) + '0');
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
	ft_putchar(hex_digits[n % 16]);
}

void ft_putptr(void *ptr)
{
	unsigned long addr = (unsigned long)ptr;
	char *hex_digits = "0123456789abcdef";
	
	if (addr >= 16)
		ft_putptr((void *)(addr / 16));
	ft_putchar(hex_digits[addr % 16]);
}
