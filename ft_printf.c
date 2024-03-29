/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariama3 <mariama3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:34:28 by mariama3          #+#    #+#             */
/*   Updated: 2024/03/29 21:15:41 by mariama3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
# include <stdio.h>


void	ft_putchar(char c, int *sol)
{
	write(1, &c, 1);
	(*sol)++;
}

void	print_str(const char *s, int *sol)
{
	if (!s)
	{
		write(1, "(null)", 6);
		*sol += 6;
		return ;
	}
	while (*s)
	{
		ft_putchar(*s, sol);
		s++;
	}
}

void	check_module(char c, va_list args, int *sol)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), sol);
	else if (c == 's')
		print_str(va_arg(args, char *), sol);
	else if (c == 'p')
		print_pointer(va_arg(args, size_t), sol);
	else if (c == 'd' || c == 'i')
		decimal(va_arg(args, int), sol);
	else if (c == 'u')
		decimal(va_arg(args, unsigned int), sol);
	else if (c == 'x')
		print_hex_lowercase(va_arg(args, unsigned int), sol);
	else if (c == 'X')
		print_hex_uppercase(va_arg(args, unsigned int), sol);
	else if (c == '%')
		ft_putchar('%', sol);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		sol;

	va_start(args, format);
	sol = 0;
	while (*format)
	{
		if (*format == '%')
			check_module(*format, args, &sol);
		else
			ft_putchar(*format, &sol);
		format++;
	}
	va_end(args);
	return (sol);
}

/*int main(void)
{
	printf("OR %u\n", 654654654);
	ft_printf("MIO %u\n", 654654654);
	return (0);
}*/




