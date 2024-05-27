/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:19:25 by jingwu            #+#    #+#             */
/*   Updated: 2024/05/27 12:19:25 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int print_nb(int nb)
{
	int char_pt;

	char_pt = 0;
	if (nb == -2147483648)
		return (print_str('-2147483648'));
	if (nb < 0)
	{
		char_pt = put_c('-');
		nb *= -1;
	}
	if (nb > 9)
		print_nb(nb / 10);
	print_c(nb % 10 + '0');
	char_pt += 1;
	return (char_pt);
}

int print_unb(unsigned int unb)
{
	int	num;

	num = (int)unb;
	return (print_nb(num));
}

int	print_hexa(unsigned int nb, char fmt)
{
	int				char_pt;
	unsigned int	number;
	int				base;
	unsigned int	num_base;


	char_pt = 0;
	num_base = 16;
	base = 1;
	if (fmt == 'x')
	{
		while (nb)
		{
			if (nb % num_base < 10)
			number += nb % num_base * base;
			nb /= num_base;
			base *= 10;
		}
	}
	if (fmt == 'X')
	{

	}
	return (char_pt);
}