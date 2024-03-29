/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariama3 <mariama3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:25:39 by mariama3          #+#    #+#             */
/*   Updated: 2024/03/28 02:33:22 by mariama3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_digit(int digit, int *sol)
{
	ft_putchar(digit + '0', sol);
}

static	void	print_integer_reverse(long long int n, int *sol)
{
	if (n != 0)
	{
		print_digit(n % 10, sol);
		print_integer_reverse(n / 10, sol);
	}
}

void	decimal(long long int n, int *sol)
{
	if (n < 0)
	{
		ft_putchar('-', sol);
		n *= -1;
	}
	if (n == 0)
	{
		print_digit(0, sol);
	}
	else
	{
		print_integer_reverse(n, sol);
	}
}

