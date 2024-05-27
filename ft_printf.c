/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:12:54 by jingwu            #+#    #+#             */
/*   Updated: 2024/05/27 12:12:54 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int specifier(const char fmt)
{
	int char_printed;
	va_list arg;

	 char_printed= 0;
	if (fmt == 'c')
		char_printed = print_c(va_arg(arg, char));
	if (fmt == 's')
		char_printed = print_str(va_arg(arg, char *));
	if (fmt == 'p')
		char_printed = print_addrs(va_arg(arg, uintptr_t));
	if (fmt == 'd' || fmt == 'i')
		char_printed = print_nb(va_arg(arg, int));
	if (fmt == 'u')
		char_printed = print_unb(va_arg(arg, unsigned int));
	if (fmt == 'x' || fmt == 'X')
		char_printed = print_hexa(va_arg(arg, unsigned int), fmt);
	if (fmt == '%')
		char_printed += print_c(fmt);
	if (fmt == '\0')
		char_printed = 0;
	return (char_printed);
}

static int format(const char *fmt, va_list arg)
{
	int	char_printed;
	int	i;
	int re_value;

	i = 0;
	char_printed = 0;
	while (fmt[i])
	{
		while (fmt[i] != '%' && fmt[i])
		{
			if (print_c(fmt[i]) == -1)
				return (-1);
			char_printed += 1;
			i++;
		}
		if (fmt[i] == '%')
		{
			re_value = specifier(fmt[++i]);
			if (re_value == -1)
				return (-1);
			char_printed += re_value ;
			i++;
		}
	}
	return (char_printed);
}


int ft_printf(const char *fmt, ...)
{
	va_list arg;
	int char_printed;

	va_start(arg, fmt);
	if (!fmt || !*fmt)
		return (0);
	char_printed = 0;
	char_printed = format(fmt, arg);
	va_end(arg);
	return (char_printed);
}