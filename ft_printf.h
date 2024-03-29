/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariama3 <mariama3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 17:15:05 by egomez-g          #+#    #+#             */
/*   Updated: 2024/03/29 20:59:18 by mariama3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(char const *input, ...);


void	decimal(long long int n, int *sol);
void	ft_putchar(char c, int *sol);
void	print_pointer(size_t address, int *sol);
void	print_hex_lowercase(unsigned long int number, int *sol);
void	print_hex_uppercase(unsigned long int number, int *sol);
void	print_str(const char *s, int *sol);
void	check_module(char c, va_list args, int *sol);

#endif
