/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:12:10 by jingwu            #+#    #+#             */
/*   Updated: 2024/05/28 14:42:35 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// For the wrtie function, on failure, 'write' returns '-1' and sets 'errno' to
// indicate the error
#include <stdio.h>
int print_c(int c)
{
	if ((write(1, &c, 1) != 1))
		return (-1);
	return (1);
}

int print_str(char *str)
{
	int i;

	if (!str)
	{
		if ((write(1, "(null)", 6) != 6))
			return(-1);
		return (6);
	}
	i = 0;
	while (str[i])
	{
		if (print_c(str[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}
// argument tag is for deciding if output '0x' or not
int print_addrs(uintptr_t addr, int tag, int char_pt)
{
	char		*base_bank;

	if (tag == 0)
	{
		if (write(1, "0x", 2) != 2)
			return (-1);
		char_pt = 2;
		tag = 1;
	}
	base_bank = "0123456789abcdef";
	if (addr >= 16)
	{
		if (print_addrs(addr / 16, tag, char_pt) == -1)
			return (-1);
	}
	if (print_c(base_bank[addr % 16]) == -1)
		return (-1);
	char_pt++;
	return (char_pt);
}
// define char_pt as static, so the value won't be lost after the function be called.
int print_num(long nb, int base, int sign, int char_pt)
{
	char		*base_bank;

	if (sign == 0)
		base_bank = "0123456789abcdef";
	else
		base_bank = "0123456789ABCDEF";
	if (nb < 0)
	{
		if( print_c('-') == -1)
			return (-1);
		char_pt++;
		printf("\nnum_char_pt=%d\n", char_pt);
		nb *= -1;
	}
	if (nb >= base)
	{
		if (print_num(nb / base, base, sign, char_pt) == -1)
			return (-1);
	}
	if (print_c(base_bank[nb % base]) == -1)
		return (-1);
	char_pt++;
//	printf("\nnum_char_pt=%d\n", char_pt);
	return (char_pt);
}
