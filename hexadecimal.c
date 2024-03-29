/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariama3 <mariama3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 02:34:16 by mariama3          #+#    #+#             */
/*   Updated: 2024/03/28 02:40:49 by mariama3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_hex_digit(unsigned long int digit, int *sol, char *hex_digits)
{
	ft_putchar(hex_digits[digit], sol);
}

static void	print_hex_recursive(unsigned long int n, int *sol, char *hex_digits)
{
	if (n > 0)
	{
		print_hex_recursive(n / 16, sol, hex_digits);
		print_hex_digit(n % 16, sol, hex_digits);
	}
}

void	print_pointer(size_t address, int *sol)
{
	write(1, "0x", 2);
	*sol += 2;
	if (address == 0)
	{
		ft_putchar('0', sol);
	}
	else
	{
		print_hex_recursive(address, sol, "0123456789abcdef");
	}
}

void	print_hex_lowercase(unsigned long int number, int *sol)
{
	if (number == 0)
	{
		ft_putchar('0', sol);
	}
	else
	{
		print_hex_recursive(number, sol, "0123456789abcdef");
	}
}

void	print_hex_uppercase(unsigned long int number, int *sol)
{
	if (number == 0)
	{
		ft_putchar('0', sol);
	}
	else
	{
		print_hex_recursive(number, sol, "0123456789ABCDEF");
	}
}
